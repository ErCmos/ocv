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
std::vector<KeyPoint> OCV_Detector::DetectorBRIEF(Mat frame, int bytes = 32, bool use_orientation = false)
{
    Mat img_1;
    Ptr<BriefDescriptorExtractor> detector = BriefDescriptorExtractor::create(bytes,use_orientation);
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
std::vector<KeyPoint> OCV_Detector::DetectorDAISY(Mat frame, float radius=15, int q_radius=3, int q_theta=8, int q_hist=8, int norm=DAISY::NRM_NONE, InputArray H=noArray(), bool interpolation=true, bool use_orientation=false)
{
    Mat img_1;
    Ptr<DAISY> detector = DAISY::create(radius, q_radius, q_theta, q_hist, norm, H, interpolation, use_orientation);
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
std::vector<KeyPoint> OCV_Detector::DetectorFAST(Mat frame, int threshold=10, bool nonmaxSuppression=true, int type=FastFeatureDetector::TYPE_9_16)
{
    Mat img_1;
    Ptr<FastFeatureDetector> detector = FastFeatureDetector::create(threshold, nonmaxSuppression, type);
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
std::vector<KeyPoint> OCV_Detector::DetectorFREAK(Mat frame, bool orientationNormalized=true, bool scaleNormalized=true, float patternScale=22.0f, int nOctaves=4, const std::vector< int > &selectedPairs=std::vector< int >())
{
    Mat img_1;
    Ptr<FREAK> detector = FREAK::create(orientationNormalized, scaleNormalized, patternScale, nOctaves, selectedPairs);
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
std::vector<KeyPoint> OCV_Detector::DetectorGFTT(Mat frame, int maxCorners=1000, double qualityLevel=0.01, double minDistance=1, int blockSize=3, bool useHarrisDetector=false, double k=0.04)
{
    Mat img_1;
    Ptr<GFTTDetector> detector = GFTTDetector::create(maxCorners, qualityLevel, minDistance, blockSize, useHarrisDetector, k);
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
std::vector<KeyPoint> OCV_Detector::DetectorKAZE(Mat frame, bool extended=false, bool upright=false, float threshold=0.001f, int nOctaves=4, int nOctaveLayers=4, int diffusivity=KAZE::DIFF_PM_G2)
{
    Mat img_1;
    Ptr<KAZE> detector = KAZE::create(extended, upright, threshold, nOctaves, nOctaveLayers, diffusivity);
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
std::vector<KeyPoint> OCV_Detector::DetectorLATCH(Mat frame, int bytes=32, bool rotationInvariance=true, int half_ssd_size=3)
{
    Mat img_1;
    Ptr<LATCH> detector = LATCH::create(bytes, rotationInvariance, half_ssd_size);
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
std::vector<KeyPoint> OCV_Detector::DetectorLUCID(Mat frame, const int lucid_kernel=1, const int blur_kernel=1)
{
    Mat img_1;
    Ptr<LUCID> detector = LUCID::create(lucid_kernel, blur_kernel);
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
std::vector<KeyPoint> OCV_Detector::DetectorMSER(Mat frame, int _delta=5, int _min_area=60, int _max_area=14400, double _max_variation=0.25, double _min_diversity=.2, int _max_evolution=200, double _area_threshold=1.01, double _min_margin=0.003, int _edge_blur_size=5)
{
    Mat img_1;
    Ptr<MSER> detector = MSER::create(_delta, _min_area, _max_area, _max_variation, _min_diversity, _max_evolution, _area_threshold, _min_margin, _edge_blur_size);
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
std::vector<KeyPoint> OCV_Detector::DetectorORB(Mat frame, int nfeatures=500, float scaleFactor=1.2f, int nlevels=8, int edgeThreshold=31, int firstLevel=0, int WTA_K=2, int scoreType=ORB::HARRIS_SCORE, int patchSize=31, int fastThreshold=20)
{
    Mat img_1;
    Ptr<ORB> detector = ORB::create(nfeatures, scaleFactor, nlevels, edgeThreshold, firstLevel, WTA_K, scoreType, patchSize, fastThreshold);
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
std::vector<KeyPoint> OCV_Detector::DetectorSBD(Mat frame, const SimpleBlobDetector::Params &parameters=SimpleBlobDetector::Params())
{
    Mat img_1;
    Ptr<SimpleBlobDetector> detector = SimpleBlobDetector::create(parameters);
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
std::vector<KeyPoint> OCV_Detector::DetectorSIFT(Mat frame, int nfeatures=0, int nOctaveLayers=3, double contrastThreshold=0.04, double edgeThreshold=10, double sigma=1.6)
{
    Mat img_1;
    Ptr<SIFT> detector = SIFT::create(nfeatures, nOctaveLayers, contrastThreshold, edgeThreshold, sigma);
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
std::vector<KeyPoint> OCV_Detector::DetectorSTAR(Mat frame, int maxSize=45, int responseThreshold=30, int lineThresholdProjected=10, int lineThresholdBinarized=8, int suppressNonmaxSize=5)
{
    Mat img_1;
    Ptr<StarDetector> detector = StarDetector::create(maxSize, responseThreshold, lineThresholdProjected, lineThresholdBinarized, suppressNonmaxSize);
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
