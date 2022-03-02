cmake_minimum_required(VERSION 3.0.2)
project(ndi_vision)

find_package(catkin REQUIRED
  COMPONENTS
    roscpp
    rospy
)

catkin_package()

install(
    DIRECTORY scripts_process scripts_combine
    DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)

install(
    DIRECTORY launch
    DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)
