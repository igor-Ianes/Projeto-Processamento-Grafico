#ifndef _INPUTMANAGER
#define _INPUTMANAGER

#include <GLFW/glfw3.h>
#include <unordered_map>
#include "MathHelper.hpp"

class InputManager
{
public:
    enum MOUSE_BUTTON
    {
        left = GLFW_MOUSE_BUTTON_LEFT,
        right = GLFW_MOUSE_BUTTON_RIGHT,
        middle = GLFW_MOUSE_BUTTON_MIDDLE
    };

private:
    static InputManager *sInstance;

    GLFWwindow *mWindow;

    std::unordered_map<int, bool> mKeyState;
    std::unordered_map<int, bool> mPrevKeyState;

    std::unordered_map<int, bool> mMouseState;
    std::unordered_map<int, bool> mPrevMouseState;

    double mMouseXPos;
    double mMouseYPos;

    double mPrevMouseX;
    double mPrevMouseY;

public:
    static InputManager *Instance();
    static void Release();

    void SetWindow(GLFWwindow *window);

    bool KeyDown(int key);
    bool KeyPressed(int key);
    bool KeyReleased(int key);

    bool MouseButtonDown(MOUSE_BUTTON button);
    bool MouseButtonPressed(MOUSE_BUTTON button);
    bool MouseButtonReleased(MOUSE_BUTTON button);

    Vector2 MousePos();

    Vector2 MouseDelta();
    GLFWwindow *GetWindow() { return mWindow; }

    void Update();
    void UpdatePrevInput();

private:
    InputManager();
    ~InputManager();
};

#endif