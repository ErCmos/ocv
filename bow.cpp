#include "bow.h"

using namespace cv;
using namespace std;
using namespace cv::xfeatures2d;

BoW::BoW()
{

}

BoW::~BoW()
{

}

//////////////// CrearDiccionario ///////////////////
void BoW::CrearDiccionario(std::string dirName)
{
    //Step 1 - Obtain the set of bags of features.

    //to store the input file names
    //char * filename = new char[100];
    //to store the current input image
    Mat input;

    //To store the keypoints that will be extracted by SIFT
    vector<KeyPoint> keypoints;
    //To store the SIFT descriptor of current image
    Mat descriptor;
    //To store all the descriptors that are extracted from all the images.
    Mat featuresUnclustered;
    //The SIFT feature extractor and descriptor
    //SiftDescriptorExtractor detector;
    Ptr<SIFT> detector = SIFT::create();

    //QString directorio = QString::fromStdString(dirName);
    //QDir dir(directorio);
    QDir dir(QString::fromStdString(dirName));
    //QMessageBox msgBox;
    foreach(QFileInfo item, dir.entryInfoList() )
        {
            if(item.isFile())
            {
               // msgBox.setText(item.absoluteFilePath());
               // msgBox.exec();
               //create the file name of an image
               //sprintf(filename,"G:\\testimages\\image\\%i.jpg",f);
               //open the file
               input = imread(item.absoluteFilePath().toStdString(), CV_LOAD_IMAGE_GRAYSCALE); //Load as grayscale
               //detect feature points
               //detector.detect(input, keypoints);
               detector->detect( input, keypoints );
               //compute the descriptors for each keypoint
               //detector.compute(input, keypoints,descriptor);
               detector->compute(input, keypoints,descriptor);
               //put the all feature descriptors in a single Mat object
               featuresUnclustered.push_back(descriptor);
               //print the percentage
               //printf("%i percent done\n",f/10);
            }
        }
    //Construct BOWKMeansTrainer
    //the number of bags
    int dictionarySize=200;
    //define Term Criteria
    TermCriteria tc(CV_TERMCRIT_ITER,100,0.001);
    //retries number
    int retries=1;
    //necessary flags
    int flags=KMEANS_PP_CENTERS;
    //Create the BoW (or BoF) trainer
    BOWKMeansTrainer bowTrainer(dictionarySize,tc,retries,flags);
    //cluster the feature vectors
    Mat dictionary=bowTrainer.cluster(featuresUnclustered);
    //store the vocabulary
    //FileStorage fs("diccionario.yml", FileStorage::WRITE);
    FileStorage fs(dirName+"/diccionario.yml", FileStorage::WRITE);
    fs << "vocabulary" << dictionary;
    fs.release();
}
////////////////////////////////////////////////


//////////////// TageadorDiccionario ///////////////////
void BoW::TageadorDiccionario(std::string dirName, std::string fileName)
{
    //Step 2 - Obtain the BoF descriptor for given image/video frame.

    //prepare BOW descriptor extractor from the dictionary
/*
    /////defining terms for bowkmeans trainer/////////////////////////////////////////
    int MAX_ITER = 15;
    int EPS = 2;
    TermCriteria tc(MAX_ITER + EPS, 10, 0.001);
    int dictionarySize = 1000;
    int retries = 1;
    int flags = KMEANS_PP_CENTERS;
    BOWKMeansTrainer bowTrainer(dictionarySize, tc, retries, flags);
    Mat dictionary = bowTrainer.cluster();
//    bowDE.setVocabulary(dictionary);
///////////////////////////////////////////////////////////////////////////////////
*/
    Mat dictionary;
    FileStorage fs(dirName+"/diccionario.yml", FileStorage::READ);
    fs["vocabulary"] >> dictionary;
    fs.release();

    //create a nearest neighbor matcher Fast Library for Approximate Nearest Neighbors (FLANN)
    //Ptr<DescriptorMatcher> matcher(new FlannBasedMatcher);

    Ptr<DescriptorMatcher> matcher = DescriptorMatcher::create("FlannBased");

    //create Sift feature point extracter
    //Ptr<FeatureDetector> detector(new SiftFeatureDetector());
    Ptr<FeatureDetector> detector = SiftFeatureDetector::create();
    //Ptr<SIFT> detector = SIFT::create();
    //create Sift descriptor extractor
    //Ptr<DescriptorExtractor> extractor(new SiftDescriptorExtractor);
    Ptr<DescriptorExtractor> extractor = SiftDescriptorExtractor::create();

    //create BoF (or BoW) descriptor extractor
    BOWImgDescriptorExtractor bowDE(extractor,matcher); //extractor es la imagen matcher es el vocabulario

    //Set the dictionary with the vocabulary we created in the first step
    bowDE.setVocabulary(dictionary);

    //To store the image file name
    //char * filename = new char[100];
    //To store the image tag name - only for save the descriptor in a file
    char * imageTag = new char[10];

    //open the file to write the resultant descriptor
    FileStorage fs1(dirName+"/diccionario_2.yml", FileStorage::WRITE);

    //the image file with the location. change it according to your image file location
    //sprintf(filename,"G:\\testimages\\image\\1.jpg");
    //read the image
    Mat img=imread(dirName+"/"+fileName,CV_LOAD_IMAGE_GRAYSCALE);
    //To store the keypoints that will be extracted by SIFT
    vector<KeyPoint> keypoints;
    //Detect SIFT keypoints (or feature points)
    detector->detect(img,keypoints);
    //To store the BoW (or BoF) representation of the image
    Mat bowDescriptor;
    //extract BoW (or BoF) descriptor from given image
    bowDE.compute(img,keypoints,bowDescriptor);

    //prepare the yml (some what similar to xml) file
    sprintf(imageTag,"img1");
    //write the new BoF descriptor to the file
    fs1 << imageTag << bowDescriptor;

    //You may use this descriptor for classifying the image.

    //release the file storage
    fs1.release();
}
/////////////////////////////////////////////////////

