#ifndef OCV_DETECTOR_H
#define OCV_DETECTOR_H

#include <string.h>

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
    //void DetectorSIFT(cv::VideoCapture cap);

    //void DetectorSURF(cv::VideoCapture cap);

    std::vector<cv::KeyPoint> DetectorAGAST(cv::Mat frame);
    std::vector<cv::KeyPoint> DetectorAGAST(cv::Mat frame, int threshold, bool nonmaxSuppression, int type);
    std::vector<cv::KeyPoint> DetectorAKAZE(cv::Mat frame);
    std::vector<cv::KeyPoint> DetectorAKAZE(cv::Mat frame, int descriptor_type, int descriptor_size, int descriptor_channels, float threshold, int nOctaves, int nOctaveLayers, int diffusivity);
    std::vector<cv::KeyPoint> DetectorBRISK(cv::Mat frame);
    std::vector<cv::KeyPoint> DetectorBRISK(cv::Mat frame, int thresh, int octaves, float patternScale);
    std::vector<cv::KeyPoint> DetectorBRIEF(cv::Mat frame);
    std::vector<cv::KeyPoint> DetectorDAISY(cv::Mat frame);

    std::vector<cv::KeyPoint> DetectorFAST(cv::Mat frame);
    std::vector<cv::KeyPoint> DetectorFREAK(cv::Mat frame);
    std::vector<cv::KeyPoint> DetectorGFTT(cv::Mat frame);
    std::vector<cv::KeyPoint> DetectorKAZE(cv::Mat frame);
    std::vector<cv::KeyPoint> DetectorLATCH(cv::Mat frame);
    std::vector<cv::KeyPoint> DetectorLUCID(cv::Mat frame);
    std::vector<cv::KeyPoint> DetectorMSER(cv::Mat frame);
    std::vector<cv::KeyPoint> DetectorORB(cv::Mat frame);
    std::vector<cv::KeyPoint> DetectorSBD(cv::Mat frame);
    //std::vector<cv::KeyPoint> DetectorSURF2(cv::VideoCapture cap,cv::Mat &frame);
    std::vector<cv::KeyPoint> DetectorSIFT(cv::Mat frame);
    std::vector<cv::KeyPoint> DetectorSTAR(cv::Mat frame);
    std::vector<cv::KeyPoint> DetectorSURF(cv::Mat frame, double hessianThreshold, int nOctaves, int nOctaveLayers, bool extended, bool upright);
    std::vector<cv::KeyPoint> DetectorSURF(cv::Mat frame);

    std::vector<cv::KeyPoint> Detector(cv::Mat frame, std::string Tipo_Detector);
    //////////////////// FIN DETECTORES /////////////////////////////////////
    ///
};

#endif // OCV_DETECTOR_H
