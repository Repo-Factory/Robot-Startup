#include "robot.hpp"

Robot::Robot(const Configuration& configuration) : Node("Robot"), configuration{configuration}
{
    submarine_state_sub = this->create_subscription<scion_types::msg::SubState>("submarine_state", 10, [this](const scion_types::msg::SubState::SharedPtr msg)
    {
        this->killRobot();
    });
}

void Robot::killRobot()
{
    Process::killProcesses(*this->childProcesses);
    exit(EXIT_SUCCESS);
}
