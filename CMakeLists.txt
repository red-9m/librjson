cmake_minimum_required(VERSION 3.14)
project (rjson-project C CXX)

if(POLICY CMP0065)
    cmake_policy(SET CMP0065 NEW)
endif()

option(BUILD_SHARED_LIBS "Default build library as shared" ON)
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Set Release as default build type" FORCE)
endif()

message(STATUS "------------------------------------------------------------------------------------")
message(STATUS "Project name     (PROJECT_NAME)             : " ${PROJECT_NAME})
message(STATUS "Project dir      (PROJECT_SOURCE_DIR)       : " ${PROJECT_SOURCE_DIR})
message(STATUS "Build type       (CMAKE_BUILD_TYPE)         : " ${CMAKE_BUILD_TYPE})
message(STATUS "Build shared     (BUILD_SHARED_LIBS)        : " ${BUILD_SHARED_LIBS})
message(STATUS "Install prefix   (CMAKE_INSTALL_PREFIX)     : " ${CMAKE_INSTALL_PREFIX})
message(STATUS "Install lib      (CMAKE_INSTALL_LIBDIR)     : " ${CMAKE_INSTALL_LIBDIR})
message(STATUS "Install include  (CMAKE_INSTALL_INCLUDEDIR) : " ${CMAKE_INSTALL_INCLUDEDIR})
message(STATUS "------------------------------------------------------------------------------------")

# Sources
file(GLOB sources librjson.cpp)
file(GLOB headers librjson.h)
file(GLOB sample-src sample.c)

# Targets
add_library(rjson ${sources})
add_executable(rjson-sample ${sample-src})

# Options
set(_COMPILE_OPT -pipe -ftree-vectorize -ffast-math -flto -Wall -Wextra -Wpedantic)
set(_LINK_OPT "-flto -fuse-ld=gold")
set(_COMPILE_DEF -D_POSIX_C_SOURCE=199309L)

# rjson
target_include_directories(rjson PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}> $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/rapidjson/include>)
set_target_properties(rjson PROPERTIES CXX_STANDARD 11 CXX_STANDARD_REQUIRED ON CXX_EXTENSIONS OFF)
target_compile_options(rjson PRIVATE ${_COMPILE_OPT})
set_target_properties(rjson PROPERTIES LINK_FLAGS ${_LINK_OPT})
set_target_properties(rjson PROPERTIES PUBLIC_HEADER ${headers})
target_compile_definitions(rjson PRIVATE ${_COMPILE_DEF})

# rjson-sample
set_target_properties(rjson-sample PROPERTIES C_STANDARD 11 C_STANDARD_REQUIRED ON C_EXTENSIONS OFF)
target_compile_options(rjson-sample PRIVATE ${_COMPILE_OPT})
set_target_properties(rjson-sample PROPERTIES LINK_FLAGS ${_LINK_OPT})
target_compile_definitions(rjson-sample PRIVATE ${_COMPILE_DEF})
target_link_libraries(rjson-sample rjson)

# Install
install(TARGETS rjson LIBRARY PUBLIC_HEADER)
