#ifndef _WLOGGER_H_
#define _WLOGGER_H_

#include "Logger.hpp"

void wrapper_logger(Level level,
               const char* fmt,
               const char* file,
               int line,
               const char* func,
               va_list args);

#endif //_WLOGGER_H_