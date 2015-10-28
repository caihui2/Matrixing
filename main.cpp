#include <iostream>
#include "vector.h"
using namespace std;

int main()
{
    Vector mVector(5, 0, 0);
    Vector mVector2(-1, 8, 0);
   float length = mVector.distanceCalculation(false,mVector2);
    cout << "length:" << length << endl;
    return 0;
}

