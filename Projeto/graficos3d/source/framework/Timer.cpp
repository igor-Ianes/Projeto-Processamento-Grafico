#include "Timer.hpp"
#include <GLFW/glfw3.h>

Timer *Timer::sInstance = NULL;

Timer *Timer::Instance()
{
    if (sInstance == NULL)
        sInstance = new Timer();

    return sInstance;
}

void Timer::Release()
{
    delete sInstance;
    sInstance = NULL;
}

Timer::Timer()
{
    Reset();
    mDeltaTime = 0.0;
    mTimeScale = 1.0;
}

Timer::~Timer() {}

void Timer::Reset()
{
    mStartTime = glfwGetTime();
}

float Timer::DeltaTime()
{
    return (float)mDeltaTime;
}

void Timer::TimeScale(float t)
{
    mTimeScale = t;
}

float Timer::TimeScale()
{
    return (float)mTimeScale;
}

void Timer::Update()
{
    double currentTime = glfwGetTime();

    mDeltaTime = (currentTime - mStartTime) * mTimeScale;

    mStartTime = currentTime;
}