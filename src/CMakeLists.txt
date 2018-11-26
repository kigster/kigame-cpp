cmake_minimum_required(VERSION 2.8.11)

set(SOURCE_FILES
        Move.cpp
        Board.cpp
        Player.cpp
        Game.cpp
        )

set(HEADER_FILES
        Move.h
        Board.h
        Player.h
        Game.h
        )

add_library(${APP_NAME} 
  ${HEADER_FILES} 
  ${SOURCE_FILES})

set_target_properties(${APP_NAME} 
  PROPERTIES 
  CXX_STANDARD 17
  CXX_EXTENSIONS OFF
  LINKER_LANGUAGE CXX)

install(TARGETS ${APP_NAME} DESTINATION ${LIB_DIR})
install(FILES ${HEADER_FILES} DESTINATION ${INC_DIR})



