#include "ocv.h"

OCV::OCV()
{

}

OCV::~OCV()
{

}

using namespace std;
using namespace cv;

/*!
 * \file ocv.cpp
 * \bri1ef OCV::OpenVideoFile as a sequence of images
 * \para1221+m dirName Nombre del Directorio de la secuencia
 * \param fileName ombre base de la secuencia
 * \author ErCmos
 * \return
 */
VideoCapture OCV::OpenVideoFile(string dirName, string fileName)
{
/*
char* Dataset_Dir( "C:/Data/" ); // Or take it from argv[1]
cv::Mat normal_matrix;
std::vector<cv::Mat>* image_stack;
for( int i=1; i<=endNumber; ++i )
{
    // Gives the entire stack of images for you to go through
    image_stack->push_back(cv::imread(std::format("%s/%03d-capture.png", Dataset, i), CV_LOAD_IMAGE_COLOR));

    normal_matrix = cv::imread(std::format("%s/%03d-capture.png", Dataset, i), CV_LOAD_IMAGE_COLOR);
}
*/

/*
 * cv::VideoCapture cap("G:/var/cache/zoneminder/events/1/13/10/21/07/50/00/%3d-capture.jpg");
 * */

    VideoCapture cap;

    string ruta = dirName+"/"+fileName;
    string extension = "";
    string fichero = "";
    string temp;
    unsigned int i;
    unsigned int a;
    if(fileName.find_last_of(".") != std::string::npos)
            extension = fileName.substr(fileName.find_last_of(".")+1);
            fichero = fileName.substr(0,fileName.find_last_of("."));
////////////////////////////////////////////////////////////////////////////
            for (i=0; i < fichero.size(); i++)
                {
                    //iterate the string to find the first "number" character
                    //if found create another loop to extract it
                    //and then break the current one
                    //thus extracting the FIRST encountered numeric block
                    if (isdigit(fichero[i]))
                    {
                        for (a=i; a<fichero.size(); a++)
                        {
                            temp += fichero[a];
                        }
                      //the first numeric block is extracted
                      break;
                    }
                }
////////////////////////////////////////////////////////////////////////////////

    string secuencia;

    ostringstream convert;   // stream used for the conversion

    convert << (a-i);      // insert the textual representation of 'Number' in the characters in the stream

    secuencia = convert.str(); // set 'Result' to the contents of the stream

    string ruta2 = dirName+"/"+fichero.substr(0,i)+"%"+secuencia+"d."+extension;
    //std::string pathToData("c:\\path\\cap_%%08d.bmp"); 8 ceros en la secuencia
    cap.open(ruta2);
    return cap;
}
/*!
 * \file ocv.cpp
 * \brief OCV::OpenVideoFile as a single video file
 * \param fileName Video Filename
 * \author ErCmos
 * \return
 */
VideoCapture OCV::OpenVideoFile(string fileName)
{
    VideoCapture cap;
    cap.open(fileName);
    return cap;
}

/*!
 * \file ocv.cpp
 * \brief OCV::OpenVideoFile as device -> WebCam
 * \param device Device Number
 * \author ErCmos
 * \return
 */
VideoCapture OCV::OpenVideoFile(int device)
{
    VideoCapture cap; /**< Instancia del capturador */
    cap.open(device);
    return cap;
}
