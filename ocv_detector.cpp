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

std::vector<KeyPoint> OCV_Detector::DetectorAGAST(Mat frame)
{
    Mat img_1;
    Ptr<AgastFeatureDetector> detector = AgastFeatureDetector::create();
    std::vector<KeyPoint> keypoints_1;

    //-- Step 1: Detect the keypoints using SURF Detector
    cvtColor(frame,img_1,CV_BGR2GRAY);
    detector->detect( img_1, keypoints_1 );

    return keypoints_1;
}
std::vector<KeyPoint> OCV_Detector::DetectorAGAST(Mat frame, int threshold=10, bool nonmaxSuppression=true, int type=AgastFeatureDetector::OAST_9_16)
{
    Mat img_1;
    Ptr<AgastFeatureDetector> detector = AgastFeatureDetector::create(threshold, nonmaxSuppression, type);
    std::vector<KeyPoint> keypoints_1;

    //-- Step 1: Detect the keypoints using SURF Detector
    cvtColor(frame,img_1,CV_BGR2GRAY);
    detector->detect( img_1, keypoints_1 );

    return keypoints_1;
}

std::vector<KeyPoint> OCV_Detector::DetectorAKAZE(Mat frame)
{
    Mat img_1;
    Ptr<AKAZE> detector = AKAZE::create();
    std::vector<KeyPoint> keypoints_1;

    //-- Step 1: Detect the keypoints using SURF Detector
    cvtColor(frame,img_1,CV_BGR2GRAY);
    detector->detect( img_1, keypoints_1 );

    return keypoints_1;
}
std::vector<KeyPoint> OCV_Detector::DetectorAKAZE(Mat frame, int descriptor_type=AKAZE::DESCRIPTOR_MLDB, int descriptor_size=0, int descriptor_channels=3, float threshold=0.001f, int nOctaves=4, int nOctaveLayers=4, int diffusivity=KAZE::DIFF_PM_G2)
{
    Mat img_1;
    Ptr<AKAZE> detector = AKAZE::create(descriptor_type, descriptor_size, descriptor_channels, threshold, nOctaves, nOctaveLayers, diffusivity);
    std::vector<KeyPoint> keypoints_1;

    //-- Step 1: Detect the keypoints using SURF Detector
    cvtColor(frame,img_1,CV_BGR2GRAY);
    detector->detect( img_1, keypoints_1 );

    return keypoints_1;
}

std::vector<KeyPoint> OCV_Detector::DetectorBRISK(Mat frame)
{
    Mat img_1;
    Ptr<BRISK> detector = BRISK::create();
    std::vector<KeyPoint> keypoints_1;

    //-- Step 1: Detect the keypoints using SURF Detector
    cvtColor(frame,img_1,CV_BGR2GRAY);
    detector->detect( img_1, keypoints_1 );

    return keypoints_1;
}
std::vector<KeyPoint> OCV_Detector::DetectorBRISK(Mat frame, int thresh=30, int octaves=3, float patternScale=1.0f)
{
    Mat img_1;
    Ptr<BRISK> detector = BRISK::create(thresh, octaves, patternScale);
    std::vector<KeyPoint> keypoints_1;

    //-- Step 1: Detect the keypoints using SURF Detector
    cvtColor(frame,img_1,CV_BGR2GRAY);
    detector->detect( img_1, keypoints_1 );

    return keypoints_1;
}

std::vector<KeyPoint> OCV_Detector::DetectorSURF(Mat frame)
{
    Mat img_1;
    Ptr<SURF> detector = SURF::create();
    std::vector<KeyPoint> keypoints_1;

    //-- Step 1: Detect the keypoints using SURF Detector
    cvtColor(frame,img_1,CV_BGR2GRAY);
    detector->detect( img_1, keypoints_1 );

    return keypoints_1;
}
std::vector<KeyPoint> OCV_Detector::DetectorSURF(Mat frame, double hessianThreshold=100, int nOctaves=4, int nOctaveLayers=3, bool extended=false, bool upright=false)
{
    Mat img_1;
    //int minHessian = 400;
    //Ptr<SURF> detector = SURF::create( minHessian );
    Ptr<SURF> detector = SURF::create( hessianThreshold, nOctaves,  nOctaveLayers,  extended, upright );
    std::vector<KeyPoint> keypoints_1;

    //-- Step 1: Detect the keypoints using SURF Detector
    cvtColor(frame,img_1,CV_BGR2GRAY);
    detector->detect( img_1, keypoints_1 );

    return keypoints_1;
}


std::vector<KeyPoint> OCV_Detector::DetectorSIFT(Mat frame)
{
    Mat img_1;
    Ptr<SIFT> detector = SIFT::create();
    std::vector<KeyPoint> keypoints_1;

    //-- Step 1: Detect the keypoints using SURF Detector
    cvtColor(frame,img_1,CV_BGR2GRAY);
    detector->detect( img_1, keypoints_1 );

    return keypoints_1;
}




std::vector<KeyPoint> OCV_Detector::DetectorBRIEF(Mat frame)
{
    Mat img_1;
    Ptr<BriefDescriptorExtractor> detector = BriefDescriptorExtractor::create();
    std::vector<KeyPoint> keypoints_1;

    //-- Step 1: Detect the keypoints using SURF Detector
    cvtColor(frame,img_1,CV_BGR2GRAY);
    detector->detect( img_1, keypoints_1 );

    return keypoints_1;
}
std::vector<KeyPoint> OCV_Detector::DetectorDAISY(Mat frame)
{
    Mat img_1;
    Ptr<DAISY> detector = DAISY::create();
    std::vector<KeyPoint> keypoints_1;

    //-- Step 1: Detect the keypoints using SURF Detector
    cvtColor(frame,img_1,CV_BGR2GRAY);
    detector->detect( img_1, keypoints_1 );

    return keypoints_1;
}
std::vector<KeyPoint> OCV_Detector::DetectorFAST(Mat frame)
{
    Mat img_1;
    Ptr<FastFeatureDetector> detector = FastFeatureDetector::create();
    std::vector<KeyPoint> keypoints_1;

    //-- Step 1: Detect the keypoints using SURF Detector
    cvtColor(frame,img_1,CV_BGR2GRAY);
    detector->detect( img_1, keypoints_1 );

    return keypoints_1;
}

std::vector<KeyPoint> OCV_Detector::DetectorGFTT(Mat frame)
{
    Mat img_1;
    Ptr<GFTTDetector> detector = GFTTDetector::create();
    std::vector<KeyPoint> keypoints_1;

    //-- Step 1: Detect the keypoints using SURF Detector
    cvtColor(frame,img_1,CV_BGR2GRAY);
    detector->detect( img_1, keypoints_1 );

    return keypoints_1;
}
std::vector<KeyPoint> OCV_Detector::DetectorKAZE(Mat frame)
{
    Mat img_1;
    Ptr<KAZE> detector = KAZE::create();
    std::vector<KeyPoint> keypoints_1;

    //-- Step 1: Detect the keypoints using SURF Detector
    cvtColor(frame,img_1,CV_BGR2GRAY);
    detector->detect( img_1, keypoints_1 );

    return keypoints_1;
}
std::vector<KeyPoint> OCV_Detector::DetectorLATCH(Mat frame)
{
    Mat img_1;
    Ptr<LATCH> detector = LATCH::create();
    std::vector<KeyPoint> keypoints_1;

    //-- Step 1: Detect the keypoints using SURF Detector
    cvtColor(frame,img_1,CV_BGR2GRAY);
    detector->detect( img_1, keypoints_1 );

    return keypoints_1;
}
std::vector<KeyPoint> OCV_Detector::DetectorLUCID(Mat frame)
{
    Mat img_1;
    Ptr<LUCID> detector = LUCID::create(1,1);
    std::vector<KeyPoint> keypoints_1;

    //-- Step 1: Detect the keypoints using SURF Detector
    cvtColor(frame,img_1,CV_BGR2GRAY);
    detector->detect( img_1, keypoints_1 );

    return keypoints_1;
}
std::vector<KeyPoint> OCV_Detector::DetectorMSER(Mat frame)
{
    Mat img_1;
    Ptr<MSER> detector = MSER::create();
    std::vector<KeyPoint> keypoints_1;

    //-- Step 1: Detect the keypoints using SURF Detector
    cvtColor(frame,img_1,CV_BGR2GRAY);
    detector->detect( img_1, keypoints_1 );

    return keypoints_1;
}
std::vector<KeyPoint> OCV_Detector::DetectorORB(Mat frame)
{
    Mat img_1;
    Ptr<ORB> detector = ORB::create();
    std::vector<KeyPoint> keypoints_1;

    //-- Step 1: Detect the keypoints using SURF Detector
    cvtColor(frame,img_1,CV_BGR2GRAY);
    detector->detect( img_1, keypoints_1 );

    return keypoints_1;
}
std::vector<KeyPoint> OCV_Detector::DetectorSBD(Mat frame)
{
    Mat img_1;
    Ptr<SimpleBlobDetector> detector = SimpleBlobDetector::create();
    std::vector<KeyPoint> keypoints_1;

    //-- Step 1: Detect the keypoints using SURF Detector
    cvtColor(frame,img_1,CV_BGR2GRAY);
    detector->detect( img_1, keypoints_1 );

    return keypoints_1;
}
std::vector<KeyPoint> OCV_Detector::DetectorSTAR(Mat frame)
{
    Mat img_1;
    Ptr<StarDetector> detector = StarDetector::create();
    std::vector<KeyPoint> keypoints_1;

    //-- Step 1: Detect the keypoints using SURF Detector
    cvtColor(frame,img_1,CV_BGR2GRAY);
    detector->detect( img_1, keypoints_1 );

    return keypoints_1;
}
std::vector<KeyPoint> OCV_Detector::DetectorFREAK(Mat frame)
{
    Mat img_1;
    Ptr<FREAK> detector = FREAK::create();
    std::vector<KeyPoint> keypoints_1;

    //-- Step 1: Detect the keypoints using SURF Detector
    cvtColor(frame,img_1,CV_BGR2GRAY);
    detector->detect( img_1, keypoints_1 );

    return keypoints_1;
}

std::vector<KeyPoint> OCV_Detector::Detector(Mat frame, std::string Tipo_Detector)
{
    Mat img_1;
    if (Tipo_Detector=="SURF")
    {
        int minHessian = 400;
        Ptr<SURF> detector = SURF::create( minHessian );
        std::vector<KeyPoint> keypoints_1;
        //-- Step 1: Detect the keypoints using SURF Detector
        cvtColor(frame,img_1,CV_BGR2GRAY);
        detector->detect( img_1, keypoints_1 );
        return keypoints_1;
    }
    else if (Tipo_Detector=="SIFT")
    {
        Ptr<SIFT> detector = SIFT::create();
        std::vector<KeyPoint> keypoints_1;
        //-- Step 1: Detect the keypoints using SURF Detector
        cvtColor(frame,img_1,CV_BGR2GRAY);
        detector->detect( img_1, keypoints_1 );
        return keypoints_1;
    }
    else if (Tipo_Detector=="BRISK")
    {
        Ptr<BRISK> detector = BRISK::create();
        std::vector<KeyPoint> keypoints_1;
        //-- Step 1: Detect the keypoints using SURF Detector
        cvtColor(frame,img_1,CV_BGR2GRAY);
        detector->detect( img_1, keypoints_1 );
        return keypoints_1;
    }
    else if (Tipo_Detector=="BRIEF")
    {
        Ptr<BriefDescriptorExtractor> detector = BriefDescriptorExtractor::create();
        std::vector<KeyPoint> keypoints_1;
        //-- Step 1: Detect the keypoints using SURF Detector
        cvtColor(frame,img_1,CV_BGR2GRAY);
        detector->detect( img_1, keypoints_1 );
        return keypoints_1;
    }
    else if (Tipo_Detector=="DAISY")
    {
        Ptr<DAISY> detector = DAISY::create();
        std::vector<KeyPoint> keypoints_1;
        //-- Step 1: Detect the keypoints using SURF Detector
        cvtColor(frame,img_1,CV_BGR2GRAY);
        detector->detect( img_1, keypoints_1 );
        return keypoints_1;
    }
    else if (Tipo_Detector=="AKAZE")
    {
        Ptr<AKAZE> detector = AKAZE::create();
        std::vector<KeyPoint> keypoints_1;
        //-- Step 1: Detect the keypoints using SURF Detector
        cvtColor(frame,img_1,CV_BGR2GRAY);
        detector->detect( img_1, keypoints_1 );
        return keypoints_1;
    }
    else if (Tipo_Detector=="AGAST")
    {
        Ptr<AgastFeatureDetector> detector = AgastFeatureDetector::create();
        std::vector<KeyPoint> keypoints_1;
        //-- Step 1: Detect the keypoints using SURF Detector
        cvtColor(frame,img_1,CV_BGR2GRAY);
        detector->detect( img_1, keypoints_1 );
        return keypoints_1;
    }
    else if (Tipo_Detector=="FAST")
    {
        Ptr<FastFeatureDetector> detector = FastFeatureDetector::create();
        std::vector<KeyPoint> keypoints_1;
        //-- Step 1: Detect the keypoints using SURF Detector
        cvtColor(frame,img_1,CV_BGR2GRAY);
        detector->detect( img_1, keypoints_1 );
        return keypoints_1;
    }
    else if (Tipo_Detector=="GFTT")
    {
        Ptr<GFTTDetector> detector = GFTTDetector::create();
        std::vector<KeyPoint> keypoints_1;
        //-- Step 1: Detect the keypoints using SURF Detector
        cvtColor(frame,img_1,CV_BGR2GRAY);
        detector->detect( img_1, keypoints_1 );
        return keypoints_1;
    }
    else if (Tipo_Detector=="KAZE")
    {
        Ptr<KAZE> detector = KAZE::create();
        std::vector<KeyPoint> keypoints_1;
        //-- Step 1: Detect the keypoints using SURF Detector
        cvtColor(frame,img_1,CV_BGR2GRAY);
        detector->detect( img_1, keypoints_1 );
        return keypoints_1;
    }
    else if (Tipo_Detector=="LATCH")
    {
        Ptr<LATCH> detector = LATCH::create();
        std::vector<KeyPoint> keypoints_1;
        //-- Step 1: Detect the keypoints using SURF Detector
        cvtColor(frame,img_1,CV_BGR2GRAY);
        detector->detect( img_1, keypoints_1 );
        return keypoints_1;
    }
    else if (Tipo_Detector=="LUCID")
    {
        Ptr<LUCID> detector = LUCID::create(1,1);
        std::vector<KeyPoint> keypoints_1;
        //-- Step 1: Detect the keypoints using SURF Detector
        cvtColor(frame,img_1,CV_BGR2GRAY);
        detector->detect( img_1, keypoints_1 );
        return keypoints_1;
    }
    else if (Tipo_Detector=="MSER")
    {
        Ptr<MSER> detector = MSER::create();
        std::vector<KeyPoint> keypoints_1;
        //-- Step 1: Detect the keypoints using SURF Detector
        cvtColor(frame,img_1,CV_BGR2GRAY);
        detector->detect( img_1, keypoints_1 );
        return keypoints_1;
    }
    else if (Tipo_Detector=="ORB")
    {
        Ptr<ORB> detector = ORB::create();
        std::vector<KeyPoint> keypoints_1;
        //-- Step 1: Detect the keypoints using SURF Detector
        cvtColor(frame,img_1,CV_BGR2GRAY);
        detector->detect( img_1, keypoints_1 );
        return keypoints_1;
    }
    else if (Tipo_Detector=="SBD")
    {
        Ptr<SimpleBlobDetector> detector = SimpleBlobDetector::create();
        std::vector<KeyPoint> keypoints_1;
        //-- Step 1: Detect the keypoints using SURF Detector
        cvtColor(frame,img_1,CV_BGR2GRAY);
        detector->detect( img_1, keypoints_1 );
        return keypoints_1;
    }
    else if (Tipo_Detector=="STAR")
    {
        Ptr<StarDetector> detector = StarDetector::create();
        std::vector<KeyPoint> keypoints_1;
        //-- Step 1: Detect the keypoints using SURF Detector
        cvtColor(frame,img_1,CV_BGR2GRAY);
        detector->detect( img_1, keypoints_1 );
        return keypoints_1;
    }
    else if (Tipo_Detector=="FREAK")
    {
        Ptr<FREAK> detector = FREAK::create();
        std::vector<KeyPoint> keypoints_1;
        //-- Step 1: Detect the keypoints using SURF Detector
        cvtColor(frame,img_1,CV_BGR2GRAY);
        detector->detect( img_1, keypoints_1 );
        return keypoints_1;
    }
}

//////////////////// FIN DETECTORES /////////////////////////////////////////////////
///
