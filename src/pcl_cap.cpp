
// pcl_cap.cpp

#include <ros/ros.h>
#include <ros/console.h>
#include <sensor_msgs/PointCloud2.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

using namespace std;

/*Script description

This script is intended for use on ROS Melodic and with the Intel Realsense D435
Depth Camera. When set up using t1_init_main.launch, the camera streams
pointclouds in ROS messages on the topic /camera/depth/color/points. This script
subscribes to that topic and captures a frame of this stream which is then
published to the topic myPCL_node.

Author: Nicholas Pater.8

PSEUDO CODE
	declare publisher
	code goes to main()
		flag main
		initialize ROS
		initialize node handle
		create subscriber
		flag subscription
		advertise creation of publisher
		create publisher
	code goes to cb
		flag cb
		publish data which was subscribed to
*/

// Declare publisher
ros::Publisher pub_;

void cb (const sensor_msgs::PointCloud2ConstPtr& input)
{

	// Publish data
	pub_.publish(input);

	// If desired, could call another script from this callback to automate process
}

int main(int argc, char** argv)
{
  	// Initialize ROS
	ros::init (argc, argv, "pcl_cap");
	ros::NodeHandle nh_;
	ROS_INFO_STREAM("pcl_cap successfully initialized");

	// Create a ROS subscriber for the input pcl
	ros::Subscriber sub_ = nh_.subscribe ("camera/depth/color/points", 25, cb);
	ROS_INFO_STREAM("Succesfully subscribed to camera/depth/color/points");

	// Create a ROS publisher for the output pcl
	pub_ = nh_.advertise<sensor_msgs::PointCloud2> ("myPCL_captured", 1);
	ROS_INFO_STREAM("ROS message from camera/depth/color/points successfully sent to myPCL_captured");

	// Spin once
	ros::spinOnce();

	ROS_INFO_STREAM("Run pcl_cap again after rearranging camera for another snapshot");
	ROS_INFO_STREAM("Consider running pcl_statfilter.cpp in another terminal tab to statistically filter the point clouds from myPCL_captured");

	return 0;
}