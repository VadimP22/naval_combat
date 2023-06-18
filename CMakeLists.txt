cmake_minimum_required(VERSION 3.25.2)
project(naval_combat CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/includes")

file(GLOB_RECURSE CORE_SOURCES
    "${CMAKE_SOURCE_DIR}/sources/core/*.cc" 
    "${CMAKE_SOURCE_DIR}/sources/core/net/*.cc"
)

file(GLOB_RECURSE CLIENT_SOURCES 
    "${CMAKE_SOURCE_DIR}/sources/client/*.cc" 
    "${CMAKE_SOURCE_DIR}/sources/client/commands/*.cc"
)

file(GLOB_RECURSE SERVER_SOURCES 
    "${CMAKE_SOURCE_DIR}/sources/server/*.cc"
)

add_library(core OBJECT ${CORE_SOURCES})
target_include_directories(core PUBLIC ${INCLUDE_DIR})

add_executable(server ${SERVER_SOURCES})
target_link_libraries(server core)

add_executable(client ${CLIENT_SOURCES})
target_link_libraries(client core)

