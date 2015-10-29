#include "vector.h"
#include "iostream"
#include <cmath>
using namespace std;
Vector::Vector():x(0),y(0),z(0)
{}


Vector::Vector(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector::~Vector()
{
    cout << "我被调用了" << endl;
}

/**
 * @brief Vector::initialization
 * Initialization this vector
 */
void Vector::initialization()
{
    x = y = z = 0;
}

/**
 * @brief Vector::changeNegative
 * This methods will make the vector changeing Negative
 */
void Vector::changeNegative()
{
    x = -x;
    y = -y;
    z = -z;
}

/**
 * @brief Vector::distanceCalculation
 * @param isDrection ture(a -> b +) or false (b -> a -)  a== curren Vector  b == param Vector
 * @param
 * @return Two vector distance
 */
float Vector::distanceCalculation(bool isDirection, Vector &v)
{
    float directionLength;
    Vector directionVection;
    if(isDirection)
    {
        directionVection = *this + v;
        directionLength = getVectorLength(directionVection);
    }
    if(!isDirection)
    {
        directionVection = *this - v;
        directionLength = getVectorLength(directionVection);
    }
    return directionLength;
}

Vector Vector::operator *(float scalar)
{
    float x = this->x * scalar;
    float y = this->y * scalar;
    float z = this->z * scalar;
    Vector v(x, y, z);
    return v;
}

float Vector::operator *(Vector &v)
{
    return this->x * v.x + this->y * v.y + this->z * v.z;
}

Vector Vector::operator /(float scalar)
{
    float modulus = 1.0f / scalar;
    float x = this->x * modulus;
    float y = this->y * modulus;
    float z = this->z * modulus;
    Vector v(x, y, z);
    return v;
}

/**
 * @brief Vector::operator -
 * @param v
 * @return param Vector arrive curren vector  （b -> a）
 */
Vector Vector::operator -(Vector &v)
{
   float x = this->x - v.x;
   float y = this->y - v.y;
   float z = this->z - v.z;
   Vector rv(x, y, z);
   return rv;
}

/**
 * @brief Vector::operator +
 * @param v
 * @return curren vector arrive param (a -> b)
 */
Vector Vector::operator +(Vector &v)
{
    float x = this->x + v.x;
    float y = this->y + v.y;
    float z = this->z + v.z;
    Vector rv(x, y, z);
    return rv;
}

/**
 * @brief printVector
 * @param Need to pint the vector
 */
void printVector(Vector &v)
{
    cout << "[ " << v.x << "," << v.y << ","  << v.z << "]" << endl;
}

/**
 * @brief getVectorLength
 * @param Want calculate length is vector
 * @return vector  length
 */
float getVectorLength(Vector &v)
{
    if(v.x == 0 && v.y == 0 && v.z == 0) return 0;
    float length = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
    return length;
}

/**
 * @brief standardizeVector
 * @param Will this  vector standardize
 * @return standardize vector
 * formula
 *      v
 * v = -----
 *     ||v||
 */
Vector standardizeVector(Vector &v)
{
    float length = getVectorLength(v);
    float x = v.x / length;
    float y = v.y / length;
    float z = v.z / length;
    Vector rv(x, y, z);
    return rv;
}

/**
 * @brief getAngle
 * @return double Vector angle
 *               a .b
 * thea = arcos -------------
 *               ||a|| ||b||
 */
float getAngle(Vector &v1, Vector &v2)
{
    float v1Leng = getVectorLength(v1);
    float v2Leng = getVectorLength(v2);
    float result = v1 * v2;
    float thea = acos(result / (v1Leng * v2Leng)) * 180 / 3.1415926;
    return thea;
}

Vector getMultiplication(Vector &v1, Vector &v2)
{
    float x = v1.y * v2.z - v1.z * v2.y;
    float y = v1.z * v2.x - v1.x * v2.z;
    float z = v1.x * v2.y - v1.y * v2.x;
    Vector rv(x, y, z);
    return rv;
}
