#include "quaternion.h"
#include "cmath"
const Quaternion kQuaternionIdentiry = {1.0f, 0.0f, 0.0f, 0.0f};
Quaternion::Quaternion()
{
}

void Quaternion::identity()
{
    w = 1.0f;
    x = y = z =0.0f;
}

void Quaternion::setRotationToX(float theta)
{
    float thetaOVer2 = theta * 0.5;
    w = cos(thetaOVer2);
    x = sin(thetaOVer2);
    y = 0.0f;
    z = 0.0f;
}

void Quaternion::setRotationToY(float theta)
{
    float thetaOVer2 = theta * 0.5;
    w = cos(thetaOVer2);
    x = 0.0f;
    y = sin(thetaOVer2);
    z = 0.0f;
}

void Quaternion::setRotationToZ(float theta)
{
    float thetaOver2 = theta * 0.5;
    w = cos(thetaOver2);
    x = 0.0f;
    y = 0.0f;
    z = sin(thetaOver2);
}

void Quaternion::setRotationToAxis(const Vector &axis, float theta)
{
    float thetaOver2 = theta * 0.5;
    float sinThetaOver2 = sin(thetaOver2);
    w = cos(thetaOver2);
    x = axis.x * sinThetaOver2;
    y = axis.y * sinThetaOver2;
    z = axis.z * sinThetaOver2;
}

