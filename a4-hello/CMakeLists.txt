cmake_minimum_required(VERSION 3.7)
project(main)
add_executable(main main.cpp)

# cmake modules
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/../cmake")

# Libraries to link with
# set(Alleg_Libraries Alleg::Allegro Alleg::Main Alleg::Color Alleg::Memfile Alleg::Primitives Alleg::Font)
set(Alleg_Libraries "alleg")

# Allegro Components to find and Allegro targets to link with
# set(Alleg_Components Main Color Memfile Primitives Font)
#set(Alleg_Components "")

# Find Allegro
find_package(Alleg4 4)

# Add directories to the include search path
target_include_directories(main PRIVATE ${ALLEGRO_INCLUDE_DIR})
# Link with dependencies
target_link_libraries(main ${Alleg_Libraries})