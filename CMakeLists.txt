cmake_minimum_required(VERSION 2.8)
set(INSTALL_PREFIX /usr)
project(damo)

execute_process(COMMAND git submodule init)
execute_process(COMMAND git submodule update)
execute_process(COMMAND cmake . WORKING_DIRECTORY jnxlibc)
execute_process(COMMAND make . WORKING_DIRECTORY jnxlibc)
execute_process(COMMAND sudo make install . WORKING_DIRECTORY jnxlibc)

add_subdirectory(src/main)
add_subdirectory(src/utils)
add_subdirectory(src/engine)
add_subdirectory(src/engine/actor)
add_subdirectory(src/engine/scene)
add_subdirectory(src/engine/landscape)

include_directories(${PROJECT_INC_DIR}src/main)
include_directories(${PROJECT_INC_DIR}src/utils)
include_directories(${PROJECT_INC_DIR}src/engine)
include_directories(${PROJECT_INC_DIR}src/engine/actor)
include_directories(${PROJECT_INC_DIR}src/engine/scene)
include_directories(${PROJECT_INC_DIR}src/engine/landscape)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++14")

add_executable(damo ${SOURCE})

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIR})

target_link_libraries(damo -lSDL2_image -lSDL2 -lpthread -ljnxc)

