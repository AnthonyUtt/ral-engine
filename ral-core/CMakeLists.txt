cmake_minimum_required(VERSION 3.0)

# Setting version and project name
set(PROJECT_VERSION "0.1")
project(ral-core VERSION ${PROJECT_VERSION})

# For Windows builds, setting CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

# Setting source directories
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
file(GLOB SOURCES ${SRC_DIR}/init/*.cpp ${SRC_DIR}/sys/*.cpp)

# Setting third-party library directories
set(LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib")
set(GLFW_DIR "${LIB_DIR}/glfw")
set(GL3W_DIR "${LIB_DIR}/gl3w")
set(LOG_DIR "${LIB_DIR}/ral-log")

# Disabling unwanted GLFW features
set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "Build the GLFW example programs")
set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "Build the GLFW test programs")
set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "Build the GLFW documentation")
set(GLFW_INSTALL OFF CACHE INTERNAL "Generate installation target")

# Adding target subdirectories
add_subdirectory(${GLFW_DIR})
add_subdirectory(${GL3W_DIR})
add_subdirectory(${LOG_DIR})

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
    target_compile_options(${PROJECT_NAME} PRIVATE -g -Wall -Wextra)
    # Setting definition to export symbols
    target_compile_definitions(${PROJECT_NAME} PRIVATE GNU_EXPORT)
elseif(${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
    # MSVC
    target_compile_options(${PROJECT_NAME} PRIVATE /EHsc /MTd /W2 /c)
    # Setting definition to export symbols
    target_compile_definitions(${PROJECT_NAME} PRIVATE WIN_EXPORT)
endif()

# GLFW
target_link_libraries(${PROJECT_NAME} "glfw" "${GLFW_LIBRARIES}")
target_include_directories(${PROJECT_NAME} PRIVATE "${GLFW_DIR}/include")
target_compile_definitions(${PROJECT_NAME} PRIVATE "GLFW_INCLUDE_NONE")

# gl3w
target_link_libraries(${PROJECT_NAME} "gl3w")
target_include_directories(${PROJECT_NAME} PRIVATE "${GL3W_DIR}/include")

# ral-log
target_link_libraries(${PROJECT_NAME} "ral-log")
target_include_directories(${PROJECT_NAME} PRIVATE "${LOG_DIR}/include")