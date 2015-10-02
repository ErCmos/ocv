#ifndef OCV_CAPTURER_H
#define OCV_CAPTURER_H

#include <opencv2/opencv.hpp>
#include "opencv2/videoio.hpp"
#include <string.h>

/**
 * @brief The OCV_Capturer class encapsulates most used OpenCV functions for capture
 * @author ErCmos
 */
class OCV_Capturer
{
public:
    /**
     * @brief Constructor of the Class OCV_Capturer
     */
    OCV_Capturer();
    ~OCV_Capturer();

    //////////////////// CAPTURA //////////////////////////////////////////////
    /**
     * @brief OpenVideoFile
     * @param dirName where file is located
     * @param fileName to be opened
     * @return VideoCapturer Returned
     */
    cv::VideoCapture OpenVideoFile(std::string dirName, std::string fileName);
    /**
     * @brief OpenVideoFile
     * @param fileName to be opened
     * @return VideoCapturer returned
     */
    cv::VideoCapture OpenVideoFile(std::string fileName);
    /**
     * @brief OpenVideoFile
     * @param device or WebCam to be opened
     * @return VideoCapturer returned
     */
    cv::VideoCapture OpenVideoFile(int device);
    //////////////////// FIN CAPTURA //////////////////////////////////////////
};

#endif // OCV_CAPTURER_H
