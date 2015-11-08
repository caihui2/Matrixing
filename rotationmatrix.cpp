#include "rotationmatrix.h"
#include "vector.h"
#include "matrix4x3.h"
#include "iostream"
using namespace std;
const int  X_ROTATION_MATRIX = 1;
const int  Y_ROTATION_MATRIX = 2;
const int  Z_ROTATION_MATRIX = 3;

RotationMatrix::RotationMatrix()
{}

RotationMatrix::RotationMatrix(float m11, float m12, float m13, float m21, float m22, float m23, float m31, float m32, float m33)
{
    this->m11 = m11;
    this->m12 = m12;
    this->m13 = m13;
    this->m21 = m21;
    this->m23 = m23;
    this->m31 = m31;
    this->m32 = m32;
    this->m33 = m33;
}

void RotationMatrix::identity()
{
    m11 = 1; m12 = 0; m13 = 0;
    m21 = 0; m22 = 1; m23 = 0;
    m31 = 0; m32 = 0; m33 = 1;
}

void RotationMatrix::setUpRotation(int rotationMode, float theta)
{
    float cos, sin;
    calculateSinCos(&sin,&cos, theta);
    switch (rotationMode) {
    case X_ROTATION_MATRIX:
        m11 = 1; m12 = 0; m13 = 0;
        m21 = 0; m22 = cos; m23 = sin;
        m31 = 0; m32 = -sin; m33 = cos;
        break;
    case Y_ROTATION_MATRIX:
        m11 = cos; m12 = 0; m13 = -sin;
        m21 = 0;   m22 = 1; m23 = 0;
        m31 = sin; m32 = 0; m33 = cos;
        break;
    case Z_ROTATION_MATRIX:
        m11 = cos; m12 = sin; m13 = 0;
        m21 = -sin; m22 = cos; m23 = 0;
        m31 = 0; m32 = 0;  m33 = 1;
        break;
    }
}

Vector RotationMatrix::IntertiaToObject(Vector &v)
{
    float x = v.x * m11 + v.y * m21 + v.z * m31;
    float y = v.x * m12 + v.y * m22 + v.z * m23;
    float z = v.x * m13 + v.y * m23 + v.z * m33;
    return Vector(x, y, z);
}

Vector RotationMatrix::ObjectToIntertia(Vector &v)
{
    float x = v.x * m11 + v.y * m12 + v.z * m13;
    float y = v.x * m21 + v.y * m22 + v.z * m23;
    float z = v.x * m31 + v.y * m32 + v.z * m33;
    return Vector(x, y, z);
}

void printRotationMatrix(RotationMatrix &m)
{
    cout << "[" << m.m11 << "," << m.m12 << "," << m.m13 <<"]" << endl;
    cout << "[" << m.m21 << "," << m.m22 << "," << m.m23 <<"]" << endl;
    cout << "[" << m.m31 << "," << m.m32 << "," << m.m33 <<"]" << endl;
}
