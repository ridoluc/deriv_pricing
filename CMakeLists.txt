cmake_minimum_required(VERSION 3.0.0)
project(OptionPricing VERSION 0.1.0)

set(CMAKE_CXX_COMPILER "clang++")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -c")

include(CTest)
enable_testing()

add_library(CallPut CallPut.cpp)

add_executable(OptionPricing main.cpp )
target_link_libraries(OptionPricing PRIVATE CallPut)



set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
