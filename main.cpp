#include <iostream>
#include "vector.h"
#include "matrix3x3.h"
using namespace std;

int main()
{
    Matrix3X3 m(1.0f,2.0f,3.0f,4.0f,5.0f,6.0f,7.0f,8.0f,9.0f);
    Matrix3X3 s = transpose(m);
    printlnMatix(s);
    printlnMatix(m);
    return 0;
}

