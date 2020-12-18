#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "janelanew.h"
#include "plotter.h"
#include <QPixmap>
#include <QMessageBox>

#include <QDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionNovo,SIGNAL(triggered(bool)),
            this,SLOT(openJanelaNew()));

    connect(ui->actionQuit,SIGNAL(triggered(bool)),
            this,SLOT(closed()));

   ui->containerMatriz->setDimXYZ(10,10,10);
   ui->horizontalSliderProfundidade->setMaximum(9);
   ui->horizontalSliderDXCubo->setMaximum(9);
   ui->horizontalSliderDYCubo->setMaximum(9);
   ui->horizontalSliderDZCubo->setMaximum(9);
   ui->horizontalSliderRXElipse->setMaximum(9);
   ui->horizontalSliderRYElipse->setMaximum(9);
   ui->horizontalSliderRZElipse->setMaximum(9);
   ui->horizontalSliderRaioEsfera->setMaximum(9);


}

MainWindow::~MainWindow()
{
    delete ui;
    ui->containerMatriz->deleteMatrix();

}

void MainWindow::openJanelaNew(){

    JanelaNew novo;

    if(novo.exec() == QDialog::Accepted){

        if(novo.getDimX()>0 && novo.getDimY() >0 && novo.getDimZ()>0){

               ui->containerMatriz->setDimXYZ(novo.getDimX(),novo.getDimY(), novo.getDimZ());
               ui->lcdNumberX->display(novo.getDimX());
               ui->lcdNumberY->display(novo.getDimY());
               ui->lcdNumberZ->display(novo.getDimZ());
               ui->horizontalSliderProfundidade->setMaximum(novo.getDimZ()-1);
               ui->horizontalSliderDXCubo->setMaximum(novo.getDimX());
               ui->horizontalSliderDYCubo->setMaximum(novo.getDimY());
               ui->horizontalSliderDZCubo->setMaximum(novo.getDimZ());
               ui->horizontalSliderRXElipse->setMaximum(novo.getDimX());
               ui->horizontalSliderRYElipse->setMaximum(novo.getDimY());
               ui->horizontalSliderRZElipse->setMaximum(novo.getDimZ());

               if(novo.getDimX() > novo.getDimY() && novo.getDimX() > novo.getDimZ()){
                    ui->horizontalSliderRaioEsfera->setMaximum(novo.getDimX()-1);
               }else if (novo.getDimY() > novo.getDimX() && novo.getDimY() > novo.getDimZ()) {
                    ui->horizontalSliderRaioEsfera->setMaximum(novo.getDimY()-1);
               }else if (novo.getDimZ() > novo.getDimX() && novo.getDimZ() > novo.getDimY()) {
                    ui->horizontalSliderRaioEsfera->setMaximum(novo.getDimZ()-1);
               }else {
                     ui->horizontalSliderRaioEsfera->setMaximum(novo.getDimX()-1);
                }
          }else {

            QMessageBox::warning(this,"Error","Error!");

           }


     }

}

void MainWindow::on_pushButtonPutVoxel_clicked()
{

}

void MainWindow::on_pushButtonCutVoxel_clicked()
{

}

void MainWindow::on_pushButtonPutBox_clicked()
{

}

void MainWindow::on_pushButtonCutBox_clicked()
{

}

void MainWindow::on_pushButtonPutSphere_clicked()
{

}

void MainWindow::on_pushButtonCutSphere_clicked()
{

}

void MainWindow::on_pushButtonPutEllipsoid_clicked()
{

}

void MainWindow::on_pushButtonCutEllipsoid_clicked()
{

}

void MainWindow::closed(){

   if(QMessageBox::question(this,"Quit","Are you sure?") == QMessageBox::Yes){
         close();
   }


}
