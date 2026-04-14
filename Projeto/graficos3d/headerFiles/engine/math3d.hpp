// Copyright (c) 2026 Igor Ianes
// Licensed under the MIT License.

#ifndef MATH3D_HPP
#define MATH3D_HPP

#include <cmath>

struct vec2d
{
    float u = 0;
    float v = 0;
    float w = 1;
};

struct Vec3d
{
    float x = 0;
    float y = 0;
    float z = 0;
    float w = 1;
};

struct Triangle
{
    Vec3d p[3];
    vec2d t[3];
    wchar_t sym;
    short col;
};

struct Mat4x4
{
    float m[4][4] = {0};
};

Vec3d Matrix_MultiplyVector(Mat4x4 &m, Vec3d &i);
Mat4x4 Matrix_MakeRotationX(float fAngleRad);
Mat4x4 Matrix_MakeRotationY(float fAngleRad);
Mat4x4 Matrix_MakeRotationZ(float fAngleRad);
Mat4x4 Matrix_MakeTranslation(float x, float y, float z);
Mat4x4 Matrix_MakeProjection(float fFovDegrees, float fAspectRatio, float fNear, float fFar);
Mat4x4 Matrix_MultiplyMatrix(const Mat4x4 &m1, const Mat4x4 &m2);
Mat4x4 Matrix_PointAt(Vec3d &pos, Vec3d &target, Vec3d &up);
Mat4x4 Matrix_QuickInverse(Mat4x4 &m);
Mat4x4 Matrix_MakeScale(float sx, float sy, float sz);
Mat4x4 Matrix_Identity();

inline Vec3d Vector_Add(const Vec3d &v1, const Vec3d &v2)
{
    return {v1.x + v2.x, v1.y + v2.y, v1.z + v2.z};
}

inline Vec3d Vector_Sub(const Vec3d &v1, const Vec3d &v2)
{
    return {v1.x - v2.x, v1.y - v2.y, v1.z - v2.z};
}

inline Vec3d Vector_Mul(const Vec3d &v1, float k)
{
    return {v1.x * k, v1.y * k, v1.z * k};
}

inline Vec3d Vector_Div(const Vec3d &v1, float k)
{
    return {v1.x / k, v1.y / k, v1.z / k};
}

inline float Vector_DotProduct(const Vec3d &v1, const Vec3d &v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

inline float Vector_Length(const Vec3d &v)
{
    return sqrtf(Vector_DotProduct(v, v));
}

inline Vec3d Vector_Normalise(const Vec3d &v)
{
    float l = Vector_Length(v);
    return {v.x / l, v.y / l, v.z / l};
}

inline Vec3d Vector_CrossProduct(const Vec3d &v1, const Vec3d &v2)
{
    Vec3d v;
    v.x = v1.y * v2.z - v1.z * v2.y;
    v.y = v1.z * v2.x - v1.x * v2.z;
    v.z = v1.x * v2.y - v1.y * v2.x;
    return v;
}

#endif