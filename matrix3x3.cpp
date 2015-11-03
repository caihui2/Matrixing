#include "matrix3x3.h"
#include <iostream>
#include <cmath>
using namespace std;
const int X_ROTATION = 1;
const int Y_ROTATION = 2;
const int Z_ROTATION = 3;

const int XY_PROJECTION = 4;
const int XZ_PROJECTION = 5;
const int YZ_PROJECTION = 6;

const int X_MIRROR = 7;
const int Y_MIRROR = 8;
const int Z_MIRROR = 9;

const int XY_SHEAR = 10;
const int XZ_SHEAR = 11;
const int YZ_SHEAR = 12;

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
       m11 = cos; m12= sin; m13 = 0;
       m21 = -sin; m22=cos; m23 = 0;
       m31 = 0;    m32 = 0; m33 = 1;
       break;
   }
}

/**
 * @brief Matrix3X3::setScale
 * @param v scale vector
 * formula
 * [x  0  0]
 * [0  y  0]
 * [0  0  z]
 */
void Matrix3X3::setScale(Vector &v)
{
    m11 = v.x; m12 = 0; m13 = 0;
    m21 = 0;  m22 = v.y; m23 = 0;
    m31 = 0;  m32 = 0;   m33 = v.z;
}

/**
 * @brief Matrix3X3::setNormalProjection
 * @param projectionMode
 */
void Matrix3X3::setNormalProjection(int projectionMode)
{
    switch (projectionMode) {
    case XY_PROJECTION:
       m11 = 1; m12 = 0; m13 = 0;
       m21 = 0; m22 = 1; m23 = 0;
       m31 = 0; m32 = 0;  m33= 0;
        break;
    case XZ_PROJECTION:
       m11 = 1; m12 = 0; m13 = 0;
       m21 =0;  m22 = 0; m23 = 0;
       m31 = 0; m32 = 0; m33 = 1;
        break;
    case YZ_PROJECTION:
       m11 = 0; m12 = 0;  m13 = 0;
       m21 = 0; m22 = 1;  m23 = 0;
       m31 = 0; m32 = 0; m33 = 1;
        break;
    }
}



/**
 * @brief Matrix3X3::setMirror
 * @param mirrorMode
 */
void Matrix3X3::setMirror(int mirrorMode)
{
    switch (mirrorMode) {
    case X_MIRROR:
       m11 = -1; m12 = 0; m13 = 0;
       m21 = 0;  m22 = 1; m23 = 0;
       m31 = 0;  m32 = 0; m33 = 1;
        break;
    case Y_MIRROR:
        m11 = 1; m12 = 0; m13 = 0;
        m21 = 0; m22 =-1;  m23 = 0;
        m31 =0;  m32 = 0;  m33 = 1;
        break;
    case Z_MIRROR:
        m11 = 1; m12 = 0; m13 = 0;
        m21 = 0; m22 =1;  m23 = 0;
        m31 =0;  m32 = 0;  m33 = -1;
        break;
    }
}

void Matrix3X3::setShear(int shearMode, float s, float t)
{
    switch (shearMode) {
    case XY_SHEAR:
        m11 = 1; m12 =0; m13 = 0;
        m21 = 0; m22 = 1; m23 = 0;
        m31 = s; m32 = t;  m33 = 1;
    case XZ_SHEAR:
        m11 = 1; m12 =0; m13 = 0;
        m21 = s; m22 = 1; m23 = t;
        m31 = 0; m32 = 0;  m33 = 1;
      break;
    case YZ_SHEAR:
        m11 = 1; m12 =s; m13 = t;
        m21 = 0; m22 = 1; m23 = 0;
        m31 = 0; m32 = 0;  m33 = 1;
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

void calculateSinCos(float *sins, float *coss, float theta)
{
    *sins = sin(theta);
    *coss = cos(theta);
}

float getDeterminant(Matrix3X3 &m)
{
    float determinant = m.m11 * m.m22 * m.m33 + m.m12 * m.m23 * m.m31 + m.m13 * m.m21 * m.m32
            - m.m13 * m.m22 * m.m31 - m.m12 * m.m21 * m.m33 - m.m11 * m.m23 * m.m32;
    return determinant;
}

/**
 * @brief getInverse
 * @param m
 * @return
 */
Matrix3X3 getInverse(Matrix3X3 &m)
{
    float deter = 1.0 / getDeterminant(m);
    float m11 = (m.m22 * m.m33 - m.m23 * m.m32) * deter;
    float m12 = (m.m23 * m.m31 - m.m21 * m.m33) * deter;
    float m13 = (m.m21 * m.m32 - m.m23 * m.m31) * deter;
    float m21 = (m.m13 * m.m32 - m.m12 * m.m33) * deter;
    float m22 = (m.m11 * m.m33 - m.m13 * m.m31) * deter;
    float m23 = (m.m12 * m.m31 - m.m11 * m.m32) * deter;
    float m31 = (m.m12 * m.m23 - m.m13 * m.m22) * deter;
    float m32 = (m.m13 * m.m21-  m.m11 * m.m23) * deter;
    float m33 = (m.m11 * m.m22 - m.m12 * m.m21) * deter;
    Matrix3X3 rm(m11,m21,m31,m12,m22,m32,m13,m23,m33);
    return rm;
}
