#include <stdio.h>
#include <stdlib.h>
#include "components.hpp"

namespace
{
    #define NODES_MAP_KEY "nodes"
    #define NULL_TERMINATOR '\0'
}

namespace
{
    void createComponent(const std::string& component_name, std::vector<pid_t>& childProcesses)
    {
        Process::createChildProgram(childProcesses, const_cast<char*>(component_name.c_str()), NULL);        
    }

    void launchNodesFromConfig(const std::vector<std::string>& nodes_to_enable, std::vector<pid_t>& childProcesses)
    {
        for (const std::string& component_name : nodes_to_enable) {
            createComponent(component_name, childProcesses);
        }
    }

    const std::vector<std::string> getNodesToEnable(const Robot& robot)
    {
        return robot.getConfiguration().getJsonString()[NODES_MAP_KEY];
    }
}

void Components::InitChildren(const Robot& robot, std::vector<pid_t>& childProcesses)
{
    launchNodesFromConfig(getNodesToEnable(robot), childProcesses);
}
