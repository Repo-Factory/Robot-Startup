#include <stdio.h>
#include <stdlib.h>
#include "components.hpp"
#include "gui_listener_node.hpp"
#include "controller_node.hpp"
#include "unified_can_driver.hpp"
#include "pid_node.hpp"

namespace
{
    #define NODES_MAP_KEY "nodes"
}

namespace
{
    void createComponent(const std::string& component_name, const std::vector<pid_t>& childProcesses)
    {
        Process::createChildProgram(childProcesses, component_name, NULL);        
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

void Components::InitChildren(const Robot& robot, const std::vector<pid_t>& childProcesses)
{
    launchNodesFromConfig(getNodesToEnable(robot), childProcesses);
}
