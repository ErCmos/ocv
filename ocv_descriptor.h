#ifndef OCV_DESCRIPTOR_H
#define OCV_DESCRIPTOR_H

/*!
 * \file ocv_descriptor.h
 * \brief Clase para encapsular los descriptores de OpenCV en sus métodos más empleados
 * \author ErCmos
 */

#include <opencv2/opencv.hpp>

class OCV_Descriptor
{
public:
    OCV_Descriptor();
    ~OCV_Descriptor();


    //////////////////// DETECTORES /////////////////////////////////////////
    void Detector(cv::VideoCapture cap);
    //////////////////// FIN DETECTORES /////////////////////////////////////
    ///
    //////////////////// DESCRIPTORES /////////////////////////////////////////

    //////////////////// FIN DESCRIPTORES /////////////////////////////////////
};

#endif // OCV_DESCRIPTOR_H
