cmake_minimum_required(VERSION 3.5.0)

project(robot)

find_package(rclcpp REQUIRED)
find_package(scion_types REQUIRED)
find_package(std_srvs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)

find_library(ROBOT_TYPES robot_types)
find_library(CAN_INTERFACE can_interface)
find_library(PROCESSES processes)

file(GLOB SOURCES src/*.cpp)
include_directories(include)

add_library(${PROJECT_NAME} STATIC ${SOURCES})

add_executable(${PROJECT_NAME}_exec 
    main/main.cpp
)

target_link_libraries(${PROJECT_NAME}
    ${ROBOT_TYPES}
    ${CAN_INTERFACE}
    ${PROCESSES}    
)

target_link_libraries(${PROJECT_NAME}_exec
    ${PROJECT_NAME}
)

ament_target_dependencies(robot scion_types rclcpp std_srvs std_msgs sensor_msgs)

install(TARGETS ${PROJECT_NAME} DESTINATION lib)
install(TARGETS ${PROJECT_NAME}_exec DESTINATION bin/robot)

file(GLOB HEADERS include/*.hpp)

install(FILES ${HEADERS} DESTINATION include/robot_libraries)