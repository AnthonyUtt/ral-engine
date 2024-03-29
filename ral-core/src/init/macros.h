#pragma once

// Define RAL_API for any platform
#if defined _WIN32 || defined __CYGWIN__
  #ifdef WIN_EXPORT
    // Exporting...
    #ifdef __GNUC__
      #define RAL_API __attribute__ ((dllexport))
    #else
      #define RAL_API __declspec(dllexport) // Note: actually gcc seems to also supports this syntax.
    #endif
  #else
    #ifdef __GNUC__
      #define RAL_API __attribute__ ((dllimport))
    #else
      #define RAL_API __declspec(dllimport) // Note: actually gcc seems to also supports this syntax.
    #endif
  #endif
  #define NOT_EXPORTED
#else
  #ifdef GNU_EXPORT
    #if __GNUC__ >= 4
      #define RAL_API __attribute__ ((visibility ("default")))
      #define NOT_EXPORTED  __attribute__ ((visibility ("hidden")))
    #else
      #define RAL_API
      #define NOT_EXPORTED
    #endif
  #else
    #define RAL_API
    #define NOT_EXPORTED
  #endif
#endif

#define BIT(x) (1 << x)

#include "../../lib/ral-log/include/ral-log.h"

#ifndef ENGINE_LOGS
  #define ENGINE_LOGS
  #define LOG_ERROR(message) ::RALlogger::logError(message, "RALengine")
  #define LOG_WARNING(message) ::RALlogger::logWarning(message, "RALengine")
  #define LOG_INFO(message) ::RALlogger::logInfo(message, "RALengine")
  #define LOG_QUIET(message) ::RALlogger::logInfo(message, "RALengine")
  #define LOG_DEBUG(message) ::RALlogger::logDebug(message, "RALengine")
  #define WRITE_LOG(message) ::RALlogger::writeToLog(message, "log/engine.log", "RALengine")
#endif