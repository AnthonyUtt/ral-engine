cmake_minimum_required(VERSION 3.0)

# Setting version and project name
set(PROJECT_VERSION "0.1")
project(ral-core VERSION ${PROJECT_VERSION})

# For Windows builds, setting CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

# Setting source directories
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
file(GLOB SOURCES ${SRC_DIR}/init/*.cpp)

# Creating library target
add_library(${PROJECT_NAME} SHARED)
target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})

# Naming convention for output .so files
set_target_properties(${PROJECT_NAME}
PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION}
)

# Compiler-specific flags
if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU")
    # g++
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra)
    # Setting definition to export symbols
    target_compile_definitions(${PROJECT_NAME} PRIVATE GNU_EXPORT)
elseif(${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
    # MSVC
    target_compile_options(${PROJECT_NAME} PRIVATE /EHsc /MTd /W2 /c)
    # Setting definition to export symbols
    target_compile_definitions(${PROJECT_NAME} PRIVATE WIN_EXPORT)
endif()