cmake_minimum_required(VERSION 2.8.11)
set(APP_NAME "kigame")

project(${APP_NAME} C CXX)

if (APPLE)
  set(CMAKE_MACOSX_RPATH ON)
endif (APPLE)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  message(" >>> Clang Compatible compiler detected.")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -stdlib=libc++")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  message(" >>> GNU Compatible compiler detected.")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
else ()
  message(" >>> Neither CLang nor GNU compiler found.")
  message(" >>> The compiler is: ${CMAKE_CXX_COMPILER_ID}")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
endif()

message(" >>> CMAKE_CXX_FLAGS=${CMAKE_CXX_FLAGS}")

set(BIN_DIR ${CMAKE_SOURCE_DIR}/bin)
set(LIB_DIR ${CMAKE_SOURCE_DIR}/lib)
set(INC_DIR ${CMAKE_SOURCE_DIR}/include)

file(MAKE_DIRECTORY ${BIN_DIR} ${LIB_DIR} ${INC_DIR})

add_subdirectory(src)
add_subdirectory(spec)


