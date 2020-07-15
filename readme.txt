Steps for proper installation
1) Insert the files into a workspace folder and use "catkin build"

2)roslaunch robot_gazebo robot_empty_world.launch 

3)roslaunch robot_rviz view_robot.launch (Use pointcloud 2 for VLP-16, depth cloud for the depth cams and camera for tracking cam)

4)rosrun teleop_twist_keyboard teleop_twist_keyboard.py (keyboard control: Might need to install it first using "sudo apt-get install ros-melodic-teleop-twist-keyboard")
