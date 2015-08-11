# ros_caffe
================
### Purpose
Integrate Caffe model into ROS

### Requirements
* Ubuntu and ROS with catkin Build

* Download the model and install Caffe by following the [Blog](http://tzutalin.blogspot.tw/2015/06/setup-caffe.html) or [Caffe offical site](http://caffe.berkeleyvision.org/installation.html)

### Grab the source
	$ cd $CATKIN_WS/src
	$ git clone https://github.com/tzutalin/ros_caffe.git
	
## Build
	$ cd  $CATKIN_WS
	$ catkin_make

You can change your Caffe's include and lib path in CMakeLists.txt(Optional)

	set(CAFFE_INCLUDEDIR caffe/include caffe/distribute/include)
	set(CAFFE_LINK_LIBRARAY caffe/lib)

## Run
`$ rosrun ros_caffe ros_caffe_test`
