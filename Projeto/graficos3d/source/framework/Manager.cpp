#include "Manager.hpp"
#include <iostream>

Manager *Manager::sInstance = NULL;

Manager *Manager::Instance()
{
    if (sInstance == NULL)
        sInstance = new Manager();

    return sInstance;
}

void Manager::Release()
{
    delete sInstance;
    sInstance = NULL;
}

Manager::Manager()
{
    mQuit = false;
}

bool Manager::Init()
{
    mGraphics = Graphics::Instance();

    if (!Graphics::Initialized())
    {
        mQuit = true;
        return false;
    }

    mInputMgr = InputManager::Instance();
    mInputMgr->SetWindow(mGraphics->GetWindow());

    mTimer = Timer::Instance();

    graphics3d = Graphics3d::Instance();
    graphics3d->Init(mInputMgr, mTimer);

    return true;
}

Manager::~Manager()
{
    Graphics3d::Release();
    graphics3d = NULL;

    delete graphics3d;
    graphics3d = NULL;

    InputManager::Release();
    mInputMgr = NULL;

    Timer::Release();
    mTimer = NULL;

    Graphics::Release();
    mGraphics = NULL;
}

void Manager::Update()
{
    mInputMgr->Update();

    if (graphics3d)
        graphics3d->Update();
}

void Manager::Render()
{
    mGraphics->ClearBackBuffer();

    if (graphics3d)
        graphics3d->Render();

    mGraphics->Render();
}

void Manager::LateUpdate()
{
    mInputMgr->UpdatePrevInput();
}

void Manager::Run()
{
    GLFWwindow *window = mGraphics->GetWindow();

    while (!mQuit && !glfwWindowShouldClose(window))
    {
        mTimer->Update();
        mInputMgr->Update();

        glfwPollEvents();

        // ESC fecha
        if (mInputMgr->KeyPressed(GLFW_KEY_ESCAPE))
        {
            mQuit = true;
        }

        {
            Update();
            LateUpdate();
            Render();
        }
    }
}