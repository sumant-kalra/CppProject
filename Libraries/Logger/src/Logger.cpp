#include <iostream>

#include "Logger.h"

logger::LogLevel logger::Logger::s_level = logger::LogLevel::INFO;

void logger::Logger::setLevel(logger::LogLevel level)
{
    s_level = level;
}

void logger::Logger::logInfo(const char *message)
{
    if (s_level == logger::LogLevel::INFO)
        std::cout << "[INFO] " << message << "\n";
}

void logger::Logger::logWarning(const char *message)
{
    if (s_level <= logger::LogLevel::WARNING && s_level > logger::LogLevel::INVALID)
        std::cout << "[WARNING] " << message << "\n";
}

void logger::Logger::logError(const char *message)
{
    if (s_level <= logger::LogLevel::ERROR && s_level > logger::LogLevel::INVALID)
        std::cout << "[ERROR] " << message << "\n";
}
