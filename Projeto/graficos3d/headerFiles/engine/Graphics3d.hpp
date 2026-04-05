// Copyright (c) 2026 Igor Ianes
// Licensed under the MIT License.

#ifndef _GRAPHICS3D_H
#define _GRAPHICS3D_H

#include "Mesh.hpp"
#include "Camera.hpp"
#include "Renderer3D.hpp"
#include "InputManager.hpp"
#include "Timer.hpp"
#include "Shader.hpp"
#include "Object3D.hpp"
#include <memory>

class Graphics3d
{
private:
    static Graphics3d *sInstance;

    Mesh mesh;
    Camera camera;
    Renderer3D renderer;

    InputManager *input;
    Timer *timer;

    float theta = 0.0f;
    float thetaX = 0.0f;
    unsigned int VAO, VBO;

    std::unique_ptr<Shader> shader;
    Mat4x4 matProj;
    Scene scene;
    size_t selectedObject = 0;

    std::vector<Camera> cameras;
    int currentCamera = 0;

    // obj
    unsigned int meshVAO, meshVBO;
    int meshVertexCount;

    // rotacao automatica
    int rotatingObject = 1;

    // orbita
    float orbitAngle = 0.0f;
    float orbitRadius = 4.0f;
    float orbitSpeed = 1.5f;

    // inclinacao inicial
    bool inclinacao = true;

public:
    void Init(InputManager *input, Timer *timer);
    void Update();
    void Render();
    void AddObject(const std::string &path, Vec3d pos);
    void EngineInput(float dt);
    void EngineAnimation(float dt);
    static void Release();
    static Graphics3d *Instance();
    Camera &GetActiveCamera();
};

#endif
