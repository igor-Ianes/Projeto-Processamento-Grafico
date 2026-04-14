// Copyright (c) 2026 Igor Ianes
// Licensed under the MIT License.

#pragma once
#include "math3d.hpp"
#include "Mesh.hpp"

struct Object3D
{
    Mesh mesh;

    Vec3d position = {0, 0, 0};
    Vec3d rotation = {0, 0, 0}; // x,y,z
    Vec3d color = {1.0f, 1.0f, 1.0f};
    Vec3d scale = {1.0f, 1.0f, 1.0f};

    float rotX = 0.0f;
    float rotY = 0.0f;
    float rotZ = 0.0f;

    unsigned int textureID;
    bool hasTexture;

    Object3D *parent = nullptr;
    Vec3d initialPosition;

    unsigned int VAO, VBO;
    int vertexCount = 0;

    ~Object3D() = default;
};