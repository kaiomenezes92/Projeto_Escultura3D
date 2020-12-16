#ifndef SCULPTOR_H
#define SCULPTOR_H

#include "voxel.h"
#include <string>
#include <vector>

class Sculptor{

protected:
    Voxel ***v;

    int nx,ny,nz;
    float r,g,b,a;

public:

    Sculptor(int _nx, int _ny, int _nz);

    ~Sculptor();

     void setColor(float r, float g, float b, float alpha);

     void putVoxel(int x, int y, int z);

     void cutVoxel(int x, int y, int z);

     void writeOFF(char* filename);

     void errorInterval(void);

     int getMatX();

     int getMatY();

     int getMatZ();
};

#endif // SCULPTOR_H
