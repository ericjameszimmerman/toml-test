cmake_minimum_required(VERSION 3.25.0)
project(tomlctest VERSION 1.0.0)

# Disable exceptions and RTTI
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(-fno-exceptions -fno-rtti)
elseif(MSVC)
    add_compile_options(/EHsc- /GR-)
endif()

# Set C++17 as the standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} main.cpp)

add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_SOURCE_DIR}/config.toml
            ${CMAKE_BINARY_DIR}/config.toml)
