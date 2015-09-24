#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <ocv.h>

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

void MainWindow::on_OpenFileButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
            tr("Open Video"), "/home/ercmos", tr("Video Files (*.avi *.mpg *.mp4 *.*)"));

    ui->OpenFilelabel->setText(fileName);

    OCV Manejador_OCV;
    cv::VideoCapture cap=Manejador_OCV.OpenVideoFile(fileName.toStdString());
    Manejador_OCV.Play_VideoCapture(cap,"Frames");
}

void MainWindow::on_WebCamButton_clicked()
{
    ui->OpenFilelabel->setText("Web Cam");

    OCV Manejador_OCV;
    cv::VideoCapture cap=Manejador_OCV.OpenVideoFile(0);
    Manejador_OCV.Play_VideoCapture(cap,"Frames");
}

void MainWindow::on_SequenceButton_clicked()
{
    QString fullName = QFileDialog::getOpenFileName(this,
            tr("Open Video"), "/home/ercmos", tr("Video Files (*.avi *.mpg *.mp4 *.*)"));

    QString dirName = QFileInfo(fullName).absolutePath();
    QString fileName=QFileInfo(fullName).fileName();

    ui->OpenFilelabel->setText(dirName);

    OCV Manejador_OCV;
    cv::VideoCapture cap=Manejador_OCV.OpenVideoFile(dirName.toStdString(), fileName.toStdString());
    Manejador_OCV.Play_VideoCapture(cap,"Frames");
/*
    OCV AbreFichero;

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
