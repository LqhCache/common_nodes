cmake_minimum_required(VERSION 3.10)
project(logger)

add_library(lib_logger detail/FileLogAppender.cpp
                       detail/LogAppender.cpp
                       detail/LogEvent.cpp
                       detail/LogFormatter.cpp
                       detail/Logger.cpp
                       detail/StdoutLogAppender.cpp)

add_subdirectory(unittest)
