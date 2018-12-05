include(CMakeToolsHelpers OPTIONAL)
cmake_minimum_required(VERSION 2.8)

project(vegnews)

aux_source_directory(. DIR_SRCS)
add_executable(vegnews ${DIR_SRCS}) 