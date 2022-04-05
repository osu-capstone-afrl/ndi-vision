# Adnan Reddy 2021-11-18
# Comments are my current understanding of processes

import pyrealsense2 as rs
import numpy as np
import matplotlib.pyplot as plt

colorizer = rs.colorizer()
pipeline = rs.pipeline()

# Make matplotlib able to update
plt.ion()

# Start receiving data from camera
pipeline.start()

try:
    while True:

        frames = pipeline.wait_for_frames() # Collect frames (?) from camera
        if not frames: continue # Skip remaining if no frames

        depth_frame = frames.get_depth_frame()
        depth_colormap = np.asanyarray(colorizer.colorize(depth_frame).get_data()) # Map colors to depths

        plt.clf()  # Clear the plot
        plt.imshow(depth_colormap)
        plt.draw() # Display the image
        plt.pause(0.1)

finally:
    pipeline.stop()
