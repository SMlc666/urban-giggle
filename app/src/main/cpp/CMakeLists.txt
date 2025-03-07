cmake_minimum_required(VERSION 3.10...3.31.5)
project("mineraft_toolbox")
include(FetchContent)
find_package(shadowhook REQUIRED CONFIG)
FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
FetchContent_MakeAvailable(json)
file(GLOB TOOLBOX_SOURCES
        "native-lib.cpp"
        "include/KittyMemory/*.cpp”
        “include/Lua/*.c"
        "src/Test/*.cpp"
        "src/Minecraft/*.cpp"
        "src/Minecraft/Hooks/*.cpp"
        "src/MemTool/*.cpp"
        "src/Instance/*.cpp"
        "src/Init/*.cpp"
        "src/Module/*.cpp"
        "src/Module/Manager/*.cpp"
        "src/Script/*.cpp"
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
        nlohmann_json::nlohmann_json
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