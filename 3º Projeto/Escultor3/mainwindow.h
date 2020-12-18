#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

public slots:

    void openJanelaNew(void);

private slots:

    void on_pushButtonPutVoxel_clicked();

    void on_pushButtonCutVoxel_clicked();

    void on_pushButtonPutBox_clicked();

    void on_pushButtonCutBox_clicked();

    void on_pushButtonPutSphere_clicked();

    void on_pushButtonCutSphere_clicked();

    void on_pushButtonPutEllipsoid_clicked();

    void on_pushButtonCutEllipsoid_clicked();

    void closed();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
