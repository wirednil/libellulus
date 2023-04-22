/**
 * @file SimpleLog.h
 * @brief Defines macros for logging messages at different levels of severity using a wrapper around WLogger.
 */

#ifndef __SIMPLE_LOG_H__
#define __SIMPLE_LOG_H__
#include <stdlib.h>
#include <stdbool.h>
#include "macros.h"
#include "WLogger.h"

/**
 * @brief Logs a message at the DEBUG level using a wrapper around WLogger.
 *
 * The SIMPLE_DEBUG macro logs a message at the DEBUG level using a wrapper around WLogger. It accepts a printf-style
 * format string and zero or more additional arguments to be formatted and included in the log message. The macro
 * automatically includes information about the file, line number, and function where it was called.
 *
 * @param FMT The printf-style format string for the log message.
 * @param ... Zero or more additional arguments to be included in the log message.
 */
#define SIMPLE_DEBUG(FMT, ...) do { \
    wrapper_logger(DEBUG, __func__, __FILE__, __LINE__, FMT, ##__VA_ARGS__); \
} while (false)

/**
 * @brief Logs a message at the INFO level using a wrapper around WLogger.
 *
 * The SIMPLE_INFO macro logs a message at the INFO level using a wrapper around WLogger. It accepts a printf-style
 * format string and zero or more additional arguments to be formatted and included in the log message. The macro
 * automatically includes information about the file, line number, and function where it was called.
 *
 * @param FMT The printf-style format string for the log message.
 * @param ... Zero or more additional arguments to be included in the log message.
 */
#define SIMPLE_INFO(FMT, ...) do { \
    wrapper_logger(INFO, __func__, __FILE__, __LINE__, FMT, ##__VA_ARGS__); \
} while (false)

/**
 * @brief Logs a message at the ERROR level using a wrapper around WLogger.
 *
 * The SIMPLE_ERROR macro logs a message at the ERROR level using a wrapper around WLogger. It accepts a printf-style
 * format string and zero or more additional arguments to be formatted and included in the log message. The macro
 * automatically includes information about the file, line number, and function where it was called.
 *
 * @param FMT The printf-style format string for the log message.
 * @param ... Zero or more additional arguments to be included in the log message.
 */
#define SIMPLE_ERROR(FMT, ...) do { \
    wrapper_logger(ERROR, __func__, __FILE__, __LINE__, FMT, ##__VA_ARGS__); \
} while (false)

/**
 * @brief Logs a message at the WARNING level using a wrapper around WLogger.
 *
 * The SIMPLE_WARNING macro logs a message at the WARNING level using a wrapper around WLogger. It accepts a printf-style
 * format string and zero or more additional arguments to be formatted and included in the log message. The macro
 * automatically includes information about the file, line number, and function where it was called.
 *
 * @param FMT The printf-style format string for the log message.
 * @param ... Zero or more additional arguments to be included in the log message.
 */
#define SIMPLE_WARNING(FMT, ...) do { \
    wrapper_logger(WARNING, __func__, __FILE__, __LINE__, FMT, ##__VA_ARGS__); \
} while (false)

/**
 * @brief Logs a message at the FATAL level using a wrapper around WLogger.
 *
 * The SIMPLE_FATAL macro logs a message at the FATAL level using a wrapper around WLogger. It accepts a printf-style
 * format string and zero or more additional arguments to be formatted and included in the log message. The macro
 * automatically includes information about the file, line number, and function where it was called.
 *
 * @param FMT The printf-style format string for the log message.
 * @param ... Zero or more additional arguments to be included in the log message.
 */
 #define SIMPLE_FATAL(FMT, ...) do { \
    wrapper_logger(FATAL, __func__, __FILE__, __LINE__, FMT, ##__VA_ARGS__); \
} while (false)

#endif //SIMPLE_LOG_H