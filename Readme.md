
# NUS ARC Summer Project 2020
![Investing in the Robotics Sector – CHRONICLING THE ROBOT INDUSTRY](https://robotrabbi.com/wp-content/uploads/2015/03/clearpath-robotics-husky-e1426720202779-1940x1092.jpg)

 **1. Brief Overview 
 2. Gazebo Environment
 3. Gazebo Robot 
 4. Dependencies** 

## 1. Brief Overview
This documentation includes a list of commands to initiate the simulation of an indoor office environment in Gazebo, using the Clearpath Husky Robot. 

## 2. Gazebo Environment

To begin, launch a terminal for roscore. Next, launch another terminal and source the devel/setup.bash in for the file containing the source folder. There are 2 available Gazebo environment, one with humans walking around and one without. To launch the first environment, use the following command in the newly launched terminal: 

    roslaunch office indoor_office_actors.launch
 If there is an error, navigate to *~/nus-arc-gazebo-env/office/launch* and do a roslaunch from the folder itself. The other file in the same folder has no dynamic models in it and it can be launched using the same method stated above. 

## 3. Gazebo Robot
Upon launching the environment, the following section will cover spawning husky into the gazebo, launching it in Rviz and controlling it with Teleop commands. 

**Spawn Husky into Gazebo**
To spawn husky, ensure that you have sourced the src file to devel/setup. Then, simply use the following command:

    roslaunch robot_gazebo spawn_husky.launch

**Launching in Rviz**
Once husky is launched inside Gazebo, you can launch another terminal and proceed to visualize it in Rviz using this command:

    roslaunch robot_rviz view_robot.launch
The Rviz is able to visualize husky robot, view the map that it has scanned through Gmapping and the camera view that is mounted on it. Use pointcloud 2 for VLP-16, depth cloud for the depth cams and camera for tracking cam

**Control Husky with Teleop**
Finally, to control it's movement inside Gazebo, launch another terminal to control it using the following command:

    rosrun random_husky_driver random_driver
An alternative to this would be 

    rosrun teleop_twist_keyboard teleop_twist_keyboard.py
And if you launch using the first method, you could control the husky intuitively using WASD keys, or alternatively, the instruction to control husky is printed in the terminal if you use the second method.

## 4. Initiating SLAM 
Lastly, to initiate SLAM in husky, we have to first convert the 3D pointcloud data collected from the Velodyne-16 into a 2D laserscan data. To do that, we could using the following command: 

    roslaunch pointcloud_to_laserscan sample_node.launch
 
Next, open up a new terminal, launch your algorithm for testing. By default, let's use Gmapping. It is located in the *robot_navigation* folder, and we can initiate it using this command: 

    roslaunch robot_navigation gmapping_demo.launch
We now have a fully working robot, that is able to control through your teleop terminal and view its mapping through Rviz. The next section will cover some tips for map viewing and troubleshooting. 

## 5. Tips and Troubleshooting
*Updating in progress*
To have a better view of the map, you could control the following parameters in Rviz, 
odometry -> position -> alpha -> 0
odometry -> cohesion -> alpha -> 0 

> Husky not appearing in Rviz, after i launched it 

Ensure you have spawned the husky in Gazebo before visualizing it in Rviz 

> No data coming in from Gmapping after i launched it 

Check whether you have launched a terminal for *pointcloud_to_laserscan* in order for gmapping to receive 2D data. 

<!--stackedit_data:
eyJoaXN0b3J5IjpbLTMwMDE4MjQ4NCwzNTM3MTAyMTksMTE1OT
M0MTQ3MSwtMTc3OTM1MDgzMiwtOTI1ODY3NjM2LDE4NjI1MDk3
MDVdfQ==
-->