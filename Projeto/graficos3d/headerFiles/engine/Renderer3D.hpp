// Copyright (c) 2026 Igor Ianes
// Licensed under the MIT License.

#ifndef _RENDERER3D_H
#define _RENDERER3D_H

#include "Camera.hpp"
#include "Shader.hpp"
#include "math3d.hpp"
#include "Object3D.hpp"
#include "Scene.hpp"
#include <vector>

class Renderer3D
{
public:
    GLint locColor;
    GLint locUseTex;
    GLint locModel;
    GLint locMVP;
    GLint locViewPos;
    GLint locLightDir;
    GLint locTexture;

    Mat4x4 matProj;
    Shader *shader = nullptr;

    GLuint whiteTexture;

    void Init(int width, int height);
    void Render(std::vector<Object3D> &objects, Camera &camera);

    void SetShader(Shader *s);
    void SetProjection(const Mat4x4 &proj);
    void CreateWhiteTexture();
    Mat4x4 GetWorldMatrix(Object3D &obj);
};

#endif