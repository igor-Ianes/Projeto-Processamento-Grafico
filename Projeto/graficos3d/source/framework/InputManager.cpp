#include "InputManager.hpp"

InputManager *InputManager::sInstance = NULL;

InputManager *InputManager::Instance()
{
    if (sInstance == NULL)
        sInstance = new InputManager();

    return sInstance;
}

void InputManager::Release()
{
    delete sInstance;
    sInstance = NULL;
}

InputManager::InputManager() : mWindow(nullptr)
{
    for (int key = 0; key <= GLFW_KEY_LAST; key++)
    {
        mKeyState[key] = false;
        mPrevKeyState[key] = false;
    }

    for (int btn = 0; btn <= GLFW_MOUSE_BUTTON_LAST; btn++)
    {
        mMouseState[btn] = false;
        mPrevMouseState[btn] = false;
    }
}

InputManager::~InputManager() {}

void InputManager::SetWindow(GLFWwindow *window)
{
    mWindow = window;
}

bool InputManager::KeyDown(int key)
{
    return mKeyState[key];
}

bool InputManager::KeyPressed(int key)
{
    return !mPrevKeyState[key] && mKeyState[key];
}

bool InputManager::KeyReleased(int key)
{
    return mPrevKeyState[key] && !mKeyState[key];
}

bool InputManager::MouseButtonDown(MOUSE_BUTTON button)
{
    return mMouseState[button];
}

bool InputManager::MouseButtonPressed(MOUSE_BUTTON button)
{
    return !mPrevMouseState[button] && mMouseState[button];
}

bool InputManager::MouseButtonReleased(MOUSE_BUTTON button)
{
    return mPrevMouseState[button] && !mMouseState[button];
}

Vector2 InputManager::MousePos()
{
    return Vector2((float)mMouseXPos, (float)mMouseYPos);
}

void InputManager::Update()
{
    if (!mWindow)
        return;

    for (int key = 0; key <= GLFW_KEY_LAST; key++)
    {
        mKeyState[key] = glfwGetKey(mWindow, key) == GLFW_PRESS;
    }

    // mouse
    for (int btn = GLFW_MOUSE_BUTTON_LEFT; btn <= GLFW_MOUSE_BUTTON_LAST; btn++)
    {
        mMouseState[btn] = glfwGetMouseButton(mWindow, btn) == GLFW_PRESS;
    }

    glfwGetCursorPos(mWindow, &mMouseXPos, &mMouseYPos);
}

Vector2 InputManager::MouseDelta()
{
    return Vector2(
        (float)(mMouseXPos - mPrevMouseX),
        (float)(mMouseYPos - mPrevMouseY));
}

void InputManager::UpdatePrevInput()
{
    mPrevKeyState = mKeyState;
    mPrevMouseState = mMouseState;

    mPrevMouseX = mMouseXPos;
    mPrevMouseY = mMouseYPos;
}