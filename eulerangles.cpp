#include "eulerangles.h"

EulerAngles::EulerAngles()
{}

/**
 * @brief EulerAngles::EulerAngles
 * @param heading Y
 * @param pitch   X
 * @param bank    Z
 */
EulerAngles::EulerAngles(float heading, float pitch, float bank)
{
    this->heading = heading;
    this->pitch = pitch;
    this->bank = bank;
}
