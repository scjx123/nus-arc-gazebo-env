
# NUS ARC Summer Project 2020

 1. Brief Overview 
 2. Gazebo Environment
 3. Gazebo Robot 
 4. Dependencies 

## 1. Brief Overview
This documentation includes a list of commands to initiate the simulation of an indoor office environment in Gazebo, using the Clearpath Husky Robot. 

2. Gazebo Environment
start with roscore 

## 3. Gazebo Robot
Upon launching the environment, the following section will cover spawning husky into the gazebo, launching it in Rviz and controlling it with Teleop commands. 

**Spawn Husky into Gazebo**
To spawn husky, ensure that you have sourced the src file to devel/setup. Then, simply use the following command:

    roslaunch robot_gazebo spawn_husky.launch

**Launching in Rviz**
Once husky is launched inside Gazebo, you can launch another terminal and proceed to visualize it in Rviz using this command:

    roslaunch robot_rviz view_robot.launch

**Control Husky with Teleop**
Finally, to control it's movement inside Gazebo, launch another terminal to control it using the following command:

    rosrun random_husky_driver random_driver
An alternative to this would be 

    rosrun teleop_twist_keyboard teleop_twist_keyboard.py
And if you launch using the first method, you could control the husky intuitively using WASD keys, or alternatively, the instruction to control husky is printed in the terminal if you use the second method.

## 4. Initiating SLAM 
To initiate SLAM in husky, we have to first convert the 3D pointcloud data collected from the Velodyne-16 into a 2D laserscan data. To do that, we could using the following command: 

    roslaunch pointcloud_to_laserscan sample_node.launch
 
Next, open up a new terminal, launch your algorithm for testing. By default, let's use Gmapping. It is located in the *robot_navigation* folder, and we can initiate it using this command: 

    roslaunch robot_navigation gmapping_demo.launch


<!--stackedit_data:
eyJoaXN0b3J5IjpbLTcwMTAzODc2MywtOTI1ODY3NjM2LDE4Nj
I1MDk3MDVdfQ==
-->