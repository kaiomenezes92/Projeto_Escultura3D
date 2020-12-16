#include <iostream>
#include "figurageometrica.h"
#include "interpretador.h"
#include "putvoxel.h"
#include "cutvoxel.h"
#include "putbox.h"
#include "cutbox.h"
#include "putsphere.h"
#include "cutsphere.h"
#include "putellipsoid.h"
#include "cutellipsoid.h"
#include "sculptor.h"

using namespace std;

int main()
{
    Sculptor *s1;

    vector<FiguraGeometrica*> figs;

    Interpretador parser;

    figs = parser.parse("teste.txt");

    s1 = new Sculptor(parser.getDimx(),parser.getDimy(),parser.getDimz());

    for(size_t i=0; i<figs.size();i++){

        figs[i] ->draw(*s1);
    }

    s1 ->writeOFF((char*)"figura.off");

    for(size_t i=0; i<figs.size();i++){

        delete figs[i];
    }

    delete s1;

    cout << "Programa Finalizado!" << endl;
    return 0;
}
