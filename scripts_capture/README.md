## Single-Frame Capture Scripts

Python scripts in this folder may be used to capture & post-process a single frame of RGB-D.

### HowTo Steps

1. **Launch Camera**
<br>This will find a USB-connected Intel Realsense Camera, open a pipeline, and publish the data streams on multiple topics in ROS. Specific settings are detailed in the launch file.

```bash
roslaunch ndi_vision t1_capture_dmap.launch
```

2. **Capture Single Frame**
<br>This python script will grab the most recent message from the color image and aligned_depth map ROS topics (ie. data streams) and save the data into the folder from which the script was started.
<br>Output includes three files. Depth map is in [mm] for both files.
* color image as .tiff
* depth map as .tiff
* depth map array as .npy

```bash
rosrun ndi_vision capture_dmap.py
```

3. **Post Processing**
<br>Post processing is possible via many different ways. 
<br>The provided python script `process_dmap.py` shows how to load the `.npy` file into a python script using Numpy.

#EOF
