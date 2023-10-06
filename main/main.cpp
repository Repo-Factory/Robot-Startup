/*******************************************************************************
 * @author Strix Elixel
 * @name robot_exec
 * 
 * @brief Entry point for parent process of robot
 * 
 * @description Think of this as a custom launch file for the robot
 * The program will look at the config file located at /usr/local/config/robot.json
 * It will fork a process for each executable given there, allowing the user to launch
 * multiple nodes. The benefit over the launch file is you have a parent thread to watch
 * the children threads if they need to be killed at any time or pass any information between each other
 * 
 * Relevant entities
 * - Various Robots
 *      - Junebug
 *      - Percy
 *      - Presumably could add Scion
 * - Robot Factory
 *      - Instantiates correct robot type for inheritance and making codebase flexible with Junebug and Percy
 * - Components
 *      - Forks Processes for each child program
 * 
 * See cpp file of each for more details in each respective area
 * 
 ******************************************************************************/

#include "robot.hpp"
#include "robot_factory.hpp"
#include "components.hpp"
#include "rclcpp/rclcpp.hpp"

#define CONFIG_PATH "/usr/local/config/robot.json"

std::shared_ptr<Robot> initRobot(const Configuration& configuration)
{
    std::shared_ptr<Robot> robot = RobotFactory::createRobot(configuration);
    Components::InitChildren(*robot, *robot->getChildren());
    return robot;
}

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);
    std::unique_ptr<Configuration> configuration = std::make_unique<Configuration>(CONFIG_PATH); // Declared in CMakeLists.txt
    std::shared_ptr<Robot> robot = initRobot(*configuration);
    rclcpp::spin(robot);
    rclcpp::shutdown();
    return EXIT_SUCCESS;
}