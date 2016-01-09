#include "clasificador_svm.h"

Clasificador_SVM::Clasificador_SVM()
{

}

Clasificador_SVM::~Clasificador_SVM()
{

}

using namespace cv;
using namespace std;
using namespace cv::ml;

void Clasificador_SVM::trainSVM(map<string,Mat>& classes_training_data, string& file_postfix, int response_cols, int response_type) {

    //train 1-vs-all SVMs
    vector<string> classes_names;
    for (map<string,Mat>::iterator it = classes_training_data.begin(); it != classes_training_data.end(); ++it) {
        classes_names.push_back((*it).first);
    }

    string use_postfix = file_postfix;
    #pragma omp parallel for schedule(dynamic) private(use_postfix)
    for (int i=0;i<classes_names.size();i++) {
        string class_ = classes_names[i];
        cout << omp_get_thread_num() << " training class: " << class_ << ".." << endl;

        Mat samples(0,response_cols,response_type);
        Mat labels(0,1,CV_32FC1);

        //copy class samples and label
        cout << "adding " << classes_training_data[class_].rows << " positive" << endl;
        samples.push_back(classes_training_data[class_]);
        Mat class_label = Mat::ones(classes_training_data[class_].rows, 1, CV_32FC1);
        labels.push_back(class_label);

        //copy rest samples and label
        for (map<string,Mat>::iterator it1 = classes_training_data.begin(); it1 != classes_training_data.end(); ++it1) {
            string not_class_ = (*it1).first;
            if(not_class_.compare(class_)==0) continue;
            samples.push_back(classes_training_data[not_class_]);
            class_label = Mat::zeros(classes_training_data[not_class_].rows, 1, CV_32FC1);
            labels.push_back(class_label);
        }

        cout << "Train.." << endl;
        Mat samples_32f; samples.convertTo(samples_32f, CV_32F);
        if(samples.rows == 0) continue; //phantom class?!

        Ptr<SVM> svm = SVM::create();

        Ptr<SVM> clasificador = SVM::create();

        clasificador->train(samples_32f,labels);

        //CvSVM classifier;
        //classifier.train(samples_32f,labels);

        {
            stringstream ss;
            ss << "SVM_classifier_";
            if(file_postfix.size() > 0) ss << file_postfix << "_";
            ss << class_ << ".yml";
            cout << "Save.." << endl;
            //classifier.save(ss.str().c_str());
            clasificador->save(ss.str().c_str());
        }
    }
}
