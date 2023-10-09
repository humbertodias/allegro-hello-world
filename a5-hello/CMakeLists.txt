cmake_minimum_required(VERSION 3.7)
project(main)

# Allegro 5
include(FetchContent)
FetchContent_Declare(
        allegro5
        GIT_REPOSITORY https://github.com/liballeg/allegro5.git
        GIT_TAG        5.2.8.0
)
FetchContent_GetProperties(allegro5)
if(NOT allegro5_POPULATED)
    FetchContent_Populate(allegro5)
    if (MSVC)
        set(SHARED ON)
    else()
        set(SHARED OFF)
    endif()
    set(WANT_TESTS OFF)
    set(WANT_EXAMPLES OFF)
    set(WANT_DEMO OFF)
    set(WANT_MONOLITHIC ON)
    add_subdirectory(${allegro5_SOURCE_DIR} ${allegro5_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

# main code
add_executable(${PROJECT_NAME} main-win.cpp)

# include
target_include_directories(${PROJECT_NAME} PUBLIC ${allegro5_SOURCE_DIR}/include ${allegro5_BINARY_DIR}/include)
# Link with dependencies
target_link_libraries(${PROJECT_NAME} PRIVATE allegro_main allegro_font allegro_primitives)

# These include files are typically copied into the correct places via allegro's install
# target, but we do it manually.
file(COPY ${allegro5_SOURCE_DIR}/addons/font/allegro5/allegro_font.h
        DESTINATION ${allegro5_SOURCE_DIR}/include/allegro5
)
file(COPY ${allegro5_SOURCE_DIR}/addons/primitives/allegro5/allegro_primitives.h
        DESTINATION ${allegro5_SOURCE_DIR}/include/allegro5
)