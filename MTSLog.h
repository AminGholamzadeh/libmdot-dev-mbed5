/************************************************
 * MultiTech MTDOT Library
 * Copyright (c) 2015 MultiTech Systems
 *
 * See LICENSE file for license information
 ***********************************************/

#ifndef MTSLOG_H
#define MTSLOG_H

#ifdef MTS_DEBUG
#define logFatal(format, ...) \
    MTSLog::printMessage(MTSLog::FATAL_LEVEL, "%s:%s:%s| [%s] " format "\r\n", __FILE__, __func__, __LINE__, MTSLog::FATAL_LABEL, ##__VA_ARGS__)
#define logError(format, ...) \
    MTSLog::printMessage(MTSLog::ERROR_LEVEL, "%s:%s:%s| [%s] " format "\r\n", __FILE__, __func__, __LINE__, MTSLog::ERROR_LABEL, ##__VA_ARGS__)
#define logWarning(format, ...) \
    MTSLog::printMessage(MTSLog::WARNING_LEVEL, "%s:%s:%s| [%s] " format "\r\n", __FILE__, __func__, __LINE__, MTSLog::WARNING_LABEL, ##__VA_ARGS__)
#define logInfo(format, ...) \
    MTSLog::printMessage(MTSLog::INFO_LEVEL, "%s:%s:%s| [%s] " format "\r\n", __FILE__, __func__, __LINE__, MTSLog::INFO_LABEL, ##__VA_ARGS__)
#define logDebug(format, ...) \
    MTSLog::printMessage(MTSLog::DEBUG_LEVEL, "%s:%s:%s| [%s] " format "\r\n", __FILE__, __func__, __LINE__, MTSLog::DEBUG_LABEL, ##__VA_ARGS__)
#define logTrace(format, ...) \
    MTSLog::printMessage(MTSLog::TRACE_LEVEL, "%s:%s:%s| [%s] " format "\r\n", __FILE__, __func__, __LINE__, MTSLog::TRACE_LABEL, ##__VA_ARGS__)
#else
#define logFatal(format, ...) \
    MTSLog::printMessage(MTSLog::FATAL_LEVEL, "[%s] " format "\r\n", MTSLog::FATAL_LABEL, ##__VA_ARGS__)
#define logError(format, ...) \
    MTSLog::printMessage(MTSLog::ERROR_LEVEL, "[%s] " format "\r\n", MTSLog::ERROR_LABEL, ##__VA_ARGS__)
#define logWarning(format, ...) \
    MTSLog::printMessage(MTSLog::WARNING_LEVEL, "[%s] " format "\r\n", MTSLog::WARNING_LABEL, ##__VA_ARGS__)
#define logInfo(format, ...) \
    MTSLog::printMessage(MTSLog::INFO_LEVEL, "[%s] " format "\r\n", MTSLog::INFO_LABEL, ##__VA_ARGS__)
#define logDebug(format, ...) \
    MTSLog::printMessage(MTSLog::DEBUG_LEVEL, "[%s] " format "\r\n", MTSLog::DEBUG_LABEL, ##__VA_ARGS__)
#define logTrace(format, ...) \
    MTSLog::printMessage(MTSLog::TRACE_LEVEL, "[%s] " format "\r\n", MTSLog::TRACE_LABEL, ##__VA_ARGS__)
#endif

namespace mts {

class MTSLog
{
public:

    /** Enum of log levels.
     */
    enum logLevel {
        NONE_LEVEL = 0,
        FATAL_LEVEL = 1,
        ERROR_LEVEL = 2,
        WARNING_LEVEL = 3,
        INFO_LEVEL = 4,
        DEBUG_LEVEL = 5,
        TRACE_LEVEL = 6
    };

    /** Print log message.
     */
    static void printMessage(int level, const char* format, ...);

    /** Determine if the given level is currently printable.
     */
    static bool printable(int level);

    /** Set log level
     * Messages with lower priority than the current level will not be printed.
     * If the level is set to NONE, no messages will print.
     */
    static void setLogLevel(int level);

    /** Get the current log level.
     */
    static int getLogLevel();

    /** Get string representation of the current log level.
     */
    static const char* getLogLevelString();

    static const char* NONE_LABEL;
    static const char* FATAL_LABEL;
    static const char* ERROR_LABEL;
    static const char* WARNING_LABEL;
    static const char* INFO_LABEL;
    static const char* DEBUG_LABEL;
    static const char* TRACE_LABEL;

private:

    /** Constructor
     */
    MTSLog();

    static int currentLevel;

};

}

#endif
