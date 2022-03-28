#!/usr/bin/env python

import numpy as np
    
def main():

    # Load Numpy (.npy) file
    loadFileName = "ndi-vision/scripts_capture/set_1.npy"
    dmap = np.load(loadFileName, fix_imports=True)

    print("Loaded numpy array from " + str(loadFileName))

if __name__ == '__main__':
    main()
