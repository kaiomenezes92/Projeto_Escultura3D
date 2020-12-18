#ifndef JANELANEW_H
#define JANELANEW_H

#include <QDialog>

namespace Ui {
class JanelaNew;
}

class JanelaNew : public QDialog
{
    Q_OBJECT

public:

    explicit JanelaNew(QWidget *parent = nullptr);

    ~JanelaNew();

    int getDimX();

    int getDimY();

    int getDimZ();

private:
    Ui::JanelaNew *ui;
};

#endif // JANELANEW_H
