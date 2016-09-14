//
//  Matrix3x3.hpp
//  Matrixing
//
//  Created by caihui yang on 16/9/14.
//  Copyright © 2016年 caihui yang. All rights reserved.
//

#ifndef Matrix3x3_hpp
#define Matrix3x3_hpp

#include <stdio.h>
#include <iostream>
#include "Vector3.hpp"

class Matrix3x3
{
public:
    float m11, m12, m13;
    float m21, m22, m23;
    float m31, m32, m33;
};

//矩阵的乘法 矩阵和矩阵
Matrix3x3  operator *(const Matrix3x3 &a, const Matrix3x3 &b);
//向量和矩阵
Vector3 operator *(const Vector3 &p, const Matrix3x3 &m);

#endif /* Matrix3x3_hpp */
