#include "matrix3x3.h"
#include <iostream>
#include <cmath>
using namespace std;
const int X_ROTATION = 1;
const int Y_ROTATION = 2;
const int Z_ROTATION = 3;

Matrix3X3::Matrix3X3():m11(0),m12(0),m13(0),m21(0),m22(0),m23(0),m31(0),m32(0),m33(0)
{
}

Matrix3X3::Matrix3X3(float m11, float m12, float m13, float m21, float m22, float m23, float m31, float m32, float m33)
{
    this->m11 = m11;
    this->m12 = m12;
    this->m13 = m13;
    this->m21 = m21;
    this->m22 = m22;
    this->m23 = m23;
    this->m31 = m31;
    this->m32 = m32;
    this->m33 = m33;
}

/**
 * @brief Matrix3X3::setRotationMatrix
 * @param direction select rotation drection (X_ROTATION, Y_ROTATION,Z_ROTATION)
 * @param theta rotation angle
 *
 *X_ROTATION formula
 * [ 1,   0   ,   0   ]
 * [ 0, cosθ  ,  sinθ ]
 * [ 0, -sinθ ,  cosθ ]
 *
 *Y_ROTATION  formula
 * [cosθ, 0 ,  -sinθ  ]
 * [ 0  , 1 ,     0   ]
 * [ sinθ，0,   cosθ  ]
 *Z_ROTATION formula
 * [cosθ, sinθ,   0   ]
 * [-sinθ，cosθ,  0   ]
 * [  0   ,  0 ,  1   ]
 *
 *
 */
void Matrix3X3::setRotationMatrix(int direction, float theta)
{
   float sin , cos;
   calculateSinCos(&sin, &cos, theta);
   switch (direction) {
   case X_ROTATION:
       m11 = 1; m12 = 0; m13 = 0;
       m21 = 0; m22 = cos; m23= sin;
       m31 = 0; m32 = -sin; m33 = cos;
       break;
   case Y_ROTATION:
       m11 = cos; m12 = 0; m13 = -sin;
       m21 = 0 ;  m22 = 1; m23 = 0;
       m31 = sin; m32 = 0; m33 = cos;
       break;
   case Z_ROTATION:
       break;
   }
}

Vector Matrix3X3::operator *(Vector &v)
{
    float x = v.x * m11 + v.y * m21 + v.z * m31;
    float y = v.x * m12 + v.y * m22 + v.z * m32;
    float z = v.x * m13 + v.y * m23 + v.z * m33;
    Vector rv(x, y, z);
    return rv;
}


void printlnMatix(Matrix3X3 &m)
{
    cout << "[" << m.m11 << "," << m.m12 << "," << m.m13 <<"]" << endl;
    cout << "[" << m.m21 << "," << m.m22 << "," << m.m23 <<"]" << endl;
    cout << "[" << m.m31 << "," << m.m32 << "," << m.m33 <<"]" << endl;
}


/**
 * @brief Matrix3X3::transpose
 *
 *               [x]
 *  [x , y, z]t =[y]
 *               [z]
 */
Matrix3X3 transpose(Matrix3X3 &m)
{
    float m11 = m.m11;
    float m12 = m.m21;
    float m13 = m.m31;
    float m21 = m.m12;
    float m22 = m.m22;
    float m23 = m.m32;
    float m31 = m.m13;
    float m32 = m.m23;
    float m33 = m.m33;
    Matrix3X3 matrix(m11,m12,m13,m21,m22,m23,m31,m32,m33);
    return matrix;
}

void calculateSinCos(float *sin, float *cos, float theta)
{
    *sin = sin(theta);
    *cos = cos(theta);
}
