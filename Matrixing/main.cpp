//
//  main.cpp
//  Matrixing
//
//  Created by caihui yang on 16/9/9.
//  Copyright © 2016年 caihui yang. All rights reserved.
//

#include <iostream>
#include "Vector3.hpp"
#include "Matrix3x3.hpp"
#include "MatchUtil.hpp"

using namespace std;

void print_v(Vector3 v) {
    cout << "[" << v.x << " , " << v.y << " , " << v.z << " ]" << endl;
}

void print_M(Matrix3x3 &m) {
 
    cout << m.m11  << "\t" << m.m12 << "\t" << m.m13  << endl;
    cout << m.m21  << "\t" << m.m22 << "\t" << m.m23  << endl;
    cout << m.m31  << "\t" << m.m32 << "\t" << m.m33  << endl;

}

int main(int argc, const char * argv[]) {
//    Vector3 v1(10,20,30);
//    print_v(v1);
//    Vector3 v2(v1);
//    print_v(v2);
//    
//    Vector3 v3 = -v1;
//    print_v(v3);
//    v2.zero();
//    print_v(v2);
//    
//    Vector3 v4(5, -4 , 7);
//    float r = vectorMag(v4);
//    cout << "向量的长度:" << r << endl;
//    
//    Vector3 v5 (-5, 0, 0.4);
//    Vector3 v6 = v5 * -3;
//    print_v(v6);
//    
//    
//    Vector3 v11(12, -5, 0);
//    v11.normalize();
//    print_v(v11);
//    
//    
//    Vector3 x(5, 0 , 0);
//    Vector3 y(-1, 8, 0);
//    float  d = distance(x, y);
//    cout << d<< endl;
//    
//    
//    Vector3 h1(3, -2, 7);
//    Vector3 h2(0, 4, -1);
//    
//    //求角度
//    float dp = h1 * h2 ;
//    double arc =  acos( dp / (vectorMag(h1) * vectorMag(h2))) * 180 / 3.14159;
//    cout << arc << endl;
//    cout << dp << endl;
//    
//    //差乘
//    Vector3 t1(1,3,4);
//    Vector3 t2(2, -5, 8);
//    Vector3 cp = crossProduct(t1, t2);
//    print_v(cp);
    
    Matrix3x3 a, b, c;
    
    a.m11 = 1 ,   a.m12 =-5,  a.m13 = 3;
    a.m21 = 0,    a.m22 =-2, a.m23 = 6;
    a.m31 = 7,    a.m32 = 2,  a.m33 = -4;
    
    b.m11 = -8 ,   b.m12 = 6,  b.m13 = 1;
    b.m21 = 7,    b.m22 =  0, b.m23 =  -3;
    b.m31 = 2,    b.m32 = 4,  b.m33 =  5;
    
    c = a * b;
    
  //  print_M(c);
    
    
    Vector3 v(3, -1, 4);
    Matrix3x3 m;
    m.m11 = -2 ,   m.m12 =0,  m.m13 = 3;
    m.m21 = 5,    m.m22 = 7, m.m23 = -6;
    m.m31 = 1,    m.m32 = -4,  m.m33 = 2;
    
    Vector3 r = v * m;
    
  //  print_v(r);
    
    Vector3 as(10,0,0), bs;
    
    Matrix3x3 ms;
    ms.setRotate(3, kPiOver2);
    bs = as * ms;
    
    print_v(bs);
    
        return 0;
}
