#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>

namespace Ui {
class MainWindow;
}
/**
 * @brief The MainWindow class Clase principal del Programa
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief MainWindow Constructor de la clase principal
     * @param parent De la ventana principal
     */
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_OpenFileButton_clicked();

    void on_WebCamButton_clicked();

    void on_SequenceButton_clicked();

    void on_DetectorButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
