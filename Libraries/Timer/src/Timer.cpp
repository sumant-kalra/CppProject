#include <iostream>

#include "Timer.h"

// ----------------------------------------------------------------------------------------------------------------------- //

timer::TimerScoped::TimerScoped()
{
  m_start = std::chrono::high_resolution_clock::now();
}

// ----------------------------------------------------------------------------------------------------------------------- //

void timer::TimerScoped::getElapsedTime()
{
  std::chrono::high_resolution_clock::time_point t = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> timeTaken = t - m_start;

  std::cout << "\n[Timer] Time elapsed (s) : " << timeTaken.count() << "\n";
}

// ----------------------------------------------------------------------------------------------------------------------- //

timer::TimerScoped::~TimerScoped()
{
  std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> timeTaken = end - m_start;

  std::cout << "\n[Timer] Time taken (s) : " << timeTaken.count() << "\n";
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

  std::chrono::high_resolution_clock::time_point t = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> timeTaken = t - m_start;
  std::cout << "\n[Timer] Time taken (s) : " << timeTaken.count() << "\n";
}
