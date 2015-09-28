#include "ocv.h"

OCV::OCV()
{

}

OCV::~OCV()
{

}

using namespace std;
using namespace cv;


//////////////////// CAPTURA //////////////////////////////////////////////////
/*!
 * \file ocv.cpp
 * \brief OCV::OpenVideoFile as a sequence of images
 * \param dirName Nombre del Directorio de la secuencia
 * \param fileName nombre base de la secuencia
 * \author ErCmos
 * \return cap VideoCapturer
 */
VideoCapture OCV::OpenVideoFile(string dirName, string fileName)
{
    VideoCapture cap;
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
    secuencia = convert.str(); // set 'secuencia' to the contents of the stream
    string ruta2 = dirName+"/"+fichero.substr(0,i)+"%"+secuencia+"d."+extension;

    cap.open(ruta2);
    return cap;
}
/*!
 * \file ocv.cpp
 * \brief OCV::OpenVideoFile as a single video file
 * \param fileName Video Filename
 * \author ErCmos
 * \return cap VideoCapturer
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
 * \return cap VideoCApturer
 */

VideoCapture OCV::OpenVideoFile(int device)
{
    VideoCapture cap; /**< Instancia del capturador */
    cap.open(device);
    return cap;
}
/////////////////////// FIN CAPTURA //////////////////////////////////////////////////

/////////////////////// VISUALIZACIÓN /////////////////////////////////////////////////
/*!
 * \file ocv.cpp
 * \brief OCV::Play_VideoCapture
 * \param cap VideoCapture
 * \author ErCmos
 * \return void
 */
void OCV::Play_VideoCapture(VideoCapture cap, string WindowName)
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
