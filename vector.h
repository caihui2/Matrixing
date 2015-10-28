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
    Vector operator /(float scalar);
    Vector operator -(Vector &v);
    Vector operator +(Vector &v);
};

void printVector(Vector &v);
float getVectorLength(Vector &v);
Vector standardizeVector(Vector &v);
#endif // VECTOR_H
