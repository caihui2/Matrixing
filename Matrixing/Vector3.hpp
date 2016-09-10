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
    
    //标量和向量相乘 [xa, ya, za];
    Vector3 operator * (float a) const {
        return Vector3(x * a, y * a, z * a);
    }
    
    //标量和向量相乘 [xa, ya, za];
    Vector3 operator *=(float a) {
        x *= a , y *= a , z *=a;
        return *this;
    }
    
    //标量和向量相除 [x/a, y/a, b/a]
    Vector3 operator/(float a)const {
        float oneOverA = 1.0f / a;//得到系数
        return Vector3(x * oneOverA, y * oneOverA, z * oneOverA);
    }
    
    //标量和向量相除 [x/a, y/a, b/a]
    Vector3 operator /=(float a)const {
        float oneOverA = 1.0f / a;//得到系数
        return Vector3(x * oneOverA, y * oneOverA, z * oneOverA);
    }
    
    
    //向量的加法
    Vector3 operator +(const Vector3 &a) const {
        return Vector3(x + a.x, y + a.y, z + a.z);
    }
    
    //向量的加法
    Vector3 operator -(const Vector3 &a) const {
        return Vector3(x - a.x, y - a.y, z - a.z);
    }
    
    //向量的加法
    Vector3 operator +=(const Vector3 &a) const {
        return Vector3(x + a.x, y + a.y, z + a.z);
    }
    
    //向量的加法
    Vector3 operator -=(const Vector3 &a) const {
        return Vector3(x - a.x, y - a.y, z - a.z);
    }
    
    
    //向量标准化 [x , y , z] / ||[x, y ,z ] ||
    void normalize() {
        float magSq = x * x + y * y  + z * z;
        if(magSq > 0.0f) {
            float oneOverMag = 1.0f / sqrtf(magSq); //系数
            x *= oneOverMag;
            y *= oneOverMag;
            z *= oneOverMag;
        }
    }
};


//计算向量的模(长度)||v|| = √x * x + y * y + z * z;
inline float vectorMag(const Vector3 &a) {
    return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}

//两点之间的距离
inline float distance(const Vector3 &a, const Vector3 &b) {

    float dx = a.x - b.x;
    float dy = a.y - b.y;
    float dz = a.z - b.z;
    
    return sqrt(dx * dx + dy * dy + dz * dz);

}

#endif /* Vector3_hpp */
