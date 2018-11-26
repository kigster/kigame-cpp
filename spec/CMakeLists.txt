cmake_minimum_required(VERSION 2.8.11)

# https://cmake.org/cmake/help/latest/prop_tgt/CXX_STANDARD.html
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(APP_SPECS "${APP_NAME}-specs")

project(${APP_SPECS})

include_directories(ccspec/include)
add_subdirectory(ccspec/src)

file(GLOB SPEC_FILES
        "*_spec.cc"
        )

enable_testing()
add_executable(${APP_SPECS} ${SPEC_FILES})
target_link_libraries(${APP_SPECS} ccspec ${APP_NAME})

set_target_properties(${APP_SPECS}
  PROPERTIES
  CXX_STANDARD 17
  CXX_EXTENSIONS OFF
  LINKER_LANGUAGE CXX)

add_test(NAME ${APP_SPECS} COMMAND ${APP_SPECS})

install(TARGETS ${APP_SPECS} DESTINATION ${BIN_DIR})
