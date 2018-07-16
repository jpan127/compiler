#pragma once

#include <string>

/// spdlog module includes
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"



/// Default logger name for typical logging operations
#define DEFAULT_LOGGER_NAME     "logger"

/// Alias for logger pointer
using SpeedLoggerPtr = std::shared_ptr <spdlog::logger>;

/**
 *  Factory method for creating a logger object
 *  @param debug_flag : True to set debug level to info, false for all levels
 *  @param name       : Name of logger object
 */
inline SpeedLoggerPtr logger_create(const bool debug_flag, const std::string & name = DEFAULT_LOGGER_NAME)
{
    // Replaces the default logging format pattern
    static const std::string pattern = "%^[%l]%$ %v";
    spdlog::set_pattern(pattern);

    // Create a logger
    SpeedLoggerPtr logger = spdlog::stdout_color_mt(name);

    // Change the logging level
    if (!debug_flag)
    {
        logger->set_level(spdlog::level::info);
    }
    else
    {
        logger->set_level(spdlog::level::debug);
    }

    return logger;
}

/// Returns a handle to the default logger
inline SpeedLoggerPtr logger_get_default_logger()
{
    return spdlog::get(DEFAULT_LOGGER_NAME);
}