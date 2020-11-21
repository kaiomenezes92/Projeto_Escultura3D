#include <iostream>
#include "sculptor.h"

using namespace std;

int main()
{

    Sculptor f(30,30,30);
    f.setColor(0,1,0,1);
    f.putSphere(15,15,15,10);
    f.cutBox(5,25,5,25,20,25);
    f.setColor(1,1,1,1);
    f.putSphere(15,15,15,9);
    f.cutBox(6,24,6,24,20,25);
    f.setColor(0,0,1,1);
    f.putBox(15,16,15,16,15,30);
    f.writeOFF((char*)"coco2.off");

    return 0;
}
