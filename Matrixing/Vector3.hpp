//
//  Vector3.hpp
//  Matrixing
//
//  Created by caihui yang on 16/9/10.
//  Copyright © 2016年 caihui yang. All rights reserved.
//3D向量

#ifndef Vector3_hpp
#define Vector3_hpp

#include <stdio.h>
#include <math.h>
class Vector3
{
public:
    float x, y ,z;
    
    Vector3() {}
    Vector3(const Vector3 & a):x(a.x), y(a.y), z(a.z){}
    Vector3(float nx,float ny,float nz):x(nx),y(ny),z(nz){}
    
    //零向量，是唯一一个没有方向的向量
    void  zero() {
        x = y = z = 0.0f;
    }
    
    //计算负向量，-[x , y , z] = [-x, -y , -z]
    Vector3 operator -() const {
        return Vector3(-x, -y, -z);
    }
};


//计算向量的模(长度)||v|| = √x * x + y * y + z * z;
inline float vectorMag(const Vector3 &a) {
    return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}

#endif /* Vector3_hpp */
