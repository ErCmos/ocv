#include "ocv_descriptor.h"

OCV_Descriptor::OCV_Descriptor()
{

}

OCV_Descriptor::~OCV_Descriptor()
{

}

//#include <stdio.h>
//#include <iostream>
#include "opencv2/core.hpp"
#include <opencv2/opencv.hpp>
//#include "opencv2/features2d.hpp"
//#include "opencv2/xfeatures2d.hpp"
//#include "opencv2/highgui.hpp"
using namespace cv;
//using namespace cv::xfeatures2d;

/*!
 * \file ocv_descriptor.cpp
 * \brief OCV::OpenVideoFile as a sequence of images
 * \param dirName Nombre del Directorio de la secuencia
 * \param fileName nombre base de la secuencia
 * \author ErCmos
 * \return cap VideoCapturer
 */

//////////////////// DETECTORES /////////////////////////////////////////////////////
void OCV_Descriptor::Detector(VideoCapture cap)
{
    Mat frame, img;
    if (cap.isOpened())
    {
        for (;;)
        {
            cap >> frame;
            if (frame.empty())
                break;

        }
    }
}
//////////////////// FIN DETECTORES /////////////////////////////////////////////////
///
//////////////////// DESCRIPTORES /////////////////////////////////////////////////////

//////////////////// FIN DESCRIPTORES /////////////////////////////////////////////////
