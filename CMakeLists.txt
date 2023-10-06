cmake_minimum_required(VERSION 3.5.0)

project(robot)

file(GLOB SOURCES src/*.cpp)

include_directories(include)

add_library(${PROJECT_NAME} SHARED ${SOURCES})

install(TARGETS ${PROJECT_NAME} DESTINATION lib)

file(GLOB HEADERS include/*.hpp)

install(FILES ${HEADERS} DESTINATION include/${PROJECT_NAME})