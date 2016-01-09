#ifndef IMAGEONIMAGE_H
#define IMAGEONIMAGE_H

// OpenCV stuff
#include <opencv2/core/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/features2d.hpp>
#include "opencv2/xfeatures2d.hpp"
#include <opencv2/calib3d.hpp> // for homography
#include "opencv2/imgproc.hpp"

//MessageBox
#include <QMessageBox>

class ImageOnImage
{
public:
    ImageOnImage();
    ~ImageOnImage();
    void Detecta(std::string fileName, std::string sceneName);
};

#endif // IMAGEONIMAGE_H
