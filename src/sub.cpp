#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

int main() {
	
	std_msgs::String msg;
	std::stringstream ss;
	ss << "It's alive" << count;
	msg.data = ss.str();

	Return 0;
}
