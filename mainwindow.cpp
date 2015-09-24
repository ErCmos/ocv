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
    OCV AbreFichero;
    cv::VideoCapture cap=AbreFichero.OpenVideoFile(fileName.toStdString());
    if( cap.isOpened() )
    {
        ui->OpenFilelabel->setText(fileName);
        cv::Mat frame, ret, prvs;
        for (;;)
        {
            cap >> frame;
            if (frame.empty())
                break;
            imshow("Frames",frame);
            if(cv::waitKey(30) >= 0) break;
        }
    }
}

void MainWindow::on_WebCamButton_clicked()
{
    OCV AbreFichero;
    cv::VideoCapture cap=AbreFichero.OpenVideoFile(0);
    if( cap.isOpened() )
    {
        ui->OpenFilelabel->setText("Web Cam");
        cv::Mat frame, ret, prvs;
        while (1)
        {
            cap >> frame;
            imshow("Frames",frame);
            if(cv::waitKey(30) >= 0) break;
        }
    }
}

void MainWindow::on_SequenceButton_clicked()
{
    QString fullName = QFileDialog::getOpenFileName(this,
            tr("Open Video"), "/home/ercmos", tr("Video Files (*.avi *.mpg *.mp4 *.*)"));

    QString dirName = QFileInfo(fullName).absolutePath();
    QString fileName=QFileInfo(fullName).fileName();

    ui->OpenFilelabel->setText(dirName);

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
            /* + convert.str()*/
            imshow("Frame ",frame);
            if(cv::waitKey(30) >= 0) break;
        }
    }
}
