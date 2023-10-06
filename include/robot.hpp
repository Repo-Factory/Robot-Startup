#pragma once
#include <robot_libraries/robot_types.hpp>
#include <robot_libraries/can_interface.hpp>
#include <robot_libraries/processes.hpp>
#include "configuration.hpp"

class Robot : public rclcpp::Node
{
    public: 
        Robot(const Configuration& configuration);
        void killRobot();
        ///////////////////////////////////////////////////
        std::string getName() const {return this->name;}
        int getMotorCount() const {return this->motor_count;}
        RTL::matrix_t getThrustMapper() const {return this->thrust_mapper;}
        const Configuration& getConfiguration() const {return this->configuration;}
        std::shared_ptr<std::vector<pid_t>> getChildren() const {return this->childProcesses;}
        ///////////////////////////////////////////////////
    protected:
        std::string name;
        int motor_count;
        RTL::matrix_t thrust_mapper;
        const Configuration& configuration;
        RTL::sub_state_sub_t submarine_state_sub;
        std::shared_ptr<std::vector<pid_t>> childProcesses = std::make_shared<std::vector<pid_t>>();
};
