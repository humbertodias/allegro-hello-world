cmake_minimum_required(VERSION 3.7)
project(main)
add_executable(${PROJECT_NAME} main-win.cpp)

# cmake modules
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

# Libraries to link with
set(Alleg_Libraries "alleg")

# Find Allegro
find_package(Alleg4 4)

# Add directories to the include search path
target_include_directories(${PROJECT_NAME} PRIVATE ${ALLEGRO_INCLUDE_DIR})

# Link with dependencies
target_link_libraries(${PROJECT_NAME} ${Alleg_Libraries})