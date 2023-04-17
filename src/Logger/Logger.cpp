#include "Logger.hpp"

const char* const Error = "ERROR";
const char* const Info = "INFO";
const char* const Warning = "WARNING";
const char* const Debug = "DEBUG";
const char* const Fatal = "FATAL";
const char* const Default = "";

void Logger::log(Level level, const std::string& message, const char* file, const char* function, int line) 
{
    if (level >= minLevel_)
    {
        auto now = std::chrono::system_clock::now();
        std::time_t nowTime = std::chrono::system_clock::to_time_t(now);
        std::stringstream ss;
        ss << std::put_time(std::localtime(&nowTime), "%F %T");
        std::string timeStamp = ss.str();

        std::stringstream logStream;
        logStream << "[" << timeStamp << "] "
                  << "[" << levelToString(level) << "] "
                  << "[" << file << ":" << line << " " << function << "] "
                  << message << std::endl;

        outStream_ << logStream.str();
    }
}

void Logger::setMinLevel(Level minLevel)
{
    minLevel_ = minLevel;
}

std::string Logger::levelToString(Level level)
{
    switch (level)
    {
        case Level::DEBUG:
            return Debug;
        case Level::INFO:
            return Info;
        case Level::WARNING:
            return Warning;
        case Level::ERROR:
            return Error;
        case Level::FATAL:
            return Fatal;
        default:
            return Default;
    }
}