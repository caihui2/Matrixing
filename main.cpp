#include <iostream>
#include "vector.h"
#include "matrix4x3.h"
#include "rotationmatrix.h"
using namespace std;

int main()
{
    RotationMatrix m;
    Vector x (10,23,23);
    Vector vs = m.IntertiaToObject(x,Y_ROTATION, 3.14159);
    printVector(vs);
    Vector c=  m.ObjectToIntertia(vs);
    printVector(c);
    return 0;
}

