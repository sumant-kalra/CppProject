cmake_minimum_required(VERSION 3.5)
project(CppProject)

if(NOT CMAKE_BUILD_TYPE)
set(CMAKE_BUILD_TYPE "Release")
message(WARNING "Build type is not provided! The default build 'Release' will be generated")
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Release")
add_compile_definitions(PR_RELEASE=1)
message("\n[DEV_INFO] This is a 'Release' build\n")
else()
add_compile_definitions(PR_RELEASE=0)
message("\n[DEV_INFO] This is a 'Debug' build\n")
endif()

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -save-temps -std=c++17")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -save-temps -std=c++17")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

add_subdirectory(Libraries/Logger)
add_subdirectory(Libraries/MemoryTrace)
add_subdirectory(Libraries/Timer)

add_executable(runApp src/Main.cpp)

target_link_libraries(runApp PUBLIC Logger)
target_link_libraries(runApp PUBLIC MemoryTrace)
target_link_libraries(runApp PUBLIC Timer)

target_include_directories(runApp PUBLIC "${PROJECT_SOURCE_DIR}/Libraries/Logger/src")
target_include_directories(runApp PUBLIC "${PROJECT_SOURCE_DIR}/Libraries/MemoryTrace/src")
target_include_directories(runApp PUBLIC "${PROJECT_SOURCE_DIR}/Libraries/Timer/src")

