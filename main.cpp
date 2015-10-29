#include <iostream>
#include "vector.h"
using namespace std;

int main()
{
    Vector mVector(1, 3, 4);
    Vector mVector2(2, -5, 8);
    Vector rv =  getMultiplication(mVector, mVector2);
    printVector(rv);
   // cout << "length:" << angle << endl;
    return 0;
}

