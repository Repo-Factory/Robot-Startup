#include "robot.hpp"

#define KILL_MODE 0x04

Robot::Robot(const Configuration& configuration) : Node("Robot"), configuration{configuration}
{
    submarine_state_sub = this->create_subscription<scion_types::msg::SubState>("submarine_state", 10, [this](const scion_types::msg::SubState::SharedPtr msg)
    {
        if (msg->host_mode == KILL_MODE)
            this->killRobot();
    });
}

void Robot::killRobot()
{
    Process::killProcesses(*this->childProcesses);
    exit(EXIT_SUCCESS);
}
