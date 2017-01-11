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
add_subdirectory(src/game/actors)
add_subdirectory(src/utils)
add_subdirectory(src/engine)
add_subdirectory(src/engine/events)
add_subdirectory(src/engine/actors)
add_subdirectory(src/engine/scenes)
add_subdirectory(src/engine/landscapes)
add_subdirectory(src/engine/loaders)

include_directories(${PROJECT_INC_DIR}src/game)
include_directories(${PROJECT_INC_DIR}src/game/actors)
include_directories(${PROJECT_INC_DIR}src/utils)
include_directories(${PROJECT_INC_DIR}src/engine)
include_directories(${PROJECT_INC_DIR}src/engine/events)
include_directories(${PROJECT_INC_DIR}src/engine/actors)
include_directories(${PROJECT_INC_DIR}src/engine/scenes)
include_directories(${PROJECT_INC_DIR}src/engine/landscapes)
include_directories(${PROJECT_INC_DIR}src/engine/loaders)

if(APPLE)
  # set_property(TARGET jnxlibc PROPERTY IMPORTED_LOCATION ${jnxlibc_INSTALL_DIR}/lib/libjnxc.dylib)
else()
  #  set_property(TARGET jnxlibc PROPERTY IMPORTED_LOCATION ${jnxlibc_INSTALL_DIR}/lib/libjnxc.so)
endif()
#set_property(TARGET jnxlibcs PROPERTY IMPORTED_LOCATION ${jnxlibc_INSTALL_DIR}/lib/libjnxc.a)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++14 -g")

add_executable(damo ${SOURCE})

find_package(SDL2 REQUIRED)

#add_dependencies(damo jnxlibc-project)

include_directories(${SDL2_INCLUDE_DIR})

#target_link_libraries(damo -lSDL2_image -lSDL2 -lpthread jnxlibc)
target_link_libraries(damo -lSDL2_image -lSDL2 -lpthread -ljnxc)

