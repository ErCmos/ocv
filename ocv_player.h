#ifndef OCV_PLAYER_H
#define OCV_PLAYER_H

#include <opencv2/opencv.hpp>
#include <string.h>

class OCV_Player
{
public:
    OCV_Player();
    ~OCV_Player();

    //////////////////// VISUALIZACIÓN ////////////////////////////////////////
    void Play_VideoCapture(cv::VideoCapture cap, std::string WindowName);
    //////////////////// FIN VISUALIZACIÓN ////////////////////////////////////
};

#endif // OCV_PLAYER_H
