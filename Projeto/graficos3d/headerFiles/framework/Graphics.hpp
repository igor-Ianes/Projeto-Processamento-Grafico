#ifndef _GRAPHICS_H
#define _GRAPHICS_H
#include <GLFW/glfw3.h>
#include <string>

class Graphics
{
public:
    static const int SCREEN_WIDTH = 800;
    static const int SCREEN_HEIGHT = 600;

private:
    static Graphics *sInstance;
    static bool sInitialized;
    GLFWwindow *mWindow;

public:
    static Graphics *Instance();
    static void Release();
    static bool Initialized();

    void ClearBackBuffer();
    void Render();

    GLFWwindow *GetWindow();

private:
    Graphics();
    ~Graphics();

    bool Init();
};

#endif