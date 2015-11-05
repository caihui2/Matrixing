#ifndef ROTATIONMATRIX_H
#define ROTATIONMATRIX_H
#include "vector.h"
#include "matrix4x3.h"
class RotationMatrix
{
public:
    Matrix4X3 mCurrentMatrix;
    RotationMatrix();
    Vector IntertiaToObject(Vector &v , int direction, float theta);
    Vector ObjectToIntertia(Vector &v);

};

#endif // ROTATIONMATRIX_H
