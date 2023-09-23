/**
 *
 * @file WLogger.h
 * @brief Header file containing function declarations for WLogger, a C-style logging library.
 * WLogger provides C-style logging functions that can be used to log messages with varying levels of severity.
 * The header file defines the wrapper_logger() function, which can be called to log messages.
 *
 */
#ifndef _WLOGGER_H_
#define _WLOGGER_H_

#include <stdarg.h>
#include "macros.h"

#ifdef __cplusplus
extern "C" {
#endif

void wrapper_init(Level level);

/**
 *
 * @brief Logs a message with a specified severity level, function name, file name, line number and format string.
 * This function logs a message with a specified severity level, function name, file name, line number and format string.
 * The format string supports placeholders, which can be replaced with the supplied arguments.
 *
 * @param level The severity level of the message to be logged.
 * @param func The name of the function where the log message is being called from.
 * @param file The name of the file where the log message is being called from.
 * @param line The line number where the log message is being called from.
 * @param fmt The format string for the log message.
 * @param ... Optional arguments to be replaced in the format string placeholders.
 * 
 * @return void.
 *
 */
void wrapper_logger(Level level,
    const char* func, const char* file, int line, const char* fmt, ...);

#ifdef __cplusplus
}
#endif

#endif // _WLOGGER_H_
