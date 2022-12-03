#include <iostream>
#include <cmath>

#include "Timer.h"

// ----------------------------------------------------------------------------------------------------------------------- //

timer::TimerScoped::TimerScoped()
{
  m_start = std::chrono::high_resolution_clock::now();
}

// ----------------------------------------------------------------------------------------------------------------------- //

void timer::TimerScoped::getElapsedTime()
{
  timer::Timer::printElapsedTimeFromStartTime(m_start);
}

// ----------------------------------------------------------------------------------------------------------------------- //

timer::TimerScoped::~TimerScoped()
{
  timer::Timer::printElapsedTimeFromStartTime(m_start);
}

// ----------------------------------------------------------------------------------------------------------------------- //

timer::TimerManual::TimerManual()
    : m_isInitialized(false)
{
}

// ----------------------------------------------------------------------------------------------------------------------- //

void timer::TimerManual::timerInit()
{
  std::cout << "\n[Timer] Timer reset.\n";
  m_isInitialized = true;
  m_start = std::chrono::high_resolution_clock::now();
}

// ----------------------------------------------------------------------------------------------------------------------- //

void timer::TimerManual::getElapsedTime()
{
  if (!m_isInitialized)
  {
    std::cerr << "\n[TIMER][ERROR] Timer is not initialized!\n";
    return;
  }
  timer::Timer::printElapsedTimeFromStartTime(m_start);
}

// ----------------------------------------------------------------------------------------------------------------------- //

void timer::Timer::printElapsedTimeFromStartTime(const std::chrono::high_resolution_clock::time_point &tStart)
{
  std::chrono::high_resolution_clock::time_point t = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> timeTaken = t - tStart;

  std::cout << "\n[Timer] Time elapsed (us) : " << timer::convertSecondsToMicroSeconds(timeTaken.count()) << "\n";
}
