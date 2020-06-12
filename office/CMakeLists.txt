cmake_minimum_required(VERSION 2.8.3)
project(office)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  message_generation
  roscpp
  std_msgs
)

# Gazebo
find_package(gazebo 8 QUIET)
if(NOT gazebo_FOUND)
  find_package(gazebo 9 REQUIRED)
endif()


set(trajectory_actor_plugin_name TrajectoryActorPlugin)
catkin_package(
  CATKIN_DEPENDS
    geometry_msgs
    message_runtime
    roscpp
    std_msgs
  LIBRARIES ${trajectory_actor_plugin_name}
)

###########
## Build ##
###########

include_directories(
  include
  ${GAZEBO_INCLUDE_DIRS}
  ${catkin_INCLUDE_DIRS}
)

link_directories(
  ${GAZEBO_LIBRARY_DIRS}
  ${catkin_LIBRARY_DIRS}
)

#############################
## Trajectory Actor plugin ##
#############################

# Create the libTrajectoryActorPlugin.so library.
add_library(${trajectory_actor_plugin_name} SHARED
  src/TrajectoryActorPlugin.cc
)
target_link_libraries(${trajectory_actor_plugin_name}
  ${GAZEBO_LIBRARIES}
  ${catkin_LIBRARIES}
)
install(TARGETS ${trajectory_actor_plugin_name}
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_GLOBAL_BIN_DESTINATION}
)


#############
## Install ##
#############

install(
  DIRECTORY
    launch
    map
    media
    models
    worlds
  DESTINATION
    ${CATKIN_PACKAGE_SHARE_DESTINATION}/
)
