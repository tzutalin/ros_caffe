# ros_caffe
================
## Purpose
Integrate Caffe model into ROS

## Requirements
* Ubuntu 

* [Install ROS](http://wiki.ros.org/ROS/Installation) with [catkin build](http://wiki.ros.org/ROS/Tutorials/InstallingandConfiguringROSEnvironment). Create a catkin workspace.

## Grab the source
`$ cd $CATKIN_WS/src`

`$ git clone --recursive https://github.com/tzutalin/ros_caffe.git`

`$ cd $CATKIN_WS/src/ros_caffe`

`$ ./get_model.py`

## Build & Run
* Build Caffe

`cd $CATKIN_WS/src/ros_caffe/caffe`

`cp Makefile.config.example Makefile.config`

`$ vi Makefile.config`

For CPU-only Caffe, uncomment CPU_ONLY := 1 in Makefile.config.

`$ make all ; make distribute`

* Build ros package

`$ cd $CATKIN_WS`

`$ catkin_make`

Open a terminal, execute

`$ roscore`

Open another terminal, execute

`$ rosrun ros_caffe ros_caffe_test`

Output:

	Test default image under /data/cat.jpg
	0.1384 - "n02123159 tiger cat"
	0.1302 - "n02123045 tabby, tabby cat"
	0.1138 - "n02085620 Chihuahua"
	0.1076 - "n02094433 Yorkshire terrier"
	0.0914 - "n02123394 Persian cat"


You can echo a topic to receive the string message.

`$ rostopic echo /caffe_ret`

	data: [0.138446 - n02123159 tiger cat]
	[0.130182 - n02123045 tabby, tabby cat]
	[0.113755 - n02085620 Chihuahua]
	[0.107584 - n02094433 Yorkshire terrier]
	[0.0913549 - n02123394 Persian cat]

## Note

* Optional: Download the model and install Caffe by following the [Blog](http://tzutalin.blogspot.tw/2015/06/setup-caffe.html) or [Caffe offical site](http://caffe.berkeleyvision.org/installation.html)

You can change your Caffe's include and lib path in CMakeLists.txt. 

	`set(CAFFE_INCLUDEDIR caffe/include caffe/distribute/include)`
	
	`set(CAFFE_LINK_LIBRARAY caffe/lib)`
# ros_caffe
================
## Purpose
Integrate Caffe model into ROS

## Requirements
* Ubuntu 

* [Install ROS](http://wiki.ros.org/ROS/Installation) with [catkin build](http://wiki.ros.org/ROS/Tutorials/InstallingandConfiguringROSEnvironment). Create a catkin workspace.

## Grab the source
`$ cd $CATKIN_WS/src`

`$ git clone --recursive https://github.com/tzutalin/ros_caffe.git`

`$ cd $CATKIN_WS/src/ros_caffe`

`$ ./get_model.py`

## Build & Run
* Build Caffe

`cd $CATKIN_WS/src/ros_caffe/caffe`

`cp Makefile.config.example Makefile.config`

`$ vi Makefile.config`

For CPU-only Caffe, uncomment CPU_ONLY := 1 in Makefile.config.

`$ make all ; make distribute`

* Build ros package

`$ cd $CATKIN_WS`

`$ catkin_make`

Open a terminal, execute

`$ roscore`

Open another terminal, execute

`$ rosrun ros_caffe ros_caffe_test`

## Note

* Optional: Download the model and install Caffe by following the [Blog](http://tzutalin.blogspot.tw/2015/06/setup-caffe.html) or [Caffe offical site](http://caffe.berkeleyvision.org/installation.html)

You can change your Caffe's include and lib path in CMakeLists.txt. 

	`set(CAFFE_INCLUDEDIR caffe/include caffe/distribute/include)`
	
	`set(CAFFE_LINK_LIBRARAY caffe/lib)`
