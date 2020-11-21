#include <iostream>
#include <fstream>
#include "sculptor.h"
#include <cstdlib>
#include <string>
#include <cmath>

using namespace std;

Sculptor::Sculptor(int _nx, int _ny, int _nz){

    nx = _nx;
    ny = _ny;
    nz = _nz;

    v = new Voxel**[nx];

    for(int i = 0; i < nx; i++){

        v[i] = new Voxel*[ny];

        for(int j = 0; j < ny; j++){

            v[i][j] = new Voxel[nz];

        }
    }

    cout << "construtor" << endl;

}

Sculptor::~Sculptor(){

    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){

            delete[] v[i][j];

        }

        delete[] v[i];

    }

    delete[] v;
    cout << "desconstrutor" << endl;
}

void Sculptor::setColor(float _r, float _g, float _b, float alpha){

    r = _r;
    g = _g;
    b = _b;
    a = alpha;

}

void Sculptor::putVoxel(int x, int y, int z){

    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;
    v[x][y][z].isOn = true;

}

void Sculptor::cutVoxel(int x, int y, int z){

    v[x][y][z].isOn = false;
}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){

    for(int x = x0; x < x1; x++){
        for(int y = y0; y < y1; y++){
            for(int z = z0; z < z1; z++){

                v[x][y][z].r = r;
                v[x][y][z].g = g;
                v[x][y][z].b = b;
                v[x][y][z].a = a;
                v[x][y][z].isOn = true;

            }
        }
    }
}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){

    for(int x = x0; x < x1; x++){
        for(int y = y0; y < y1; y++){
            for(int z = z0; z < z1; z++){

                v[x][y][z].isOn = false;

            }
        }
    }
}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){

    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){

                int eqEsfera = pow((i - xcenter), 2) + pow((j - ycenter), 2) + pow((k - zcenter), 2);

                if(eqEsfera <= pow(radius, 2)){

                    v[i][j][k].r = r;
                    v[i][j][k].g = g;
                    v[i][j][k].b = b;
                    v[i][j][k].a = a;
                    v[i][j][k].isOn = true;

                }
            }
        }
    }
}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){

    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){

                int eqEsfera = pow((i - xcenter), 2) + pow((j - ycenter), 2) + pow((k - zcenter), 2);

                if(eqEsfera <= pow(radius, 2)){

                    v[i][j][k].isOn = false;

                }
            }
        }
    }
}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){

    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){

                int eqElipsoide = pow((i - xcenter), 2)/pow(rx, 2) + pow((j - ycenter), 2)/pow(ry, 2) + pow((k - zcenter), 2)/pow(rz, 2);

                if(eqElipsoide <= 1){

                    v[i][j][k].r = r;
                    v[i][j][k].g = g;
                    v[i][j][k].b = b;
                    v[i][j][k].a = a;
                    v[i][j][k].isOn = true;

                }
            }
        }
    }
}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){

    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){

                int eqElipsoide = pow((i - xcenter), 2)/pow(rx, 2) + pow((j - ycenter), 2)/pow(ry, 2) + pow((k - zcenter), 2)/pow(rz, 2);

                if(eqElipsoide <= 1){

                    v[i][j][k].isOn = false;

                }
            }
        }
    }
}

void Sculptor :: writeOFF(char *filename){

    int _f = 0;
    int _v = 0;
    int total = 0;

    ofstream fout;
    fout.open(filename);

    if(!fout.is_open()){
        exit(1);
    }

    fout << "OFF" << endl;

    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){

                if(v[i][j][k].isOn){

                    _v++;

                }
            }
        }
    }

    fout << _v*8 << " " << _v*6 << " " << 0 <<endl;

    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){

                if(v[i][j][k].isOn){

                    fout << i - 0.5 << " " << j + 0.5 << " " << k - 0.5 << endl;
                    fout << i - 0.5 << " " << j - 0.5 << " " << k - 0.5 << endl;
                    fout << i + 0.5 << " " << j - 0.5 << " " << k - 0.5 << endl;
                    fout << i + 0.5 << " " << j + 0.5 << " " << k - 0.5 << endl;
                    fout << i - 0.5 << " " << j + 0.5 << " " << k + 0.5 << endl;
                    fout << i - 0.5 << " " << j - 0.5 << " " << k + 0.5 << endl;
                    fout << i + 0.5 << " " << j - 0.5 << " " << k + 0.5 << endl;
                    fout << i + 0.5 << " " << j + 0.5 << " " << k + 0.5 << endl;

                }
            }
        }
    }

    fout.precision(2);

    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){

                if(v[i][j][k].isOn){

                    _f = total*8;

                    fout << 4 << " " << _f+0 << " " << _f+3 << " " << _f+2 << " " << _f+1 << " " << fixed << v[i][j][k].r << " " << fixed << v[i][j][k].g << " " << fixed << v[i][j][k].b << " " << fixed << v[i][j][k].a << endl;
                    fout << 4 << " " << _f+4 << " " << _f+7 << " " << _f+3 << " " << _f+0 << " " << fixed << v[i][j][k].r << " " << fixed << v[i][j][k].g << " " << fixed << v[i][j][k].b << " " << fixed << v[i][j][k].a << endl;
                    fout << 4 << " " << _f+5 << " " << _f+6 << " " << _f+7 << " " << _f+4 << " " << fixed << v[i][j][k].r << " " << fixed << v[i][j][k].g << " " << fixed << v[i][j][k].b << " " << fixed << v[i][j][k].a << endl;
                    fout << 4 << " " << _f+6 << " " << _f+2 << " " << _f+3 << " " << _f+7 << " " << fixed << v[i][j][k].r << " " << fixed << v[i][j][k].g << " " << fixed << v[i][j][k].b << " " << fixed << v[i][j][k].a << endl;
                    fout << 4 << " " << _f+5 << " " << _f+1 << " " << _f+2 << " " << _f+6 << " " << fixed << v[i][j][k].r << " " << fixed << v[i][j][k].g << " " << fixed << v[i][j][k].b << " " << fixed << v[i][j][k].a << endl;
                    fout << 4 << " " << _f+5 << " " << _f+4 << " " << _f+0 << " " << _f+1 << " " << fixed << v[i][j][k].r << " " << fixed << v[i][j][k].g << " " << fixed << v[i][j][k].b << " " << fixed << v[i][j][k].a << endl;
                    total++;
                }
            }
        }
    }

    cout<< "Arquivo salvo!" << endl;
    fout.close();
}
