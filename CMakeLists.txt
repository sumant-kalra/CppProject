cmake_minimum_required(VERSION 3.5)
project(CppProject VERSION 1.0.0)

# Set "Release" build as the default build 
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release")
  message(WARNING "Build type is undefined! Generating a 'Release' build by default")
endif()

# Set the preprocessor directives
if(CMAKE_BUILD_TYPE STREQUAL Release)
  add_compile_definitions(PR_RELEASE=1)
  message(STATUS "## Build Type: 'Release'")
else()
  add_compile_definitions(PR_RELEASE=0)
  message(STATUS "## Build Type: 'Debug'")
endif()


# Detect OS
if(APPLE)
  message(STATUS "## OS: MacOS")
elseif(UNIX AND NOT APPLE)
  message(STATUS "## OS: Unix based OS")
elseif(WIN32)
  message(STATUS "## OS: Microsoft windows")
endif()

# Set the C++ flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++17 -save-temps")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
set(CMAKE_CXX_FLAGS_DEBUG "-g")

# Set up project
add_subdirectory(Libraries/Timer)
add_subdirectory(Libraries/MemoryTrace)

add_executable(runApp src/Main.cpp)

target_link_libraries(runApp PUBLIC Timer
                             PUBLIC MemoryTrace)




