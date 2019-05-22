################ standard cmake script ################
cmake_minimum_required(VERSION 3.0)
project(Test C)

set(CMAKE_C_STANDARD 11)

# OpenMP flags
find_package(OpenMP REQUIRED)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    
add_executable(s target/example.c)

################ clava-specific instructions ################
# Required if CMake plugin is not installed
# Download CMake plugin from: https://github.com/specs-feup/clava/tree/master/CMake
#set(Clava_DIR "<FOLDER WITH CLAVA CMAKE PLUGIN>")

find_package(Clava REQUIRED)

clava_weave(s resolver.lara)
