#include "OpenGL.hpp"
#include "Graphics.hpp"
#include <iostream>

Graphics *Graphics::sInstance = NULL;
bool Graphics::sInitialized = false;

Graphics *Graphics::Instance()
{
    if (sInstance == NULL)
        sInstance = new Graphics();

    return sInstance;
}

void Graphics::Release()
{
    delete sInstance;
    sInstance = NULL;
    sInitialized = false;
}

bool Graphics::Initialized()
{
    return sInitialized;
}

Graphics::Graphics()
{
    sInitialized = Init();
}

Graphics::~Graphics()
{
    glfwDestroyWindow(mWindow);
    glfwTerminate();
}

bool Graphics::Init()
{
    if (!glfwInit())
    {
        std::cout << "GLFW init failed\n";
        return false;
    }

    mWindow = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "GLFW Window", NULL, NULL);
    //  glfwSetInputMode(mWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    if (!mWindow)
    {
        std::cout << "Window creation failed\n";
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(mWindow);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD\n";
        return false;
    }

    glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    glEnable(GL_DEPTH_TEST);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

    return true;
}

void Graphics::ClearBackBuffer()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Graphics::Render()
{
    glfwSwapBuffers(mWindow);
}

GLFWwindow *Graphics::GetWindow()
{
    return mWindow;
}