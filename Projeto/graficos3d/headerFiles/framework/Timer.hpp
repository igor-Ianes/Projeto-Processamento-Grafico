#ifndef _TIMER_H
#define _TIMER_H

class Timer
{
private:
    static Timer *sInstance;

    double mStartTime;
    double mDeltaTime;
    double mTimeScale;

public:
    static Timer *Instance();
    static void Release();

    void Reset();
    float DeltaTime();

    void TimeScale(float t);
    float TimeScale();

    void Update();

private:
    Timer();
    ~Timer();
};

#endif