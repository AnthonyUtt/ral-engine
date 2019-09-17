# Setting required version
cmake_minimum_required(VERSION 3.0)

# Setting project version and name
set(PROJECT_VERSION "0.1")
project(game-demo VERSION ${PROJECT_VERSION})

# Setting source directories
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/app/src")
file(GLOB SOURCES ${SRC_DIR}/main.cpp)

# Adding engine library files
set(ENGINE_LIB "${CMAKE_CURRENT_SOURCE_DIR}/ral-core")
add_subdirectory(${ENGINE_LIB})

# Building project data
add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE "${SRC_DIR}")
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)

# Linking library files
target_link_libraries(${PROJECT_NAME} "ral-core")
target_include_directories(${PROJECT_NAME} PRIVATE "${ENGINE_LIB}/include")