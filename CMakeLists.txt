cmake_minimum_required(VERSION 3.9)
project(TODO)

set(CMAKE_CXX_STANDARD 14)

#Add ./cmake to project
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

file(GLOB_RECURSE SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

# JsonCpp root directory
if (WIN32)
    set(JSONCPP_ROOT_DIR "C:/Program Files (x86)/jsoncpp")
elseif(UNIX)
    #set(JSONCPP_ROOT_DIR "/usr/local")
endif ()

# Find JsonCpp library
find_package(JsonCpp REQUIRED)

message("   ROOT: " ${JSONCPP_ROOT_DIR})
message("  FOUND: " ${JSONCPP_FOUND})
message("INCLUDE: " ${JSONCPP_INCLUDE_DIR})
message("LIBRARY: " ${JSONCPP_LIBRARY_RELEASE})

if (WIN32)
    add_definitions("-D_WINDOWS_")
elseif(UNIX)
    add_definitions("-D_LINUX_")
endif ()

include_directories(${JSONCPP_INCLUDE_DIR})
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")

add_executable(TODO main.cpp ${SRC})
#src/Task.cpp include/Task.h src/Board.cpp include/Board.h
target_link_libraries(TODO ${JSONCPP_LIBRARY_RELEASE})
