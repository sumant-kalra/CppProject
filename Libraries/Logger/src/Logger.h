#ifndef LOGGER_H
#define LOGGER_H

namespace logger
{
    enum class LogLevel
    {
        INFO = 0,
        WARNING = 1,
        ERROR = 2,
        INVALID = -1
    };

    class Logger
    {
    private:
        static LogLevel s_level;

    public:
        static void setLevel(LogLevel level);

        static void getLevel(LogLevel level);

        static void logInfo(const char *message);
        static void logWarning(const char *message);
        static void logError(const char *message);
    };
}

#endif