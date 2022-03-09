cmake_minimum_required(VERSION 3.0.2)
project(ndi_vision)

find_package(catkin REQUIRED
  COMPONENTS
    roscpp
    rospy
#     std_msgs
#     genmsg
)

include_directories(${catkin_INCLUDE_DIRS})

catkin_package()

add_executable(sub_pcl src/sub_pcl.cpp)
target_link_libraries(sub ${catkin_LIBRARIES})
# add_dependencies(sub)
# add_executable(talker src/talker.cpp)
# target_link_libraries(talker ${catkin_LIBRARIES})
# add_dependencies(talker beginner_tutorials_generate_messages_cpp)
# add_executable(listener src/listener.cpp)
# target_link_libraries(listener ${catkin_LIBRARIES})
# add_dependencies(listener beginner_tutorials_generate_messages_cpp)

install(
    DIRECTORY scripts_process scripts_combine launch
    DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)
