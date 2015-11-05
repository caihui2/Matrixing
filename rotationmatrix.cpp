#include "rotationmatrix.h"
#include "vector.h"
#include "matrix4x3.h"

RotationMatrix::RotationMatrix()
{}

Vector RotationMatrix::IntertiaToObject(Vector &v, int direction, float theta)
{
    Matrix4X3 m;m.setRotationMatrix(direction,theta);
    Vector rv = m * v;
    mCurrentMatrix = m;
    return rv;
}

Vector RotationMatrix::ObjectToIntertia(Vector &v)
{
    Matrix4X3 rm = transpose(mCurrentMatrix);
    Vector rv = rm * v;
    return rv;
}
