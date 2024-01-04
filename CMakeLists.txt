cmake_minimum_required(VERSION 3.20)
project(lab2)

set(CMAKE_CXX_STANDARD 14)

find_package(glfw3 3.3 REQUIRED)
find_package(OpenGL REQUIRED)

set(ASSIMP_DIR assimp/)
set(GLM_DIR glm/)
add_subdirectory(${ASSIMP_DIR})
add_subdirectory(${GLM_DIR})
include_directories(${STB_DIR})
include_directories(${ASSIMP_DIR}/include)
include_directories(glfw/include)
include_directories(glad/include)

add_executable(lab2 main.cpp glad/src/glad.c
        files/Shader/Shader.cpp
        files/Mesh/Mesh.cpp
        files/Model/Model.cpp
        files/Object/Object.cpp
        files/Cubemap/Cubemap.cpp)

target_link_libraries(lab2 glfw)
target_link_libraries(lab2 OpenGL::GL)
target_link_libraries(lab2 assimp)
target_link_libraries(lab2 glm)
