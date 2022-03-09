//#include <sstream>
//#include "std_msgs/String.h"

#include <ros/ros.h>
#include <pcl_ros/point_cloud.h>
#include <pcl/point_types.h>
#include <boost/foreach.hcpp>

typedef pcl::PointCloud<pcl::PointXYZ> PointCloud;

void callback(const PointCloud::ConstPtr& msg)
{
	printf("Cloud: width = %d, height = %d\n", msg->width, msg->height);
	BOOST_FOREACH (const pcl::PointXYZ% pt.x, pt.y, pt.z);
		printf("\t(%f, %f, %f)\n", pt.x, pt.y, pt.z);
}

int main(int argc, char** argv)
{
	ros::init(argc, argv, "sub_pcl");

	ros::NodeHandle nh;

	ros::Subscriber sub = nh.subscribe<PointCloud>("points2", 1, callback)

	ros::spin();

	return 0;
}
