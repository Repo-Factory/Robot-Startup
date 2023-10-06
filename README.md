# Robot Entry Point

Think of this as Custom Launch System instead of ROS2 Launch

## Description

ROS2 Launch system causes some issues because it's hard to keep track of child processes and send global data.
This parent process will act as a bridge between all children nodes.

## Directories ##

- `main` - I recommend reading the comments here  

### Dependencies

* CAN_Interface
* Robot Types
* Processes Library

### Install/Linking

* If you get a shared_library error (can't load .so file) do this command LD_LIBRARY_PATH=/usr/local/lib
* Make sure that path is here echo $LD_LIBRARY_PATH

### Executing program

Run with robot_exec. Make sure there is a config file in /usr/local/config

## Authors

[@Strix Elixel](https://github.com/Repo-Factory/) Github
