// Copyright (c) 2026 Igor Ianes
// Licensed under the MIT License.

#include "OpenGL.hpp"
#include "Renderer3D.hpp"

void Renderer3D::Init(int width, int height)
{
    matProj = Matrix_MakeProjection(90.0f, (float)width / height, 0.1f, 1000.0f);

    // textura
    CreateWhiteTexture();

    locColor = glGetUniformLocation(shader->ID, "objColor");
    locUseTex = glGetUniformLocation(shader->ID, "useTexture");
    locModel = glGetUniformLocation(shader->ID, "model");
    locMVP = glGetUniformLocation(shader->ID, "mvp");
    locViewPos = glGetUniformLocation(shader->ID, "viewPos");
    locLightDir = glGetUniformLocation(shader->ID, "lightDir");
    locTexture = glGetUniformLocation(shader->ID, "texture1");
}

void Renderer3D::Render(std::vector<Object3D> &objects, Camera &camera)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    shader->Use();

    // posição da câmera

    glUniform3f(locViewPos,
                camera.position.x,
                camera.position.y,
                camera.position.z);

    // ativa textura no slot 0
    glUniform1i(locTexture, 0);

    Vec3d lightDir = {-0.5f, -1.0f, -0.3f};
    lightDir = Vector_Normalise(lightDir);

    glUniform3f(
        locLightDir,
        lightDir.x,
        lightDir.y,
        lightDir.z);

    glUniform3f(
        locViewPos,
        camera.position.x,
        camera.position.y,
        camera.position.z);

    for (auto &obj : objects)
    {
        // Envia a cor fixa do objeto para o shader
        glUniform3f(locColor, obj.color.x, obj.color.y, obj.color.z);

        // Define se usa textura ou cor sólida
        if (obj.textureID > 0)
        {
            glUniform1i(locTexture, 1);
            glBindTexture(GL_TEXTURE_2D, obj.textureID);
        }
        else
        {
            glUniform1i(locTexture, 0);
            glBindTexture(GL_TEXTURE_2D, 0);
        }

        bool hasTexture = (obj.textureID != 0);

        // ativa textura no slot 0
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, hasTexture ? obj.textureID : whiteTexture);

        // sampler aponta pro slot 0
        glUniform1i(locTexture, 0);

        // diz se usa textura ou não
        glUniform1i(locUseTex, hasTexture ? 1 : 0);

        // cor base
        glUniform3f(locColor, obj.color.x, obj.color.y, obj.color.z);

        // ORDEM FINAL
        Mat4x4 matWorld = GetWorldMatrix(obj);

        // uniforms
        glUniformMatrix4fv(locModel, 1, GL_FALSE, &matWorld.m[0][0]);
        glUniform3f(locColor, obj.color.x, obj.color.y, obj.color.z);

        Mat4x4 matView = camera.GetViewMatrix();
        Mat4x4 matWVP = Matrix_MultiplyMatrix(
            Matrix_MultiplyMatrix(matWorld, matView), matProj);

        glUniformMatrix4fv(locMVP, 1, GL_FALSE, &matWVP.m[0][0]);
        glBindVertexArray(obj.VAO);
        glDrawArrays(GL_TRIANGLES, 0, obj.vertexCount);
    }
}

void Renderer3D::SetShader(Shader *s)
{
    shader = s;
}

void Renderer3D::SetProjection(const Mat4x4 &proj)
{
    matProj = proj;
}

void Renderer3D::CreateWhiteTexture()
{
    unsigned char white[3] = {255, 255, 255};

    glGenTextures(1, &whiteTexture);
    glBindTexture(GL_TEXTURE_2D, whiteTexture);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 1, 1, 0, GL_RGB, GL_UNSIGNED_BYTE, white);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
}

Mat4x4 Renderer3D::GetWorldMatrix(Object3D &obj)
{
    Mat4x4 matScale = Matrix_MakeScale(obj.scale.x, obj.scale.y, obj.scale.z);

    Mat4x4 matRotX = Matrix_MakeRotationX(obj.rotX);
    Mat4x4 matRotY = Matrix_MakeRotationY(obj.rotY);
    Mat4x4 matRotZ = Matrix_MakeRotationZ(obj.rotZ);

    Mat4x4 matRot = Matrix_MultiplyMatrix(
        matRotZ,
        Matrix_MultiplyMatrix(matRotY, matRotX));

    Mat4x4 matTrans = Matrix_MakeTranslation(
        obj.position.x,
        obj.position.y,
        obj.position.z);

    Mat4x4 local = Matrix_MultiplyMatrix(matScale, matRot);
    local = Matrix_MultiplyMatrix(local, matTrans);

    // hierarquia
    if (obj.parent != nullptr)
    {
        Mat4x4 parentWorld = GetWorldMatrix(*obj.parent);
        return Matrix_MultiplyMatrix(local, parentWorld);
    }

    return local;
}