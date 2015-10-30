#ifndef MATRIX3X3_H
#define MATRIX3X3_H
#include "vector.h"

extern const int X_ROTATION;
extern const int Y_ROTATION;
extern const int Z_ROTATION;
class Matrix3X3
{
public:
    float m11, m12, m13;
    float m21, m22, m23;
    float m31, m32, m33;
    Matrix3X3();
    Matrix3X3(float m11, float m12, float m13, float m21, float m22, float m23, float m31, float m32, float m33);
    void setRotationMatrix(int direction, float theta);


    //Overwrite operator
    Vector operator *(Vector &v);

};
  void printlnMatix(Matrix3X3 &m);
  Matrix3X3 transpose(Matrix3X3 &m);
  void calculateSinCos(float *sin, float *cos, float theta);
#endif // MATRIX3X3_H
