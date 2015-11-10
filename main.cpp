#include <iostream>
#include "vector.h"
#include "matrix4x3.h"
#include "rotationmatrix.h"
using namespace std;

int main()
{
    RotationMatrix m;
    Vector x (10, 20, 30);
    m.setUpRotation(Y_ROTATION_MATRIX, 3.1415926 / 180 * 90);
    Vector objectVector = m.IntertiaToObject(x);
    printVector(objectVector);
    Vector c=  m.ObjectToIntertia(objectVector);
    printVector(c);
    RotationMatrix rota;
    EulerAngles eu(0, 3.1415926 / 180 * 90, 0);
    rota.setUpEulerangles(eu);
    Vector Obj = m.IntertiaToObject(x);
    printVector(Obj);
    Vector in = m.ObjectToIntertia(Obj);
    printVector(in);
    return 0;
}

