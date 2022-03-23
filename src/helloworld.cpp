#include <ros/ros.h>
#include <ros/console.h>

int main (int argc, char** argv)
{
  ros::init (argc, argv, "helloworld");
  ros::start();
  ROS_INFO_STREAM("Hello World");
  ros::spin();
  ros::shutdown();
  return 0;
}