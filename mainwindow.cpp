#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <ocv_capturer.h>
#include <ocv_player.h>
#include <ocv_descriptor.h>

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
cv::VideoCapture cap;

void MainWindow::on_OpenFileButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
            tr("Open Video"), "/home/ercmos", tr("Video Files (*.avi *.mpg *.mp4 *.*)"));

    ui->OpenFilelabel->setText(fileName);

    //OCV_Capturer Capturer;
    //cv::VideoCapture cap=Capturer.OpenVideoFile(fileName.toStdString());
    cap=Capturer.OpenVideoFile(fileName.toStdString());
    OCV_Player Player;
    Player.Play_VideoCapture(cap,"Frames");
}

void MainWindow::on_WebCamButton_clicked()
{
    ui->OpenFilelabel->setText("Web Cam");

    //OCV_Capturer Capturer;
    //cv::VideoCapture cap=Capturer.OpenVideoFile(0);
    cap=Capturer.OpenVideoFile(0);
    OCV_Player Player;
    Player.Play_VideoCapture(cap,"Frames");
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
    cap=Capturer.OpenVideoFile(dirName.toStdString(), fileName.toStdString());
    OCV_Player Player;
    Player.Play_VideoCapture(cap,"Frames");
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
    cap=Capturer.OpenVideoFile(fileName.toStdString());
    OCV_Descriptor Detector;
    Detector.Detector(cap);
}
