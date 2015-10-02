#ifndef OCV_PLAYER_H
#define OCV_PLAYER_H

#include <opencv2/opencv.hpp>
#include <string.h>

/**
 * @brief The OCV_Player class encapsulates most used OpenCV functions for player
 */
class OCV_Player
{
public:
    OCV_Player();
    ~OCV_Player();

    //////////////////// VISUALIZACIÓN ////////////////////////////////////////
    /**
    * @brief Play_VideoCapture
    * @param cap VideoCapturer to be played
    * @param WindowName Name for the display window
    */
    void Play_VideoCapture(cv::VideoCapture cap, std::string WindowName);
    //////////////////// FIN VISUALIZACIÓN ////////////////////////////////////
};

#endif // OCV_PLAYER_H
