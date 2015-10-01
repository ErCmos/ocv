#include "ocv_descriptor.h"

OCV_Descriptor::OCV_Descriptor()
{

}

OCV_Descriptor::~OCV_Descriptor()
{

}

using namespace cv;
using namespace cv::xfeatures2d;

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
    Mat frame, img_1;
    if (cap.isOpened())
    {
        for (;;)
        {
            cap >> frame;
            if (frame.empty())
                break;
            cvtColor(frame,img_1,CV_BGR2GRAY);
            imshow("Imagen en BN",img_1);

            //-- Step 1: Detect the keypoints using SURF Detector
            int minHessian = 400;
            Ptr<SURF> detector = SURF::create( minHessian );
            std::vector<KeyPoint> keypoints_1;
            detector->detect( img_1, keypoints_1 );
            //-- Draw keypoints
            Mat img_keypoints_1;
            drawKeypoints( img_1, keypoints_1, img_keypoints_1, Scalar::all(-1), DrawMatchesFlags::DEFAULT );
            //-- Show detected (drawn) keypoints
            imshow("Keypoints 1", img_keypoints_1 );
            //waitKey(0);

            if(cv::waitKey(30) >= 0) break;
        }
    }
}
//////////////////// FIN DETECTORES /////////////////////////////////////////////////
///
//////////////////// DESCRIPTORES /////////////////////////////////////////////////////

//////////////////// FIN DESCRIPTORES /////////////////////////////////////////////////
