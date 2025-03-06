cmake_minimum_required(VERSION 3.10...3.31.5)
project("mineraft_toolbox")
find_package(shadowhook REQUIRED CONFIG)
file(GLOB TOOLBOX_SOURCES
        "native-lib.cpp"
        "include/*.cpp"
        "include/*/*.cpp"
        "include/*/*/*.cpp"
        "src/*.cpp"
        "src/*/*.cpp"
        "src/*/*/*.cpp"
)
set(TOOLBOX_INCLUDE_DIRS
    "include"
    "src"
    "."
)
set(TOOLBOX_SHARED_LIBRARIES
    android
        log
        shadowhook::shadowhook
)
set(TOOLBOX_STATIC_LIBRARIES
        frida-gum
        keystone
)
set(TOOLBOX_STATIC_LINK_DIRS
        "include/Keystone/"
        "include/frida-gum/"
)
link_directories(${TOOLBOX_STATIC_LINK_DIRS})
include_directories(${TOOLBOX_INCLUDE_DIRS})
add_library(${CMAKE_PROJECT_NAME} SHARED ${TOOLBOX_SOURCES})
target_link_libraries(${CMAKE_PROJECT_NAME} ${TOOLBOX_SHARED_LIBRARIES})
target_link_libraries(${CMAKE_PROJECT_NAME} ${TOOLBOX_STATIC_LIBRARIES})