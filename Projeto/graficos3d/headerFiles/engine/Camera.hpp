// Copyright (c) 2026 Igor Ianes
// Licensed under the MIT License.

#ifndef _CAMERA_H
#define _CAMERA_H

#include "math3d.hpp"

class Camera
{
public:
    Vec3d position = {0, 0, 0};
    Vec3d lookDir;
    float yaw = 0.0f;
    float pitch = 0.0f;

    Vec3d GetForward()
    {
        Vec3d target = {0, 0, 1};

        Mat4x4 rotY = Matrix_MakeRotationY(yaw);
        Mat4x4 rotX = Matrix_MakeRotationX(pitch);

        Mat4x4 rot = Matrix_MultiplyMatrix(rotX, rotY);

        return Matrix_MultiplyVector(rot, target);
    }

    Mat4x4 GetViewMatrix()
    {
        Vec3d up = {0, 1, 0};
        Vec3d target = {0, 0, 1};

        Mat4x4 rotY = Matrix_MakeRotationY(yaw);
        Mat4x4 rotX = Matrix_MakeRotationX(pitch);

        Mat4x4 rot = Matrix_MultiplyMatrix(rotX, rotY);

        lookDir = Matrix_MultiplyVector(rot, target);
        target = Vector_Add(position, lookDir);

        Mat4x4 cam = Matrix_PointAt(position, target, up);
        return Matrix_QuickInverse(cam);
    }
};

#endif