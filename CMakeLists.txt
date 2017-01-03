cmake_minimum_required(VERSION 2.8)
include(ExternalProject)
project(whisper-protocol)
if(APPLE)
set(CMAKE_MACOSX_RPATH 1)
endif()
set(INSTALL_PREFIX /usr)
project(damo)

set(jnxlibc_PREFIX "${CMAKE_CURRENT_BINARY_DIR}/jnxlibc")
set(jnxlibc_INSTALL_DIR ${CMAKE_INSTALL_PREFIX})
set(jnxlibc_CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${jnxlibc_INSTALL_DIR})

#ExternalProject_Add(jnxlibc-project
  #PREFIX ${jnxlibc_PREFIX}
  #GIT_REPOSITORY https://github.com/AlexsJones/jnxlibc.git
  #INSTALL_DIR ${jnxlibc_INSTALL_DIR}
  #CMAKE_ARGS ${jnxlibc_CMAKE_ARGS}
  #BUILD_COMMAND make
  #INSTALL_COMMAND sudo make install
  #)

#add_library(jnxlibc SHARED IMPORTED)
#add_library(jnxlibcs STATIC IMPORTED)

add_subdirectory(src/game)
add_subdirectory(src/utils)
add_subdirectory(src/engine)
add_subdirectory(src/engine/actor)
add_subdirectory(src/engine/scene)
add_subdirectory(src/engine/landscape)

include_directories(${PROJECT_INC_DIR}src/game)
#include_directories(${PROJECT_INC_DIR}src/game/actors)
include_directories(${PROJECT_INC_DIR}src/utils)
include_directories(${PROJECT_INC_DIR}src/engine)
include_directories(${PROJECT_INC_DIR}src/engine/actor)
include_directories(${PROJECT_INC_DIR}src/engine/scene)
include_directories(${PROJECT_INC_DIR}src/engine/landscape)

if(APPLE)
  # set_property(TARGET jnxlibc PROPERTY IMPORTED_LOCATION ${jnxlibc_INSTALL_DIR}/lib/libjnxc.dylib)
else()
  #  set_property(TARGET jnxlibc PROPERTY IMPORTED_LOCATION ${jnxlibc_INSTALL_DIR}/lib/libjnxc.so)
endif()
#set_property(TARGET jnxlibcs PROPERTY IMPORTED_LOCATION ${jnxlibc_INSTALL_DIR}/lib/libjnxc.a)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++14")

add_executable(damo ${SOURCE})

find_package(SDL2 REQUIRED)

#add_dependencies(damo jnxlibc-project)

include_directories(${SDL2_INCLUDE_DIR})

#target_link_libraries(damo -lSDL2_image -lSDL2 -lpthread jnxlibc)
target_link_libraries(damo -lSDL2_image -lSDL2 -lpthread -ljnxc)

