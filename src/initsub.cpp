#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <ros/console.h>
#include <fstream>
using namespace std;

ros::Publisher pub;

void cloud_cb (const sensor_msgs::PointCloud2ConstPtr& input)
{
  // Create a container for the data.
  sensor_msgs::PointCloud2 output;

  ROS_INFO_STREAM("test52.pcd created");

  ofstream myfile;
  myfile.open("test52.pcd", ios::out | ios::binary);
  myfile << *input;
  myfile.close();

  // Do data processing here...
  //output = input;

  // Publish the data.
  //pub.publish (input);
}

int main (int argc, char** argv)
{
  // Initialize ROS
  ros::init (argc, argv, "initsub");
  ros::NodeHandle nh;

  // Create a ROS subscriber for the input point cloud
  ros::Subscriber sub = nh.subscribe ("camera/depth/color/points", 1, cloud_cb);

  // Create a ROS publisher for the output point cloud
  pub = nh.advertise<sensor_msgs::PointCloud2> ("output", 1);

  // Spin
  ros::spin ();

  return 0;
}