#ifndef BOW_H
#define BOW_H

//#include "stdafx.h"
//#include <opencv2/cv.h>
#include <QString>
#include <QDir>
#include <QMessageBox>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/features2d.hpp>
#include "opencv2/xfeatures2d.hpp"

/**
 * @brief The BoW class Clase para definir un Bag of Words
 * @author ErCmos
 */
class BoW
{
public:
    /**
     * @brief BoW Constructor y destructor del BoW
     */
    BoW();
    ~BoW();
    //////////////// CrearDiccionario ///////////////////
    void CrearDiccionario(std::string dirName);
    ////////////////////////////////////////////////

    //////////////// TageadorDiccionario ///////////////////
    void TageadorDiccionario(std::string dirName, std::string fileName);
    ////////////////////////////////////////////////
};

#endif // BOW_H
