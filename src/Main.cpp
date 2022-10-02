#include <iostream>
#include <cstdlib>

#include "Timer.h"

int main(int argc, char *argv[])
{
  srand(time(NULL));
  int count = rand() % 1000;

  timer::TimerManual time;
  time.timerInit();

  for (int i = 0; i < count; ++i)
    std::cout << i << " ";

  time.getElapsedTime();
  return 0;
}
