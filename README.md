
# Non-Destructive Inspection - Vision Project
Package intended to retrieve and reconstitute multiple point clouds from the RealSense Depth Camera D435i using ROS, C++, and Python. This work completed for the Air Force Research Lab through the Multidisciplinary Capstone within The Ohio State University.

_Note: This repository was designed for ROS Melodic. It has not been tested on other distributions._

## Tools Contained
  - **.catkin_tools:** Contains Catkin-created build (compilation) of code.
  - **launch:** Contains ROS-specific launch files which setup for and call scripts.
  - **scripts_capture:** Contains scripts to capture single shots and streams of point clouds from the Realsense camera.
  - **scripts_combine:** Contains scripts to eventually combine the point clouds.
  - **scripts_process:** Contains scripts to process and filter single point clouds.
  - **src:** Contains test and troubleshooting code.
  - **CMakeLists.txt:** Contains instructions for CMake compiler regarding included libraries and installation location.
  - **package.xml:** Contains package information and describes dependencies.

## Installation
The following section explains how to setup the package.

### Prerequisites
  - **ROS Melodic:** For obstaining and cofiguring ROS follw the instructions for [full-desktop Melodic installation](https://wiki.ros.org/melodic/Installation/Ubuntu).

### Required Repositories
  - **LibRealSense:** 

### Dependencies
