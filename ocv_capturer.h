#ifndef OCV_CAPTURER_H
#define OCV_CAPTURER_H

#include <opencv2/opencv.hpp>
#include <string.h>

//! Clase para encapsular OpenCV

/*!
 * \file ocv_capturer.h
 * \brief Clase para encapsular la captura con OpenCV en sus métodos más empleados
 * \author ErCmos
 */
class OCV_Capturer
{
public:
    OCV_Capturer();
    ~OCV_Capturer();

    //////////////////// CAPTURA //////////////////////////////////////////////
    cv::VideoCapture OpenVideoFile(std::string dirName, std::string fileName);
    cv::VideoCapture OpenVideoFile(std::string fileName);
    cv::VideoCapture OpenVideoFile(int device);
    //////////////////// FIN CAPTURA //////////////////////////////////////////
};

#endif // OCV_CAPTURER_H
