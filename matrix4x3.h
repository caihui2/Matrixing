#ifndef MATRIX4X3_H
#define MATRIX4X3_H
#include "vector.h"

extern const int X_ROTATION;
extern const int Y_ROTATION;
extern const int Z_ROTATION;

extern const int XY_PROJECTION;
extern const int XZ_PROJECTION;
extern const int YZ_PROJECTION;

extern const int X_MIRROR;
extern const int Y_MIRROR;
extern const int Z_MIRROR;

extern const int XY_SHEAR;
extern const int XZ_SHEAR;
extern const int YZ_SHEAR;
class Matrix3X3
{
public:
    float m11, m12, m13;
    float m21, m22, m23;
    float m31, m32, m33;
    float tx,  ty , tz;
    Matrix3X3();
    Matrix3X3(float m11, float m12, float m13, float m21, float m22, float m23, float m31, float m32, float m33);
    void setRotationMatrix(int direction, float theta);
    void setScale(Vector &v);
    void setNormalProjection(int projectionMode);
    void setMirror(int mirrorMode);
    void setShear(int shearMode, float s, float t);
    void setTranslation(Vector &v);

    //Overwrite operator
    Vector operator *(Vector &v);

};
  void printlnMatix(Matrix3X3 &m);
  Matrix3X3 transpose(Matrix3X3 &m);
  void calculateSinCos(float *sin, float *cos, float theta);
  float getDeterminant(Matrix3X3 &m);
  Matrix3X3 getInverse(Matrix3X3 &m);
#endif // MATRIX3X3_H
