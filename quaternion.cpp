#include "quaternion.h"
const Quaternion kQuaternionIdentiry = {1.0f, 0.0f, 0.0f, 0.0f};
Quaternion::Quaternion()
{
}

void Quaternion::identity()
{
    w = 1.0f;
    x = y = z =0.0f;
}
