#ifndef PUTBOX_H
#define PUTBOX_H

#include <figurageometrica.h>
#include "sculptor.h"

class PutBox : public FiguraGeometrica{
    int x0,y0,z0,x1,y1,z1;
public:

    PutBox(int x0, int x1, int y0, int y1, int z0, int z1, float r, float g, float b, float a);

    ~PutBox(){}

    void draw(Sculptor &s);
};

#endif // PUTBOX_H
