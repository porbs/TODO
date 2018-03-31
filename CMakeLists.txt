cmake_minimum_required(VERSION 3.10)
project(TODO)

set(CMAKE_CXX_STANDARD 14)

#Add ./cmake to project
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# JsonCpp root directory
set(JSONCPP_ROOT_DIR "C:/Program Files (x86)/jsoncpp")

# Find JsonCpp library
find_package(JsonCpp)

message("   ROOT: " ${JSONCPP_ROOT_DIR})
message("  FOUND: " ${JSONCPP_FOUND})
message("INCLUDE: " ${JSONCPP_INCLUDE_DIR})
message("LIBRARY: " ${JSONCPP_LIBRARY_RELEASE})

include_directories(${JSONCPP_INCLUDE_DIR})
add_executable(TODO main.cpp src/Task.cpp include/Task.h src/Board.cpp include/Board.h)
target_link_libraries(TODO ${JSONCPP_LIBRARY_RELEASE})
