//
//  main.cpp
//  Matrixing
//
//  Created by caihui yang on 16/9/9.
//  Copyright © 2016年 caihui yang. All rights reserved.
//

#include <iostream>
#include "Vector3.hpp"

using namespace std;

void print_v(Vector3 v) {
    cout << "[" << v.x << " , " << v.y << " , " << v.z << " ]" << endl;
}

int main(int argc, const char * argv[]) {
    Vector3 v1(10,20,30);
    print_v(v1);
    Vector3 v2(v1);
    print_v(v2);
    
    Vector3 v3 = -v1;
    print_v(v3);
    v2.zero();
    print_v(v2);
    
    Vector3 v4(5, -4 , 7);
    float r = vectorMag(v4);
    cout << "向量的长度:" << r << endl;
    
    Vector3 v5 (-5, 0, 0.4);
    Vector3 v6 = v5 * -3;
    print_v(v6);
    
    
    Vector3 v11(12, -5, 0);
    v11.normalize();
    print_v(v11);
    
    
    Vector3 x(5, 0 , 0);
    Vector3 y(-1, 8, 0);
    float  d = distance(x, y);
    cout << d<< endl;
        return 0;
}
