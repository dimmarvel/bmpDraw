cmake_minimum_required(VERSION 3.26)

project(drawBmp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(PkgConfig REQUIRED)

pkg_check_modules(SDL2 REQUIRED sdl2)
pkg_check_modules(SDL2_IMAGE REQUIRED SDL2_image)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

add_executable(drawBmp main.cpp draw.cpp)

target_link_libraries(drawBmp ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

if (CMAKE_COMPILER_IS_GNUCXX)
    target_compile_options(drawBmp PRIVATE -Wall -Wextra -pedantic)
endif()
