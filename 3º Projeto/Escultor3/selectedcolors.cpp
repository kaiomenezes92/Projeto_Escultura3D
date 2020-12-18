#include "selectedcolors.h"
#include <QPainter>
#include <QBrush>
#include <QPen>

SelectedColors::SelectedColors(QWidget *parent) : QWidget(parent)
{
    r=0;
    b=0;
    g=0;
}
void SelectedColors::paintEvent(QPaintEvent *event){

    QPainter painter(this);
    QBrush brush;

    brush.setColor(QColor(r,g,b));
    brush.setStyle(Qt::SolidPattern);

    painter.setBrush(brush);

    painter.drawRect(0,0,width(),height());
}

void SelectedColors::setRed(int _r){
    r=_r;
    emit emitSelectedColors(r,g,b);
    repaint();
}

void SelectedColors::setBlue(int _b){
    b=_b;
    emit emitSelectedColors(r,g,b);
    repaint();

}

void SelectedColors::setGreen(int _g){
    g=_g;
    emit emitSelectedColors(r,g,b);
    repaint();
}
