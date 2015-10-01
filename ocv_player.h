#ifndef OCV_PLAYER_H
#define OCV_PLAYER_H

#include <opencv2/opencv.hpp>
#include <string.h>

/*!
 * \file ocv_player.h
 * \brief Clase para encapsular el reproductor de OpenCV en sus métodos más empleados
 * \author ErCmos
 */
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
