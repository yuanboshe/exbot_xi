cmake_minimum_required(VERSION 2.8.3)
project(exbotxi_example)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  rospy
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES exbotxi_example
  CATKIN_DEPENDS geometry_msgs roscpp rospy
#  DEPENDS system_lib
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(move nodes/move.cpp)
target_link_libraries(move ${catkin_LIBRARIES})