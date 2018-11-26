cmake_minimum_required(VERSION 2.8.11)
set(APP_NAME "kigame")

project(${APP_NAME} C CXX)

include(CMakeForceCompiler)

if (APPLE)
    set(CMAKE_MACOSX_RPATH ON)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -stdlib=libc++")
elseif (WIN32 OR UNIX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
endif (APPLE)

set(BIN_DIR ${CMAKE_SOURCE_DIR}/bin)
set(LIB_DIR ${CMAKE_SOURCE_DIR}/lib)
set(INC_DIR ${CMAKE_SOURCE_DIR}/include)

file(MAKE_DIRECTORY ${BIN_DIR} ${LIB_DIR} ${INC_DIR})

add_subdirectory(src)
add_subdirectory(spec)


