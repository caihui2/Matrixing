#ifndef QUATERNION_H
#define QUATERNION_H

class Quaternion
{
public:
    float w, x, y, z;
    Quaternion();
    void identity();
};

extern const Quaternion kQuaternionIdentiry;

#endif // QUATERNION_H
