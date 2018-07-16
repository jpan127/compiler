// #include "Logger.hpp"

// /// spdlog module includes
// #include "spdlog/spdlog.h"
// #include "spdlog/sinks/stdout_color_sinks.h"


// Logger::create(const std::string & name, const bool debug_flag)
// {
//     // Replaces the default logging format pattern
//     static const std::string pattern = "%^[%l]%$ %v";
//     spdlog::set_pattern(pattern);

//     // Create a logger
//     std::shared_ptr <spdlog::logger> logger = spdlog::stdout_color_mt("logger");

//     // Change the logging level
//     if (!debug_flag)
//     {
//         logger->set_level(spdlog::level::info);
//     }
//     else
//     {
//         logger->set_level(spdlog::level::debug);
//     }

//     return logger;
// }

// #pragma once

// #include <string>



// class Logger
// {

// public:

//     /// Retrieves the singleton pointer
//     static Logger & get()
//     {
//         static Logger logger;
//         return logger;
//     }

// private:

//     /// Private constructor
//     Logger();

//     *
//      *  Factory method for creating a logger object
//      *  @param name       : Name of logger object
//      *  @param debug_flag : True to set debug level to info, false for all levels
     
//     void create(const std::string & name, const bool debug_flag);

// };
