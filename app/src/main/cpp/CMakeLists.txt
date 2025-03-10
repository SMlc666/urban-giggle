cmake_minimum_required(VERSION 3.10...3.31.5)
project("mineraft_toolbox")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include(FetchContent)
find_package(shadowhook REQUIRED CONFIG)
FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
FetchContent_MakeAvailable(json)
FetchContent_Declare(GSL
        GIT_REPOSITORY "https://github.com/microsoft/GSL"
        GIT_TAG "v4.2.0"
        GIT_SHALLOW ON
)
FetchContent_MakeAvailable(GSL)
file(GLOB TOOLBOX_SOURCES
        #main sources
        "native-lib.cpp"
        #Package sources
        "include/KittyMemory/*.cpp"
        "include/Lua/*.c"
        "include/imgui/*.cpp"
        "include/imgui/backends/*.cpp"
        #Project sources
        "src/Test/*.cpp"
        "src/Minecraft/*.cpp"
        "src/Minecraft/Hooks/*.cpp"
        "src/Minecraft/Event/*.cpp"
        "src/Minecraft/Event/Events/*.cpp"
        "src/MemTool/*.cpp"
        "src/Instance/*.cpp"
        "src/Instance/jni/*.cpp"
        "src/Init/*.cpp"
        "src/Module/*.cpp"
        "src/Module/Manager/*.cpp"
        "src/Module/Config/*.cpp"
        "src/Module/GUI/*.cpp"
        "src/Module/GUI/Draw/*.cpp"
        "src/Module/GUI/Draw/ImGuiDraw/*.cpp"
        "src/Module/GUI/Draw/Touch/*.cpp"
        "src/Module/GUI/Controls/*.cpp"
        "src/Module/GUI/Manager/*.cpp"
        "src/Module/Event/*.cpp"
        "src/Script/*.cpp"
        "src/Utils/*.cpp"
        
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
        EGL
        GLESv3
)
set(TOOLBOX_STATIC_LIBRARIES
        keystone
        nlohmann_json::nlohmann_json
        Microsoft.GSL::GSL
)
set(TOOLBOX_STATIC_LINK_DIRS
        "include/Keystone/"
)
link_directories(${TOOLBOX_STATIC_LINK_DIRS})
include_directories(${TOOLBOX_INCLUDE_DIRS})
add_library(${CMAKE_PROJECT_NAME} SHARED ${TOOLBOX_SOURCES})
target_link_libraries(${CMAKE_PROJECT_NAME} ${TOOLBOX_SHARED_LIBRARIES})
target_link_libraries(${CMAKE_PROJECT_NAME} ${TOOLBOX_STATIC_LIBRARIES})