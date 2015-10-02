#ifndef OCV_DESCRIPTOR_H
#define OCV_DESCRIPTOR_H

/*!
 * \file ocv_descriptor.h
 * \brief Clase para encapsular los descriptores de OpenCV en sus métodos más empleados
 * \author ErCmos
 */

#include "opencv2/core.hpp"
#include <opencv2/opencv.hpp>
#include "opencv2/videoio.hpp"
#include "opencv2/features2d.hpp"
#include "opencv2/xfeatures2d.hpp"
//#include "opencv2/highgui.hpp"

/**
 * @brief The OCV_Descriptor class encapsulates most used OpenCV functions for Detectors and Descriptors
 * @author ErCmos
 */
class OCV_Descriptor
{
public:
    OCV_Descriptor();
    ~OCV_Descriptor();


    //////////////////// DETECTORES /////////////////////////////////////////
    /**
    * @brief Detector Detector definition
    * @param cap
    */
    void Detector(cv::VideoCapture cap);
    //////////////////// FIN DETECTORES /////////////////////////////////////
    ///
    //////////////////// DESCRIPTORES /////////////////////////////////////////

    //////////////////// FIN DESCRIPTORES /////////////////////////////////////
};

#endif // OCV_DESCRIPTOR_H
