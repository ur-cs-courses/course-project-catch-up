cmake_minimum_required(VERSION 3.16)
project(libRoom)

include(dependencies.cmake)

add_library(libRoom
  src/Room.cpp
)

target_include_directories(libRoom
  PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
)

target_link_libraries(libRoom
  fmt::fmt
)

add_subdirectory(app)
