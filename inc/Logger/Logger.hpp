#ifndef __LOGGER_H__
#define __LOGGER_H__
#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <iomanip>
#include "macros.h"

/**
 * @class Logger
 * @brief Provides a mechanism for logging messages at different levels of severity.
 *
 * The Logger class provides a way to log messages with different levels of severity, such as DEBUG, INFO, WARNING,
 * ERROR, and FATAL. Messages with a severity level lower than the minimum level set for the logger will not be
 * logged. The logger can output messages to a stream, such as cout or a file, and can be customized to include
 * information about the file, function, and line where each message was logged.
 */
class Logger
{
public:

    /**
     * @brief Constructs a new Logger with the specified output stream and minimum severity level.
     * @param outStream The stream to which log messages will be written.
     * @param minLevel The minimum severity level of messages that will be logged.
     */
    Logger(std::ostream& outStream, Level minLevel) :
        outStream_(outStream),
        minLevel_(minLevel)
    {}

    /**
     * @brief Logs a message with the specified severity level.
     *
     * The log method writes a message with the specified severity level to the logger's output stream, if the
     * severity level is greater than or equal to the minimum level set for the logger. The message includes the
     * severity level, the time at which it was logged, the file, function, and line number where the log statement
     * occurred, and the user-provided message text.
     *
     * @param level The severity level of the message.
     * @param message The text of the log message.
     * @param file The name of the file where the log statement occurred.
     * @param function The name of the function where the log statement occurred.
     * @param line The line number where the log statement occurred.
     */
    void log(Level level, const std::string& message, const char* file, const char* function, int line);

    /**
     * @brief Sets the minimum severity level of messages that will be logged.
     *
     * The setMinLevel method sets the minimum severity level of messages that will be logged. Messages with a
     * severity level lower than the specified level will not be logged.
     *
     * @param minLevel The minimum severity level of messages that will be logged.
     */
    void setMinLevel(Level minLevel);

private:
    std::ostream& outStream_; /**< The output stream to which log messages will be written. */
    Level minLevel_ = Level::DEBUG;          /**< The minimum severity level of messages that will be logged. */

    /**
     * @brief Converts a severity level to its string representation.
     * @param level The severity level to convert.
     * @return The string representation of the severity level.
     */
    std::string levelToString(Level level);
};

#endif // __LOGGER_H__