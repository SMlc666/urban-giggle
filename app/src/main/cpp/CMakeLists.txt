cmake_minimum_required(VERSION 3.10...3.31.5)
project("mineraft_toolbox")
find_package(shadowhook REQUIRED CONFIG)
file(GLOB TOOLBOX_SOURCES
        "src/*.cpp"
        "src/*/*.cpp"
)
set(TOOLBOX_INCLUDE_DIRS
    "include"
    "src"
    "."
)
set(TOOLBOX_LIBRARIES
    android
        log
        shadowhook::shadowhook
)
include_directories(${TOOLBOX_INCLUDE_DIRS})
add_library(${CMAKE_PROJECT_NAME} SHARED
        ${TOOLBOX_SOURCES}
        native-lib.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME} ${TOOLBOX_LIBRARIES})