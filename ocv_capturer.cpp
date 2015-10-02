#include "ocv_capturer.h"

OCV_Capturer::OCV_Capturer()
{

}

OCV_Capturer::~OCV_Capturer()
{

}

using namespace std;
using namespace cv;

//////////////////// CAPTURA //////////////////////////////////////////////////

VideoCapture OCV_Capturer::OpenVideoFile(string dirName, string fileName)
{
    VideoCapture cap;
    string extension = "";
    string fichero = "";
    string temp;
    unsigned int i=0;
    unsigned int a=0;
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
    string ruta2="";
    if (a!=0)
    {
        string secuencia="";

        ostringstream convert;   // stream used for the conversion
        convert << (a-i);      // insert the textual representation of 'Number' in the characters in the stream
        secuencia = convert.str(); // set 'secuencia' to the contents of the stream
        ruta2 = dirName+"/"+fichero.substr(0,i)+"%"+secuencia+"d."+extension;
    }
    else
    {
        ruta2 = dirName+"/"+fileName;
    }

    cap.open(ruta2);
    return cap;
}

VideoCapture OCV_Capturer::OpenVideoFile(string fileName)
{
    VideoCapture cap;
    cap.open(fileName);
    return cap;
}

VideoCapture OCV_Capturer::OpenVideoFile(int device)
{
    VideoCapture cap;
    cap.open(device);
    return cap;
}
/////////////////////// FIN CAPTURA //////////////////////////////////////////////////

