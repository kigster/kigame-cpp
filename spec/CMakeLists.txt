cmake_minimum_required(VERSION 2.8.11)

INCLUDE (CMakeForceCompiler)

IF(APPLE)
  set(CMAKE_MACOSX_RPATH ON)
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -stdlib=libc++")
ELSEIF (WIN32 OR UNIX)
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
ENDIF(APPLE)

set(PROJECT_SPECS "${PROJECT_LIBRARY}-specs")

project(${PROJECT_SPECS})
include_directories(ccspec/include)
add_subdirectory(ccspec/src)

file(GLOB SPEC_FILES
        "*_spec.cc"
        )

enable_testing()
add_executable(${PROJECT_SPECS} ${SPEC_FILES})
target_link_libraries(${PROJECT_SPECS} ccspec ${PROJECT_LIBRARY})
set_target_properties(${PROJECT_SPECS} PROPERTIES LINKER_LANGUAGE CXX)
add_test(NAME ${PROJECT_SPECS} COMMAND ${PROJECT_SPECS})
install(TARGETS ${PROJECT_SPECS} DESTINATION ${BIN_DIR})
