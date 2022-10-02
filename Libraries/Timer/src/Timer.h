#ifndef TIMER_H
#define TIMER_H

#include <chrono>

namespace timer
{
  class Timer
  {
  protected:
    std::chrono::high_resolution_clock::time_point m_start;

  public:
    Timer() = default;
    virtual void getElapsedTime() = 0;
    virtual ~Timer() = default;
  };

  class TimerScoped : public Timer
  {
  public:
    TimerScoped();
    TimerScoped(const TimerScoped &) = delete;
    TimerScoped &operator=(const TimerScoped &) = delete;
    ~TimerScoped();

    void getElapsedTime() override;
  };

  class TimerManual : public Timer
  {
  private:
    bool m_isInitialized;

  public:
    TimerManual();
    TimerManual(const TimerManual &) = delete;
    TimerManual &operator=(const TimerManual &) = delete;
    ~TimerManual() = default;

    void timerInit();
    void getElapsedTime() override;
  };

}

#endif
