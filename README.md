# ros_caffe
================
## Purpose
Integrate Caffe model into ROS

## Requirement
1 Enviornment: Ubuntu 14.04 and catkin Build

2 Download the model cafe by yourself

## Install
$ cd $CATKIN_WS/src

$ git clone https://github.com/tzutalin/ros_caffe.git

## Build
$ cd $CATKIN_WS

$ catkin_make

You can change your Caffe's include and lib path in CMakeLists.txt(Optional)

set(CAFFE_INCLUDEDIR caffe/include caffe/distribute/include)

set(CAFFE_LINK_LIBRARAY caffe/lib)

## Run
$ rosrun ros_caffe ros_caffe_test


