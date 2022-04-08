cmake_minimum_required(VERSION 3.0.2)
project(ndi_vision)

find_package(catkin REQUIRED
  COMPONENTS
    roscpp
    pcl_conversions
    pcl_ros
)
find_package(PCL 1.2 REQUIRED)

catkin_package(
  LIBRARIES initsub.cpp helloworld.cpp pcl_cap.cpp
  CATKIN_DEPENDS pcl_conversions pcl_ros roscpp
)

include_directories(${catkin_INCLUDE_DIRS})
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

install(
    DIRECTORY scripts_process scripts_combine launch src
    DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)

add_executable(helloworld src/helloworld.cpp)
target_link_libraries(helloworld ${catkin_LIBRARIES})

add_executable(initsub src/initsub.cpp)
target_link_libraries(initsub ${catkin_LIBRARIES})
target_link_libraries(initsub ${PCL_LIBRARIES})

add_executable(pcl_cap src/pcl_cap.cpp)
target_link_libraries(pcl_cap ${catkin_LIBRARIES})
target_link_libraries(pcl_cap ${PCL_LIBRARIES})

# add_executable(pointcloud_to_pcd src/pointcloud_to_pcd.cpp)
# target_link_libraries(pointcloud_to_pcd ${catkin_LIBRARIES})
# target_link_libraries(pointcloud_to_pcd ${PCL_LIBRARIES})