cmake_minimum_required(VERSION 3.0.2)
project(ndi_vision)

find_package(catkin REQUIRED
  COMPONENTS
    roscpp
    rospy
)
find_package(PCL 1.2 REQUIRED)

include_directories(${catkin_INCLUDE_DIRS})
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

catkin_package()

# add_executable(subpcl src/subpcl.cpp)
# target_link_libraries(subpcl ${catkin_LIBRARIES})
add_executable(initsub src/initsub.cpp)
target_link_libraries(initsub ${catkin_LIBRARIES})
target_link_libraries(initsub ${PCL_LIBRARIES})

install(
    DIRECTORY scripts_process scripts_combine launch
    DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)
