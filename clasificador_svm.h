#ifndef CLASIFICADOR_SVM_H
#define CLASIFICADOR_SVM_H

// OpenCV stuff
#include <stdio.h>
#include <stdlib.h>

#include <opencv2/opencv.hpp>
#include <fstream>
#include <iostream>
#include <string>

#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#include <omp.h>
//#include <opencv2/core.hpp>
//#include <opencv2/highgui.hpp>
#include <opencv2/ml.hpp>

class Clasificador_SVM
{
public:
    Clasificador_SVM();
    ~Clasificador_SVM();
    void trainSVM(std::map<std::string,cv::Mat>& classes_training_data, std::string& file_postfix, int response_cols, int response_type);
};

#endif // CLASIFICADOR_SVM_H
