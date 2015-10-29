#ifndef VECTOR_H
#define VECTOR_H


class Vector
{
public:
    float x, y ,z;
    Vector();
    Vector(float x, float y, float z);
    ~Vector();
    void initialization();
    void changeNegative();
    float distanceCalculation(bool isDirection, Vector &v);

    //Overwrite operator
    Vector operator *(float scalar);
    float operator *(Vector &v);
    Vector operator /(float scalar);
    Vector operator -(Vector &v);
    Vector operator +(Vector &v);
};

void printVector(Vector &v);
float getVectorLength(Vector &v);
Vector standardizeVector(Vector &v);
float getAngle(Vector &v1 , Vector &v2);
Vector getMultiplication(Vector &v1, Vector &v2);
#endif // VECTOR_H
