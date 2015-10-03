#ifndef OCV_DETECTOR_H
#define OCV_DETECTOR_H

#include "opencv2/core.hpp"
#include <opencv2/opencv.hpp>
#include "opencv2/videoio.hpp"
#include "opencv2/features2d.hpp"
#include "opencv2/xfeatures2d.hpp"


/**
 * @brief The OCV_Detector class encapsulates most used OpenCV functions for Detectors
 * @author ErCmos
 */
class OCV_Detector
{
public:
    OCV_Detector();
    ~OCV_Detector();

    //////////////////// DETECTORES /////////////////////////////////////////
    /**
    * @brief Detector Detector definition
    * @param cap VideoCapturer to be used
    */
    void DetectorSIFT(cv::VideoCapture cap);

    void DetectorSURF(cv::VideoCapture cap);

    std::vector<cv::KeyPoint> DetectorSURF2(cv::VideoCapture cap,cv::Mat &frame);
    //////////////////// FIN DETECTORES /////////////////////////////////////
    ///
};

#endif // OCV_DETECTOR_H
