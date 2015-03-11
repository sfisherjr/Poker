cmake_minimum_required(VERSION 2.8)

project(poker)

FILE(GLOB SRCFILES src/*.cpp)

add_executable(poker ${SRCFILES})