#include <iostream>
#include "Vector2d.h"
#include "quadtre.h"

using namespace std;

int main()
{
    //Lager quadtreet
    Vector2d a{0, 0};
    Vector2d b{16, 0};
    Vector2d c{16, 16};
    Vector2d d{0, 16};
    QuadTre rot{a,b,c,d};

    //Subdividerer
    rot.subDivide(2);

    //Printer ut bladene
    rot.printLeaf();

    return 0;
}















