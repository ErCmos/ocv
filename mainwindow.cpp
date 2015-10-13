#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <ocv_capturer.h>
#include <ocv_player.h>
#include <ocv_detector.h>
#include <ocv_descriptor.h>
#include "opencv2/videoio.hpp"
#include "opencv2/features2d.hpp"
#include "opencv2/xfeatures2d.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

using namespace std;
OCV_Capturer Capturer;
cv::VideoCapture capturador;

void MainWindow::on_OpenFileButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
            tr("Open Video"), "/home/ercmos", tr("Video Files (*.avi *.mpg *.mp4 *.*)"));

    ui->OpenFilelabel->setText(fileName);

    //OCV_Capturer Capturer;
    //cv::VideoCapture cap=Capturer.OpenVideoFile(fileName.toStdString());
    capturador=Capturer.OpenVideoFile(fileName.toStdString());
    OCV_Player Player;
    Player.Play_VideoCapture(capturador,"Frames");
}

void MainWindow::on_WebCamButton_clicked()
{
    ui->OpenFilelabel->setText("Web Cam");

    //OCV_Capturer Capturer;
    //cv::VideoCapture cap=Capturer.OpenVideoFile(0);
    capturador=Capturer.OpenVideoFile(0);
    OCV_Player Player;
    Player.Play_VideoCapture(capturador,"Frames");
}

void MainWindow::on_SequenceButton_clicked()
{
    QString fullName = QFileDialog::getOpenFileName(this,
            tr("Open Video"), "/home/ercmos", tr("Video Files (*.avi *.mpg *.mp4 *.*)"));

    QString dirName = QFileInfo(fullName).absolutePath();
    QString fileName=QFileInfo(fullName).fileName();

    ui->OpenFilelabel->setText(dirName);

    //OCV_Capturer Capturer;
    //cv::VideoCapture cap=Capturer.OpenVideoFile(dirName.toStdString(), fileName.toStdString());
    capturador=Capturer.OpenVideoFile(dirName.toStdString(), fileName.toStdString());
    OCV_Player Player;
    Player.Play_VideoCapture(capturador,"Frames");
/*
    OCV_Capturer AbreFichero;

    cv::VideoCapture cap=AbreFichero.OpenVideoFile(dirName.toStdString(), fileName.toStdString());
    if( cap.isOpened() )
    {
        cv::Mat frame;
        int i=0;

        for (;;)
        {
            ostringstream convert;   // stream used for the conversion
            std::string titulo;
            convert << (++i);
            cap >> frame;
            if (frame.empty())
                break;
            titulo="Frame " + convert.str();
            ui->Frame->setText(QString::fromStdString(titulo));
            // + convert.str()
            imshow("Frame ",frame);
            if(cv::waitKey(30) >= 0) break;
        }
    }*/
}

void MainWindow::on_DetectorButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
            tr("Open Video"), "/home/ercmos", tr("Video Files (*.avi *.mpg *.mp4 *.*)"));

    ui->OpenFilelabel->setText(fileName);

    //OCV_Capturer Capturer;
    //cv::VideoCapture cap=Capturer.OpenVideoFile(fileName.toStdString());
    capturador=Capturer.OpenVideoFile(fileName.toStdString());
    OCV_Detector Detector;
    OCV_Player Player;
    std::vector<cv::KeyPoint> keypoints_1;
    cv::Mat img_keypoints_1, img_1, frame;
    if (capturador.isOpened())
    {
        for(;;)
        {
            capturador >> frame;
            keypoints_1=Detector.DetectorBRISK(frame);
            //keypoints_1=Detector.DetectorSIFT2(frame);
            //Detector.DetectorSURF(capturador);
            //-- Draw keypoints
            //capturador >> frame;
            if (frame.empty())
            {
                break;
            }
            cvtColor(frame,img_1,CV_BGR2GRAY);
            //Player.Play_VideoCapture(cap,"Imagen");
            imshow("Imagen en BN",frame);
            drawKeypoints( img_1, keypoints_1, img_keypoints_1, cv::Scalar::all(-1), cv::DrawMatchesFlags::DEFAULT );
            //-- Show detected (drawn) keypoints
            imshow("Keypoints 1", img_keypoints_1 );
             if(cv::waitKey(30) >= 0) break;
        }
    }
}
