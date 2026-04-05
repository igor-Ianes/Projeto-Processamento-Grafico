// Copyright (c) 2026 Igor Ianes
// Licensed under the MIT License.

#include "OpenGL.hpp"
#include "Scene.hpp"
#include <iostream>

Object3D &Scene::AddObject(const std::string &path, Vec3d pos)
{
    Object3D obj;

    obj.mesh.LoadFromObjectFile(path);
    obj.position = pos;
    obj.textureID = 0; // se nao inicializar com 0, gera um bug horrendo

    // define cor aleatoria a cada execucao, para diferenciar os objetos sem textura
    /*
        obj.color = {
            (float)(rand() % 100) / 100.0f,
            (float)(rand() % 100) / 100.0f,
            (float)(rand() % 100) / 100.0f};
        std::cout << "cor: " << obj.color.x << ", " << obj.color.y << ", " << obj.color.z << std::endl;
    */

    // define cor fixa, cinza para objetos sem textura
    obj.color = {1.0f, 1.0f, 1.0f};

    std::vector<float> vertices;

    for (auto &tri : obj.mesh.tris)
    {
        Vec3d line1 = Vector_Sub(tri.p[1], tri.p[0]);
        Vec3d line2 = Vector_Sub(tri.p[2], tri.p[0]);

        Vec3d normal = Vector_CrossProduct(line2, line1);
        normal = Vector_Normalise(normal);

        for (int i = 0; i < 3; i++)
        {
            vertices.push_back(tri.p[i].x);
            vertices.push_back(tri.p[i].y);
            vertices.push_back(tri.p[i].z);

            // normal
            vertices.push_back(normal.x);
            vertices.push_back(normal.y);
            vertices.push_back(normal.z);

            // UV
            vertices.push_back(tri.t[i].u);
            vertices.push_back(tri.t[i].v);
        }
    }

    obj.vertexCount = vertices.size() / 8; // 6 ou 8

    glGenVertexArrays(1, &obj.VAO);
    glGenBuffers(1, &obj.VBO);

    glBindVertexArray(obj.VAO);
    glBindBuffer(GL_ARRAY_BUFFER, obj.VBO);

    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

    // posição
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    // normal
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // UV
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    objects.push_back(obj);
    return objects.back();
}