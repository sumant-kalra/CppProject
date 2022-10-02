#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>

namespace logger
{
  enum class Level
  {
    INFO=0,
    WARNING,
    ERROR,
    INVALID=-1
  };

  class Logger
  {
    private:
      static Level m_level;

    public:
      static void getLogLevel();
      static void setLogLevel(Level level);

      template<typename T>
        static void logInfo(const T& message);

      template<typename T>
        static void logWarning(const T& message);

      template<typename T>
        static void logError(const T& message);

  };

  template<typename T>
    void Logger::logInfo (const T& message)
    {
      std::cout<<message<<"\n";
    }
}

#endif


/*
 *

logInfo<<" "<<;


 *
 * */



