// Copyright (c) 2026 Igor Ianes
// Licensed under the MIT License.

#include "OpenGL.hpp"
#include "Graphics3d.hpp"
#include "Scene.hpp"
#include "TextureManager.hpp"
#include "Graphics.hpp"
#include <iostream>

Graphics3d *Graphics3d::sInstance = NULL;

Graphics3d *Graphics3d::Instance()
{
    if (sInstance == NULL)
        sInstance = new Graphics3d();

    return sInstance;
}

void Graphics3d::Init(InputManager *in, Timer *t)
{
    input = in;
    timer = t;

    // criar câmeras
    Camera cam1;
    cam1.position = {0, 10, -65}; // era 10 e depois 40

    Camera cam2;
    cam2.position = {0, 10, 300}; //  {10, 5, 10};
    cam2.yaw = 3.14f;             // 180 graus, olhando para o centro da cena

    Camera cam3;
    cam3.position = {-75, 20, -45}; // {0, 10, 20};
    cam3.yaw = -0.4f;
    cam3.pitch = 0.5f; // -0.5f; pra cima

    cameras.push_back(cam1);
    cameras.push_back(cam2);
    cameras.push_back(cam3);

    // camera atual começa na 0
    currentCamera = 0;

    // Fragment Shader, determina cor dos fragmentos
    const char *fs = "#version 330 core\n"
                     "in vec2 TexCoord;\n"
                     "in vec3 Normal;\n"
                     "in vec3 FragPos;\n"
                     "\n"
                     "out vec4 FragColor;\n"
                     "\n"
                     "uniform sampler2D texture1;\n"
                     "uniform bool useTexture;\n"
                     "uniform vec3 objColor;\n"
                     "uniform vec3 lightDir;\n"
                     "\n"
                     "void main()\n"
                     "{\n"
                     "    vec3 baseColor;\n"
                     "\n"
                     "    if (useTexture)\n"
                     "        baseColor = texture(texture1, TexCoord).rgb;\n"
                     "    else\n"
                     "        baseColor = objColor;\n"
                     "\n"
                     "    vec3 norm = normalize(Normal);\n"
                     "    vec3 light = normalize(lightDir);\n"
                     "\n"
                     "    float diff = max(dot(norm, light), 0.1);\n"
                     "\n"
                     "    vec3 ambient = baseColor * 0.2;\n"
                     "    vec3 diffuse = baseColor * diff;\n"
                     "\n"
                     "    vec3 result = ambient + diffuse;\n"
                     "\n"
                     "    FragColor = vec4(result, 1.0);\n"
                     "}";

    // Vertex Shader, processa vertices
    const char *vs = "#version 330 core\n"
                     "layout (location = 0) in vec3 aPos;\n"
                     "layout (location = 1) in vec3 aNormal;\n"
                     "layout (location = 2) in vec2 aTex;\n"
                     "\n"
                     "out vec2 TexCoord;\n"
                     "out vec3 Normal;\n"
                     "out vec3 FragPos;\n"
                     "\n"
                     "uniform mat4 mvp;\n"
                     "uniform mat4 model;\n"
                     "\n"
                     "void main()\n"
                     "{\n"
                     "    vec4 worldPos = model * vec4(aPos, 1.0);\n"
                     "    FragPos = worldPos.xyz;\n"
                     "\n"
                     "    Normal = mat3(transpose(inverse(model))) * aNormal;\n"
                     "    TexCoord = aTex;\n"
                     "\n"
                     "    gl_Position = mvp * vec4(aPos, 1.0);\n"
                     "}";

    // Shader de textura
    shader = std::make_unique<Shader>(vs, fs);

    // ********* Matriz de projeção, perspectiva ********
    matProj = Matrix_MakeProjection(90.0f, 800.0f / 600.0f, 0.1f, 1000.0f);

    // Configurações iniciais do renderizador
    renderer.SetShader(shader.get());
    renderer.Init(800, 600);
    renderer.SetProjection(matProj);

    // OBJETOS TESTE

    // arrega modelo de Teapot
    // scene.AddObject("Assets/teapot.obj", {0, 0, 8});

    // Carrega modelo de com que suporta textura
    // scene.AddObject("Assets/cuboTextura.obj", {3, 0, 8});

    // carrega textura
    // GLuint tex = TextureManager::LoadTexture("Assets/Textura.png");

    /* ******** montagem da cena de demonstracao ******** */

    // carrega modelo de planicie montanhosa
    scene.AddObject("Assets/montanhaNeve.obj", {0, -45, 40});

    // carrega modelo de dragao
    scene.AddObject("Assets/corpo.obj", {0, 40, 120});
    scene.AddObject("Assets/asaEsquerda.obj", {0, 40, 120});
    scene.AddObject("Assets/asaDireita.obj", {0, 40, 120});

    scene.AddObject("Assets/corpo.obj", {60, 30, 120});
    scene.AddObject("Assets/asaEsquerda.obj", {60, 30, 120});
    scene.AddObject("Assets/asaDireita.obj", {60, 30, 120});

    scene.AddObject("Assets/corpo.obj", {-60, 30, 120});
    scene.AddObject("Assets/asaEsquerda.obj", {-60, 30, 120});
    scene.AddObject("Assets/asaDireita.obj", {-60, 30, 120});

    // carrega textura do dragao
    GLuint tex = TextureManager::LoadTexture("Assets/TextureDragon.png");
    GLuint tex2 = TextureManager::LoadTexture("Assets/TextureDragonBlue.png");
    GLuint tex3 = TextureManager::LoadTexture("Assets/TextureDragonGreen.png");
    GLuint tex4 = TextureManager::LoadTexture("Assets/grama.JPG");

    if (tex == 0)
        std::cout << "FALHA AO CARREGAR TEXTURA\n";

    // link de textura e objeto
    scene.objects[1].textureID = tex;
    scene.objects[2].textureID = tex;
    scene.objects[3].textureID = tex;

    scene.objects[4].textureID = tex2;
    scene.objects[5].textureID = tex2;
    scene.objects[6].textureID = tex2;

    scene.objects[7].textureID = tex3;
    scene.objects[8].textureID = tex3;
    scene.objects[9].textureID = tex3;

    scene.objects[0].textureID = tex4;

    scene.objects[2].parent = &scene.objects[1]; // asa esquerda → corpo
    scene.objects[3].parent = &scene.objects[1]; // asa direita → corpo

    // segundo dragão
    scene.objects[5].parent = &scene.objects[4];
    scene.objects[6].parent = &scene.objects[4];

    // terceiro dragão
    scene.objects[8].parent = &scene.objects[7];
    scene.objects[9].parent = &scene.objects[7];

    // primeiro dragão
    scene.objects[2].position = {0, 0, 0}; // esquerda
    scene.objects[3].position = {0, 0, 0}; // direita
    scene.objects[1].rotX = -0.3f;         // inclina pra cima

    // segundo
    scene.objects[5].position = {0, 0, 0};
    scene.objects[6].position = {0, 0, 0};

    // terceiro
    scene.objects[8].position = {0, 0, 0};
    scene.objects[9].position = {0, 0, 0};

    // define tamanho montanha
    scene.objects[0].scale = {5.0f, 2.0f, 5.0f}; // padrao {5.0f, 5.0f, 5.0f}

    // salva posicao inicial dos objetos para usar como referencia em animacoes
    for (auto &obj : scene.objects)
    {
        obj.initialPosition = obj.position;
    }

    /* ******** montagem da cena de demonstracao ******** */

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glFrontFace(GL_CCW);
}

void Graphics3d::Release()
{
    for (auto &obj : sInstance->scene.objects)
    {
        if (obj.VAO)
            glDeleteVertexArrays(1, &obj.VAO);

        if (obj.VBO)
            glDeleteBuffers(1, &obj.VBO);
    }

    TextureManager::Release();
}

void Graphics3d::Update()
{
    float dt = timer->DeltaTime();

    if (scene.objects.empty())
        return;

    if (selectedObject >= scene.objects.size())
        selectedObject = 0;

    // execucao das animacoes
    EngineAnimation(dt);

    // leitura dos inputs
    EngineInput(dt);
}

void Graphics3d::Render()
{
    renderer.Render(scene.objects, GetActiveCamera());
}

Camera &Graphics3d::GetActiveCamera()
{
    return cameras[currentCamera];
}

void Graphics3d::EngineInput(float dt)
{

    float speed = 5.0f;
    float rotSpeed = 2.0f;

    Object3D &obj = scene.objects[selectedObject];

    // seleciona objeto com tab
    if (input->KeyPressed(GLFW_KEY_TAB))
    {
        selectedObject++;

        if (scene.objects[selectedObject].parent != nullptr)
            selectedObject++; // pula filho, seleciona só o pai
        if (scene.objects[selectedObject].parent != nullptr)
            selectedObject++; // pula filho, seleciona só o pai

        if (selectedObject >= scene.objects.size())
            selectedObject = 0;
    }

    // Movimento do objeto selecionado com TAB

    // para perto e longe
    if (input->KeyDown(GLFW_KEY_I))
        obj.position.z += speed * dt;

    if (input->KeyDown(GLFW_KEY_K))
        obj.position.z -= speed * dt;

    // para esquerda e direita
    if (input->KeyDown(GLFW_KEY_J))
        obj.position.x -= speed * dt;

    if (input->KeyDown(GLFW_KEY_L))
        obj.position.x += speed * dt;

    // para cima e para baixo
    if (input->KeyDown(GLFW_KEY_U))
        obj.position.y += speed * dt;

    if (input->KeyDown(GLFW_KEY_O))
        obj.position.y -= speed * dt;

    // rotação horizontal
    if (input->KeyDown(GLFW_KEY_LEFT))
        obj.rotY -= rotSpeed * dt;

    if (input->KeyDown(GLFW_KEY_RIGHT))
        obj.rotY += rotSpeed * dt;

    // rotação vertical
    if (input->KeyDown(GLFW_KEY_UP))
        obj.rotX += rotSpeed * dt;

    if (input->KeyDown(GLFW_KEY_DOWN))
        obj.rotX -= rotSpeed * dt;

    // rotação no eixo Z
    if (input->KeyDown(GLFW_KEY_M))
        obj.rotZ += rotSpeed * dt;

    if (input->KeyDown(GLFW_KEY_N))
        obj.rotZ -= rotSpeed * dt;

    // rotação no eixo X
    if (input->KeyDown(GLFW_KEY_V))
        obj.rotX += rotSpeed * dt;

    if (input->KeyDown(GLFW_KEY_B))
        obj.rotX -= rotSpeed * dt;

    // mudanca de camera
    if (input->KeyPressed(GLFW_KEY_C))
    {
        currentCamera++;

        if (currentCamera >= (int)cameras.size())
            currentCamera = 0;
    }

    Camera &cam = GetActiveCamera();
    Vec3d forward = cam.GetForward();

    if (input->KeyDown(GLFW_KEY_W))
        cam.position = Vector_Add(cam.position, Vector_Mul(forward, speed * dt * 4.0f));

    if (input->KeyDown(GLFW_KEY_S))
        cam.position = Vector_Sub(cam.position, Vector_Mul(forward, speed * dt * 4.0f));

    if (input->KeyDown(GLFW_KEY_A))
        cam.yaw -= 4.0f * dt;

    if (input->KeyDown(GLFW_KEY_D))
        cam.yaw += 4.0f * dt;

    if (input->KeyDown(GLFW_KEY_G))
        cam.pitch += 2.0f * dt;

    if (input->KeyDown(GLFW_KEY_F))
        cam.pitch -= 2.0f * dt;

    if (input->KeyDown(GLFW_KEY_SPACE))
        cam.position.y += speed * dt * 4.0f;

    if (input->KeyDown(GLFW_KEY_LEFT_SHIFT))
        cam.position.y -= speed * dt * 4.0f;

    /* ************** Escala Por eixo *************** */

    float scaleSpeed = 2.0f;
    // X
    if (input->KeyDown(GLFW_KEY_1))
        obj.scale.x += scaleSpeed * dt;
    if (input->KeyDown(GLFW_KEY_2))
        obj.scale.x -= scaleSpeed * dt;

    // Y
    if (input->KeyDown(GLFW_KEY_3))
        obj.scale.y += scaleSpeed * dt;
    if (input->KeyDown(GLFW_KEY_4))
        obj.scale.y -= scaleSpeed * dt;

    // Z
    if (input->KeyDown(GLFW_KEY_5))
        obj.scale.z += scaleSpeed * dt;
    if (input->KeyDown(GLFW_KEY_6))
        obj.scale.z -= scaleSpeed * dt;

    /* ************** Escala por Tamanho *************** */

    // aumentar tamanho
    if (input->KeyDown(GLFW_KEY_EQUAL)) // tecla "+"
    {
        obj.scale.x += scaleSpeed * dt;
        obj.scale.y += scaleSpeed * dt;
        obj.scale.z += scaleSpeed * dt;
    }

    // diminuir tamanho
    if (input->KeyDown(GLFW_KEY_MINUS)) // tecla "-"
    {
        obj.scale.x -= scaleSpeed * dt;
        obj.scale.y -= scaleSpeed * dt;
        obj.scale.z -= scaleSpeed * dt;
    }

    // evitar escala negativa ou zero
    obj.scale.x = std::max(0.1f, obj.scale.x);
    obj.scale.y = std::max(0.1f, obj.scale.y);
    obj.scale.z = std::max(0.1f, obj.scale.z);

    /* ************  MOUSE  **************** */

    // só mexe se botão esquerdo estiver pressionado
    if (input->MouseButtonDown(InputManager::left))
    {
        Vector2 mouseDelta = input->MouseDelta();
        float mouseSensitivity = 0.005f;

        // rotacao
        cam.yaw += mouseDelta.x * mouseSensitivity;

        // movimento para frente e para tras
        cam.position = Vector_Add(
            cam.position,
            Vector_Mul(forward, -mouseDelta.y * mouseSensitivity * 50.0f));
    }
    else
    {
        // evita lag
        input->UpdatePrevInput();
    }
}

void Graphics3d::EngineAnimation(float dt)
{

    /* ******* Rotacao atomatica do cenario ******* */

    Object3D &rotObj = scene.objects[0];
    rotObj.rotY += 0.4f * dt;

    /* **************** orbita para objetos **************** */

    orbitAngle += orbitSpeed * timer->DeltaTime();

    for (int i = 1; i <= 7; i += 3) // cada dragao, corpo
    {
        Object3D &dragon = scene.objects[i];

        float cx = dragon.initialPosition.x;
        float cz = dragon.initialPosition.z;

        float angle = orbitAngle + i; // ou i * 1.0f

        dragon.position.x = cx + cos(angle) * orbitRadius;
        dragon.position.z = cz + sin(angle) * orbitRadius;
    }

    /* ************** Animacao asas *************** */

    static float time = 0.0f;
    time += dt;

    for (int i = 1; i <= 7; i += 3)
    {
        Object3D &wingL = scene.objects[i + 1];
        Object3D &wingR = scene.objects[i + 2];

        float amplitude = 0.3f;
        float speedAnim = 3.0f;

        float wave = sin(time * speedAnim);

        wingR.rotZ = wave * amplitude;
        wingL.rotZ = -wave * amplitude;
    }

    /* ************** Animacao asas *************** */
}
