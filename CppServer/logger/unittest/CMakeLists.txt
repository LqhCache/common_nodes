cmake_minimum_required(VERSION 3.10)

add_executable(unittest_logger main.cpp LoggerTest.cpp)

target_link_libraries(unittest_logger gtest)