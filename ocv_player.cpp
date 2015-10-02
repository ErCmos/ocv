#include "ocv_player.h"

OCV_Player::OCV_Player()
{

}

OCV_Player::~OCV_Player()
{

}

using namespace std;
using namespace cv;

/////////////////////// VISUALIZACIÓN /////////////////////////////////////////////////

void OCV_Player::Play_VideoCapture(VideoCapture cap, string WindowName)
{
    cv::Mat frame;
    if (cap.isOpened())
    {
        for (;;) //while (1)
        {
            cap >> frame;
            if (frame.empty())
                break;
            imshow(WindowName,frame);
            if(cv::waitKey(30) >= 0) break;
        }
    }
}
/////////////////////// FIN VISUALIZACIÓN /////////////////////////////////////////////
