cmake_minimum_required(VERSION 4.2)

# disable exception handling
set(CMAKE_MSVC_EXCEPTION_HANDLING OFF)

# Do not use default cmake flags
set(CMAKE_MSVC_RUNTIME_LIBRARY "" CACHE STRING "" FORCE)
set(CMAKE_BUILD_TYPE "" CACHE STRING "" FORCE)
set(CMAKE_CONFIGURATION_TYPES "" CACHE STRING "" FORCE)

project(app CXX)

if (NOT MSVC)
    message(FATAL_ERROR "Only MSVC is supported")
endif()

# Do not use default cmake link libraries
set(CMAKE_CXX_STANDARD_LIBRARIES "" CACHE STRING "" FORCE)

# Do not use default cmake flags
set(CMAKE_CXX_FLAGS "" CACHE STRING "" FORCE)
set(CMAKE_CXX_FLAGS_DEBUG "" CACHE STRING "" FORCE)
set(CMAKE_CXX_FLAGS_RELEASE "" CACHE STRING "" FORCE)

file(GLOB SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp)
add_executable(${PROJECT_NAME} ${SOURCES})

set(CMAKE_CXX_STANDARD_REQUIRED OFF)
set(CMAKE_CXX_EXTENSIONS OFF)


# Common
target_compile_options(${PROJECT_NAME} PRIVATE
    /std:c++23preview /utf-8 -fp:precise -MP -FC -GF)
target_compile_options(${PROJECT_NAME} PRIVATE
    -W4 -wd4127 -wd4146 -wd4505 -wd4456 -wd4457)
target_compile_definitions(${PROJECT_NAME} PRIVATE
    UNICODE _UNICODE _CRT_SECURE_NO_WARNINGS)
# target_include_directories(${PROJECT_NAME} PRIVATE 
#     ${CMAKE_SOURCE_DIR}/vendor/raylib/include)
# target_link_options(${PROJECT_NAME} PRIVATE
#     /libpath:${CMAKE_SOURCE_DIR}/vendor/raylib/lib)
# target_link_libraries(${PROJECT_NAME} PRIVATE raylib.lib winmm.lib)

set(BUILD_MODE "Debug" CACHE STRING "Choose: Debug or Release")

if (BUILD_MODE STREQUAL "Debug")
    # Debug
    target_compile_options(${PROJECT_NAME} PRIVATE 
        -Od -MDd)
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        DEBUG _DEBUG)
    # target_link_options(${PROJECT_NAME} PRIVATE
    #     /NODEFAULTLIB:msvcrt)
else()
    # Release
    target_compile_options(${PROJECT_NAME} PRIVATE 
        -O2 -MT)
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        NDEBUG _NDEBUG)
    # target_link_options(${PROJECT_NAME} PRIVATE
    #     /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup /NODEFAULTLIB:libcmt)
endif()
