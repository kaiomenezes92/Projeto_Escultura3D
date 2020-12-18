#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>

class Plotter : public QWidget
{
    Q_OBJECT
private:
    int nx,ny,nz,coodX,coodY,coodZ,r,g,b,
    raioEsfera,
    rxElipse,ryElipse,rzElipse,
    dxCubo,dyCubo,dzCubo,selectedMetodo;
public:

    explicit Plotter(QWidget *parent = nullptr);

    Plotter();

    ~Plotter();

    Plotter(int _nx,int _ny,int _nz);

    void paintEvent(QPaintEvent *event);

    void mousePressEvent(QMouseEvent *event);

    void mouseMoveEvent(QMouseEvent *event);

signals:


      void emitResetRed(int _r);

      void emitResetBlue(int _b);

      void emitResetGreen(int _g);

      void emitResetProfundidade(int _f);

      void emitCursorX(int _x);

      void emitCursorY(int _y);

      void emitCursorZ(int _z);

public slots:

    void setDimXYZ(int _nx,int _ny,int _nz);

    void deleteMatrix();

    void setColors(int r,int g,int b);

    void setCoodenadaZ(int _z);

    void saveFigure();

    void setPutVoxel();

    void setCutVoxel();

    void setPutBox();

    void setCutBox();

    void setPutSphere();

    void setCutSphere();

    void setPutEllipsoid();

    void setCutEllipsoid();

    void setRaioEsfera(int _r);

    void setRaioXElipse(int _x);

    void setRaioYElipse(int _y);

    void setRaioZElipse(int _z);

    void setDimXCubo(int _x);

    void setDimYCubo(int _y);

    void setDimZCubo(int _z);

    void setMetodos();

};

#endif // PLOTTER_H
