cmake_minimum_required(VERSION 2.8.11)


IF(APPLE)
  set(CMAKE_MACOSX_RPATH ON)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -stdlib=libc++")
ELSEIF (WIN32 OR UNIX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
ENDIF(APPLE)

set(PROJECT_LIBRARY "binary-tree")

set(BIN_DIR ${CMAKE_SOURCE_DIR}/bin)
set(LIB_DIR ${CMAKE_SOURCE_DIR}/lib)
set(INC_DIR ${CMAKE_SOURCE_DIR}/include)
file(MAKE_DIRECTORY ${BIN_DIR} ${LIB_DIR} ${INC_DIR})

project(${PROJECT_LIBRARY})

include_directories(include)

file(GLOB INCLUDE_FILES
        "include/*.h"
        )

file(GLOB SOURCE_FILES
        "src/*.cc"
        )

add_subdirectory(spec)
add_library(${PROJECT_LIBRARY} ${SOURCE_FILES} ${INCLUDE_FILES})
install(TARGETS ${PROJECT_LIBRARY} DESTINATION ${LIB_DIR})
