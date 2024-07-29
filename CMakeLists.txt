cmake_minimum_required(VERSION 3.20)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(madrun VERSION 1.0 LANGUAGES CXX)

include_directories(include)

file(GLOB SOURCES src/*.cpp)

include(FindPkgConfig)
find_package(PkgConfig)

pkg_check_modules(Gtkmm3 REQUIRED gtkmm-3.0)

add_executable(madrun ${SOURCES})

target_link_libraries(madrun ${Gtkmm3_LIBRARIES} pthread)
target_include_directories(madrun PUBLIC ${Gtkmm3_INCLUDE_DIRS})
target_compile_options(madrun PUBLIC ${Gtkmm3_CFLAGS_OTHER})
