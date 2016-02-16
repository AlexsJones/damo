cmake_minimum_required(VERSION 2.8)
set(INSTALL_PREFIX /usr)
project(damo)

add_subdirectory(src/main)
add_subdirectory(src/utils)
add_subdirectory(src/engine)

include_directories(${PROJECT_INC_DIR}src/main)
include_directories(${PROJECT_INC_DIR}src/utils)
include_directories(${PROJECT_INC_DIR}src/engine)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

add_executable(damo ${SOURCE})

find_package(SDL REQUIRED)

include_directories(${SDL_INCLUDE_DIR})

target_link_libraries(damo ${SDL2_LIBRARIES})

