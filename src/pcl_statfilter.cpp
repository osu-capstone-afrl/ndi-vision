
// pcl_statfilter.cpp

#include <ros/ros.h>
#include <ros/console.h>
#include <sensor_msgs/PointCloud2.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/PCLPointCloud2.h>
#include <pcl_ros/transforms.h>
#include <pcl/filters/statistical_outlier_removal.h>

using namespace std;

/*Script description

need to convert from sensor_msgs::PointCoud2 to pcl::PointCloud2 class somehow!

Author: Nicholas Pater.8

PSEUDO CODE
	ddd
*/

// Declare publisher
ros::Publisher pub_;

// void cb (const sensor_msgs::PointCloud2ConstPtr& input)
void cb (const boost::shared_ptr<const sensor_msgs::PointCloud2>& input)
{
	// // Convert input from sensor_msgs::PointCloud2 to pcl::PCLPointCloud2
	// pcl::PCLPointCloud2 input_pcl;
	// pcl_conversions::toPCL(*input, input_pcl);
	// // pcl::PCLPointCloud2<pcl::PointCloud2>::Ptr temp_cloud(new pcl::PCLPointCloud2<pcl::PointCloud2>);
	// pcl::PointCloud<pcl::PointXYZ>::Ptr temp_cloud(new pcl::PointCloud<pcl::PointXYZ>);
	// pcl::fromPCLPointCloud2(input_pcl, *temp_cloud);

	// // Create a sorting container for the data
	// sensor_msgs::PointCloud2 sort_obj;
	// const sensor_msgs::PointCloud2ConstPtr& sort_obj_ptr = boost::make_shared<sensor_msgs::PointCloud2>(sort_obj_ptr);

	// // Create output container for the data
	// sensor_msgs::PointCloud2 output;
	// const sensor_msgs::PointCloud2ConstPtr& output_ptr = boost::make_shared<sensor_msgs::PointCloud2>(output_ptr);

	// // Filter data
	// sort_obj.setInputCloud(input);
	// sort_obj.setMeanK(50);					// Guess for now
	// sort_obj.setStddevMulThresh(1.0);		// Guess for now
	// sort_obj.filter(*output);

	// // Convert output from pcl::PointCloud2 to sensor_msgs::PointCloud2
	// // do me i think

	// // Publish the data

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Convert input from sensor_msgs::PointCloud2 to pcl::PointCloud
	

	// Create a sorting container for the data
	

	// Create output container for the data


	// Filter data
	

	// Convert output from pcl::PointCloud2 to sensor_msgs::PointCloud2
	// do me i think

	// Publish the data
	pub_.publish(output);
}

int main(int argc, char** argv)
{
  	// Initialize ROS
	ros::init (argc, argv, "pcl_statfilter");
	ros::NodeHandle nh_;
	ROS_INFO_STREAM("pcl_statfilter successfully initialized");

	// Create a ROS subscriber for the input pcl
	ros::Subscriber sub_ = nh_.subscribe ("myPCL_captured", 25, cb);
	ROS_INFO_STREAM("Successfully subscribed to myPCL_captured");

	// Create a ROS publisher for the output pcl
	pub_ = nh_.advertise<sensor_msgs::PointCloud2> ("myPCL_statfiltered", 1);
	ROS_INFO_STREAM("ROS message successfully sent to myPCL_statfiltered");

	// Spin
	ros::spin();

	return 0;
}