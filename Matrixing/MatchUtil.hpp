//
//  MatchUtil.hpp
//  Matrixing
//
//  Created by caihui yang on 16/9/14.
//  Copyright © 2016年 caihui yang. All rights reserved.
//

#ifndef MatchUtil_hpp
#define MatchUtil_hpp


#include <math.h>

const float kPi = 3.1415926f;
const float k2Pi = kPi * 2.0f;
const float kPiOver2 = kPi / 2.0f;

inline void sinCos(float *returnSin, float *returnCos, float theta) {
    *returnSin = sin(theta);
    *returnCos = cos(theta);
}


#endif /* MatchUtil_hpp */
