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
    /**
     * @brief DetectorAGAST
     * @param frame
     * @param threshold threshold on difference between intensity of the central pixel and pixels of a circle around this pixel.
     * @param nonmaxSuppression if true, non-maximum suppression is applied to detected corners (keypoints).
     * @param type one of the four neighborhoods as defined in the paper: AgastFeatureDetector::AGAST_5_8, AgastFeatureDetector::AGAST_7_12d, AgastFeatureDetector::AGAST_7_12s, AgastFeatureDetector::OAST_9_16.
     * @return
     */
    std::vector<cv::KeyPoint> DetectorAGAST(cv::Mat frame, int threshold, bool nonmaxSuppression, int type);
    std::vector<cv::KeyPoint> DetectorAKAZE(cv::Mat frame);
    /**
     * @brief DetectorAKAZE
     * @param frame
     * @param descriptor_type Type of the extracted descriptor: DESCRIPTOR_KAZE, DESCRIPTOR_KAZE_UPRIGHT, DESCRIPTOR_MLDB or DESCRIPTOR_MLDB_UPRIGHT.
     * @param descriptor_size Size of the descriptor in bits. 0 -> Full size.
     * @param descriptor_channels Number of channels in the descriptor (1, 2, 3).
     * @param threshold Detector response threshold to accept point.
     * @param nOctaves Maximum octave evolution of the image.
     * @param nOctaveLayers Default number of sublevels per scale level.
     * @param diffusivity Diffusivity type. DIFF_PM_G1, DIFF_PM_G2, DIFF_WEICKERT or DIFF_CHARBONNIER
     * @return
     */
    std::vector<cv::KeyPoint> DetectorAKAZE(cv::Mat frame, int descriptor_type, int descriptor_size, int descriptor_channels, float threshold, int nOctaves, int nOctaveLayers, int diffusivity);
    std::vector<cv::KeyPoint> DetectorBRISK(cv::Mat frame);
    /**
     * @brief DetectorBRISK
     * @param frame
     * @param thresh AGAST detection threshold score.
     * @param octaves Detection octaves. Use 0 to do single scale.
     * @param patternScale Spply this scale to the pattern used for sampling the neighbourhood of a keypoint.
     * @return
     */
    std::vector<cv::KeyPoint> DetectorBRISK(cv::Mat frame, int thresh, int octaves, float patternScale);
    std::vector<cv::KeyPoint> DetectorBRIEF(cv::Mat frame);
    /**
     * @brief DetectorBRIEF
     * @param frame
     * @param bytes legth of the descriptor in bytes, valid values are: 16, 32 (default) or 64.
     * @param use_orientation sample patterns using keypoints orientation, disabled by default.
     * @return
     */
    std::vector<cv::KeyPoint> DetectorBRIEF(cv::Mat frame, int bytes, bool use_orientation);
    std::vector<cv::KeyPoint> DetectorDAISY(cv::Mat frame);
    /**
     * @brief DetectorDAISY
     * @param frame
     * @param radius Radius of the descriptor at the initial scale.
     * @param q_radius Amount of radial range division quantity.
     * @param q_theta Amount of angular range division quantity.
     * @param q_hist Amount of gradient orientations range division quantity.
     * @param norm Choose descriptors normalization type, where DAISY::NRM_NONE will not do any normalization (default), DAISY::NRM_PARTIAL mean that histograms are normalized independently for L2 norm equal to 1.0, DAISY::NRM_FULL mean that descriptors are normalized for L2 norm equal to 1.0, DAISY::NRM_SIFT mean that descriptors are normalized for L2 norm equal to 1.0 but no individual one is bigger than 0.154 as in SIFT.
     * @param H Optional 3x3 homography matrix used to warp the grid of daisy but sampling keypoints remains unwarped on image.
     * @param interpolation Switch to disable interpolation for speed improvement at minor quality loss.
     * @param use_orientation Sample patterns using keypoints orientation, disabled by default.
     * @return
     */
    std::vector<cv::KeyPoint> DetectorDAISY(cv::Mat frame, float radius, int q_radius, int q_theta, int q_hist, int norm, cv::InputArray H, bool interpolation, bool use_orientation);
    std::vector<cv::KeyPoint> DetectorFAST(cv::Mat frame);
    /**
     * @brief DetectorFAST
     * @param frame
     * @param threshold Threshold on difference between intensity of the central pixel and pixels of a circle around this pixel.
     * @param nonmaxSuppression If true, non-maximum suppression is applied to detected corners (keypoints).
     * @param type One of the three neighborhoods as defined in the paper: FastFeatureDetector::TYPE_9_16, FastFeatureDetector::TYPE_7_12, FastFeatureDetector::TYPE_5_8.
     * @return
     */
    std::vector<cv::KeyPoint> DetectorFAST(cv::Mat frame, int threshold, bool nonmaxSuppression, int type);
    std::vector<cv::KeyPoint> DetectorFREAK(cv::Mat frame);
    /**
     * @brief DetectorFREAK
     * @param frame
     * @param orientationNormalized Enable orientation normalization.
     * @param scaleNormalized Enable scale normalization.
     * @param patternScale Scaling of the description pattern.
     * @param nOctaves Number of octaves covered by the detected keypoints.
     * @param selectedPairs (Optional) user defined selected pairs indexes.
     * @return
     */
    std::vector<cv::KeyPoint> DetectorFREAK(cv::Mat frame, bool orientationNormalized, bool scaleNormalized, float patternScale, int nOctaves, const std::vector< int > &selectedPairs);
    std::vector<cv::KeyPoint> DetectorGFTT(cv::Mat frame);
    /**
     * @brief DetectorGFTT
     * @param frame
     * @param maxCorners
     * @param qualityLevel
     * @param minDistance
     * @param blockSize
     * @param useHarrisDetector
     * @param k
     * @return
     */
    std::vector<cv::KeyPoint> DetectorGFTT(cv::Mat frame, int maxCorners, double qualityLevel, double minDistance, int blockSize, bool useHarrisDetector, double k);
    std::vector<cv::KeyPoint> DetectorKAZE(cv::Mat frame);
    /**
     * @brief DetectorKAZE
     * @param frame
     * @param extended Set to enable extraction of extended (128-byte) descriptor.
     * @param upright Set to enable use of upright descriptors (non rotation-invariant).
     * @param threshold Detector response threshold to accept point.
     * @param nOctaves Maximum octave evolution of the image.
     * @param nOctaveLayers Default number of sublevels per scale level.
     * @param diffusivity Diffusivity type. DIFF_PM_G1, DIFF_PM_G2, DIFF_WEICKERT or DIFF_CHARBONNIER.
     * @return
     */
    std::vector<cv::KeyPoint> DetectorKAZE(cv::Mat frame, bool extended, bool upright, float threshold, int nOctaves, int nOctaveLayers, int diffusivity);
    std::vector<cv::KeyPoint> DetectorLATCH(cv::Mat frame);
    /**
     * @brief DetectorLATCH
     * @param frame
     * @param bytes Is the size of the descriptor - can be 64, 32, 16, 8, 4, 2 or 1.
     * @param rotationInvariance Whether or not the descriptor should compansate for orientation.
     * @param half_ssd_size The size of half of the mini-patches size.
     * @return
     */
    std::vector<cv::KeyPoint> DetectorLATCH(cv::Mat frame, int bytes, bool rotationInvariance, int half_ssd_size);
    std::vector<cv::KeyPoint> DetectorLUCID(cv::Mat frame);
    /**
     * @brief DetectorLUCID
     * @param frame
     * @param lucid_kernel Kernel for descriptor construction, where 1=3x3, 2=5x5, 3=7x7 and so forth.
     * @param blur_kernel KIernel for blurring image prior to descriptor construction, where 1=3x3, 2=5x5, 3=7x7 and so forth.
     * @return
     */
    std::vector<cv::KeyPoint> DetectorLUCID(cv::Mat frame, const int lucid_kernel, const int blur_kernel);
    std::vector<cv::KeyPoint> DetectorMSER(cv::Mat frame);
    /**
     * @brief DetectorMSER
     * @param frame
     * @param _delta
     * @param _min_area
     * @param _max_area
     * @param _max_variation
     * @param _min_diversity
     * @param _max_evolution
     * @param _area_threshold
     * @param _min_margin
     * @param _edge_blur_size
     * @return
     */
    std::vector<cv::KeyPoint> DetectorMSER(cv::Mat frame, int _delta, int _min_area, int _max_area, double _max_variation, double _min_diversity, int _max_evolution, double _area_threshold, double _min_margin, int _edge_blur_size);
    std::vector<cv::KeyPoint> DetectorORB(cv::Mat frame);
    /**
     * @brief DetectorORB
     * @param frame
     * @param nfeatures The maximum number of features to retain.
     * @param scaleFactor Pyramid decimation ratio, greater than 1. scaleFactor==2 means the classical pyramid, where each next level has 4x less pixels than the previous, but such a big scale factor will degrade feature matching scores dramatically. On the other hand, too close to 1 scale factor will mean that to cover certain scale range you will need more pyramid levels and so the speed will suffer.
     * @param nlevels The number of pyramid levels. The smallest level will have linear size equal to input_image_linear_size/pow(scaleFactor, nlevels).
     * @param edgeThreshold This is size of the border where the features are not detected. It should roughly match the patchSize parameter.
     * @param firstLevel It should be 0 in the current implementation.
     * @param WTA_K The number of points that produce each element of the oriented BRIEF descriptor. The default value 2 means the BRIEF where we take a random point pair and compare their brightnesses, so we get 0/1 response. Other possible values are 3 and 4. For example, 3 means that we take 3 random points (of course, those point coordinates are random, but they are generated from the pre-defined seed, so each element of BRIEF descriptor is computed deterministically from the pixel rectangle), find point of maximum brightness and output index of the winner (0, 1 or 2). Such output will occupy 2 bits, and therefore it will need a special variant of Hamming distance, denoted as NORM_HAMMING2 (2 bits per bin). When WTA_K=4, we take 4 random points to compute each bin (that will also occupy 2 bits with possible values 0, 1, 2 or 3).
     * @param scoreType The default HARRIS_SCORE means that Harris algorithm is used to rank features (the score is written to KeyPoint::score and is used to retain best nfeatures features); FAST_SCORE is alternative value of the parameter that produces slightly less stable keypoints, but it is a little faster to compute.
     * @param patchSize Size of the patch used by the oriented BRIEF descriptor. Of course, on smaller pyramid layers the perceived image area covered by a feature will be larger.
     * @param fastThreshold
     * @return
     */
    std::vector<cv::KeyPoint> DetectorORB(cv::Mat frame, int nfeatures, float scaleFactor, int nlevels, int edgeThreshold, int firstLevel, int WTA_K, int scoreType, int patchSize, int fastThreshold);
    std::vector<cv::KeyPoint> DetectorSBD(cv::Mat frame);
    /**
     * @brief DetectorSBD
     * @param frame
     * @param parameters
     * @return
     */
    std::vector<cv::KeyPoint> DetectorSBD(cv::Mat frame, const cv::SimpleBlobDetector::Params &parameters);
    std::vector<cv::KeyPoint> DetectorSIFT(cv::Mat frame);
    /**
     * @brief DetectorSIFT
     * @param frame
     * @param nfeatures The number of best features to retain. The features are ranked by their scores (measured in SIFT algorithm as the local contrast).
     * @param nOctaveLayers The number of layers in each octave. 3 is the value used in D. Lowe paper. The number of octaves is computed automatically from the image resolution.
     * @param contrastThreshold The contrast threshold used to filter out weak features in semi-uniform (low-contrast) regions. The larger the threshold, the less features are produced by the detector.
     * @param edgeThreshold The threshold used to filter out edge-like features. Note that the its meaning is different from the contrastThreshold, i.e. the larger the edgeThreshold, the less features are filtered out (more features are retained).
     * @param sigma The sigma of the Gaussian applied to the input image at the octave #0. If your image is captured with a weak camera with soft lenses, you might want to reduce the number.
     * @return
     */
    std::vector<cv::KeyPoint> DetectorSIFT(cv::Mat frame, int nfeatures, int nOctaveLayers, double contrastThreshold, double edgeThreshold, double sigma);
    std::vector<cv::KeyPoint> DetectorSTAR(cv::Mat frame);
    /**
     * @brief DetectorSTAR
     * @param frame
     * @param maxSize
     * @param responseThreshold
     * @param lineThresholdProjected
     * @param lineThresholdBinarized
     * @param suppressNonmaxSize
     * @return
     */
    std::vector<cv::KeyPoint> DetectorSTAR(cv::Mat frame, int maxSize, int responseThreshold, int lineThresholdProjected, int lineThresholdBinarized, int suppressNonmaxSize);
    std::vector<cv::KeyPoint> DetectorSURF(cv::Mat frame);
    /**
     * @brief DetectorSURF
     * @param frame
     * @param hessianThreshold Threshold for hessian keypoint detector used in SURF.
     * @param nOctaves Number of pyramid octaves the keypoint detector will use.
     * @param nOctaveLayers Number of octave layers within each octave.
     * @param extended Extended descriptor flag (true - use extended 128-element descriptors; false - use 64-element descriptors).
     * @param upright Up-right or rotated features flag (true - do not compute orientation of features; false - compute orientation).
     * @return
     */
    std::vector<cv::KeyPoint> DetectorSURF(cv::Mat frame, double hessianThreshold, int nOctaves, int nOctaveLayers, bool extended, bool upright);
    /**
     * @brief Detector
     * @param frame
     * @param Tipo_Detector
     * @return
     */
    std::vector<cv::KeyPoint> Detector(cv::Mat frame, std::string Tipo_Detector);
    //////////////////// FIN DETECTORES /////////////////////////////////////
    ///
};

#endif // OCV_DETECTOR_H
