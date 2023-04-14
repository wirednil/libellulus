#include <cstdarg>
#include "WLogger.h"

static Logger* logger = nullptr;
void init_logger(std::ostream& outStream, Level minLevel);
void log_message(Level level, const char* message, const char* file, const char* function, int line);


void wrapper_logger(Level level, const char* fmt, 
    const char* file, int line, const char* func, va_list args) 
{
    va_list args;
    va_start(args, fmt);
    char buffer[1024];
    vsnprintf(buffer, sizeof(buffer), fmt, args);
    va_end(args);
    init_logger(std::cerr, level);
    log_message(level, buffer, file, func, line);
}

void init_logger(std::ostream& outStream, Level minLevel)
{
    if (!logger) {
        logger = new Logger(outStream, minLevel);
    } else {
        logger->setMinLevel(minLevel);
    }
}

void log_message(Level level, const char* message, const char* file, const char* function, int line)
{
    if (logger)
    {
        logger->log(level, message, file, function, line);
    }
}