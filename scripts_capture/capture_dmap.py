#!/usr/bin/env python

import rospy
import numpy as np
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2

    
def frameGrabber():

    # Grab single message from ROS
    newMsg_dmap = rospy.wait_for_message("/camera/aligned_depth_to_color/image_raw", Image, timeout=10)
    newMsg_colr = rospy.wait_for_message("/camera/color/image_raw", Image, timeout=10)

    rospy.loginfo(rospy.get_caller_id() + " Recieved and Saved Realsense Camera Messages")

    # Initialize OpenCV
    bridge = CvBridge()

    # Extract Depth Map from ROS Image message format
    dmap = bridge.imgmsg_to_cv2(newMsg_dmap, desired_encoding='passthrough')
    cimg_bgr = bridge.imgmsg_to_cv2(newMsg_colr, desired_encoding='passthrough') #will be BGR format

    # Export Parameters
    filename = 'set_1' # + str(rospy.get_time())

    # Save Color
    cimg = cv2.cvtColor(cimg_bgr, cv2.COLOR_BGR2RGB)
    cv2.imwrite(filename+'_color.tiff', cimg)

    # Save dmap
    np.save(filename, dmap, allow_pickle=True, fix_imports=True)
    cv2.imwrite(filename + '_dmap.tiff', dmap)


if __name__ == '__main__':
    rospy.init_node('frameGrabber', anonymous=True)
    frameGrabber()