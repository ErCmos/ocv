#include "ocv_detector.h"

OCV_Detector::OCV_Detector()
{

}

OCV_Detector::~OCV_Detector()
{

}

using namespace cv;
using namespace cv::xfeatures2d;

//////////////////// DETECTORES /////////////////////////////////////////////////////

void OCV_Detector::Detector(VideoCapture cap)
{
/*    Mat frame, img_1;
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
    }*/

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
            Ptr<SIFT> detector = SIFT::create();
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
