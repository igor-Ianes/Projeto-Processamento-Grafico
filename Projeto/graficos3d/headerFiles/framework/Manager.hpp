#ifndef _MANAGER_H
#define _MANAGER_H

#include "Graphics.hpp"
#include "InputManager.hpp"
#include "Graphics3d.hpp"
#include "Renderer3D.hpp"
#include "Timer.hpp"

class Manager
{
private:
    static Manager *sInstance;

    const int FRAME_RATE = 60;

    bool mQuit;
    Graphics *mGraphics;
    InputManager *mInputMgr;
    Timer *mTimer;

    Graphics3d *graphics3d;

public:
    static Manager *Instance();
    static void Release();

    bool Init();
    void Run();

private:
    Manager();
    ~Manager();

    void Update();
    void LateUpdate();
    void Render();
};

#endif
