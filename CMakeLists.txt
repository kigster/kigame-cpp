cmake_minimum_required(VERSION 2.8.11)
set(PROJECT_LIBRARY "kigame")

project(${PROJECT_LIBRARY} C CXX)

IF(APPLE)
  set(CMAKE_MACOSX_RPATH ON)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -stdlib=libc++")
ELSEIF (WIN32 OR UNIX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
ENDIF(APPLE)

set(BIN_DIR ${CMAKE_SOURCE_DIR}/bin)
set(LIB_DIR ${CMAKE_SOURCE_DIR}/lib)
set(INC_DIR ${CMAKE_SOURCE_DIR}/include)

file(MAKE_DIRECTORY ${BIN_DIR} ${LIB_DIR} ${INC_DIR})

include_directories(include)
include_directories(${LIB_DIR})

set(SOURCE_FILES
    src/Move.cpp
    src/Board.cpp
    src/Player.cpp
    src/Game.cpp
)

file(GLOB HEADER_FILES "src/*.h")

add_library(${PROJECT_LIBRARY} ${HEADER_FILES} ${SOURCE_FILES})
install(TARGETS ${PROJECT_LIBRARY} DESTINATION ${LIB_DIR})
set_target_properties(${PROJECT_LIBRARY} PROPERTIES LINKER_LANGUAGE CXX)

add_subdirectory(spec)


