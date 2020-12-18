#ifndef SELECTEDCOLORS_H
#define SELECTEDCOLORS_H

#include <QWidget>


class SelectedColors : public QWidget
{
    Q_OBJECT
private:
    int r,g,b;
public:

    explicit SelectedColors(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *event);

signals:

    void emitSelectedColors(int _r,int _g,int _b);

public slots:

    void setRed(int _r);

    void setBlue(int _b);

    void setGreen(int _g);

};

#endif // SELECTEDCOLORS_H
