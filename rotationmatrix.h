#ifndef ROTATIONMATRIX_H
#define ROTATIONMATRIX_H
#include "vector.h"
#include "matrix4x3.h"
#include "eulerangles.h"

extern const int X_ROTATION_MATRIX;
extern const int Y_ROTATION_MATRIX;
extern const int Z_ROTATION_MATRIX;
class RotationMatrix
{
public:
    float m11, m12, m13;
    float m21, m22, m23;
    float m31, m32, m33;
    RotationMatrix();
    RotationMatrix(float m11, float m12, float m13, float m21, float m22, float m23, float  m31, float m32, float m33);
    void identity();
    void setUpRotation(int RotationMode, float theta);
    void setUpEulerangles(EulerAngles &e);
    Vector IntertiaToObject(Vector &v);
    Vector ObjectToIntertia(Vector &v);

};
void printRotationMatrix(RotationMatrix &m);

#endif // ROTATIONMATRIX_H
