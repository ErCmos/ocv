#ifndef OCV_H
#define OCV_H

#include <opencv2/opencv.hpp>
#include <string.h>

//! Clase para encapsular OpenCV

/*!
 * \file ocv.h
 * \brief The OCV class Clase para encapsular OpenCV en sus métodos más empleados
 * \author ErCmos
 */
class OCV
{
public:
    OCV();
    ~OCV();
    cv::VideoCapture OpenVideoFile(std::string dirName, std::string fileName);
    cv::VideoCapture OpenVideoFile(std::string fileName);
    cv::VideoCapture OpenVideoFile(int device);
};

#endif // OCV_H
