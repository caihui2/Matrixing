#include <iostream>
#include "vector.h"
#include "matrix3x3.h"
using namespace std;

int main()
{
    Matrix3X3 m(3, -2, 0, 1, 4, -3, -1, 0, 2);
   float re =  getDeterminant(m);
   cout << re << endl;
    return 0;
}

