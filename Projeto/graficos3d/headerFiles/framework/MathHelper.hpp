#ifndef _MATHHELPER_H
#define _MATHHELPER_H
#include <math.h>

struct Vector2
{
    float x;
    float y;

    Vector2(float _x = 0.0f, float _y = 0.0f)
        : x(_x), y(_y) {}
};

#endif