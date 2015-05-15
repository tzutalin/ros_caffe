#include "ros/ros.h"
#include <iostream>
#include <caffe/caffe.hpp>
#include <vector>
#include <sstream>
using std::string;
using caffe::Blob;
using caffe::Caffe;
using caffe::Datum;
using caffe::Net;
using caffe::shared_ptr;
using caffe::vector;
using caffe::MemoryDataLayer;

void Log(std::string msg) {
	std::cout << msg << std::endl;
}

int main(int argc, char **argv) {
#ifdef CPU_ONLY:
	std::cout<<"CPU_ONLY" << std::endl;
    Caffe::set_mode(Caffe::CPU);
#endif
	ros::init(argc, argv, "ros_caffe_main");

	std::string model_path = "/home/darrenl/workspace/eclipse_clusplus_workspace/TestCaffe/bvlc_reference_deploy_memorylayer.prototxt";
	std::string weights_path = "/home/darrenl/workspace/eclipse_clusplus_workspace/TestCaffe/bvlc_reference_caffenet.caffemodel";
	std::string image_path = "/home/darrenl/cat.jpg";
	// Use CPU only.
	// Initial
	Net<float> *caffe_net;
	caffe_net = new Net<float>(model_path, caffe::TEST);
	caffe_net->CopyTrainedLayersFrom(weights_path);
	// Assign datum
	Datum datum;
	if (!ReadImageToDatum(image_path, 1, 227, 227, &datum)) {
		Log("Read Image fail");
		return -1;
	}
	// Use MemoryDataLayer
	const boost::shared_ptr<MemoryDataLayer<float> > memory_data_layer =
			boost::static_pointer_cast<MemoryDataLayer<float> >(
					caffe_net->layer_by_name("data"));
	std::vector<Datum> datum_vector;
	datum_vector.push_back(datum);
	memory_data_layer->AddDatumVector(datum_vector);
	std::vector<Blob<float>*> dummy_bottom_vec;
	float loss;
	const std::vector<Blob<float>*>& result = caffe_net->Forward(
			dummy_bottom_vec, &loss);
	const std::vector<float> probs = std::vector<float>(result[1]->cpu_data(),
			result[1]->cpu_data() + result[1]->count());
	// Find the index with max prob
	int max_index = -1;
	float max_value;
	for (int index = 0; index != probs.size(); index++) {
		if (index == 0) {
			max_index = 0;
			max_value = probs[max_index];
			continue;
		}
		// Compare
		if (max_value < probs[index]) {
			max_value = probs[index];
			max_index = index;
		}
	}
	/**
	 * Result : Toilet is 861 Cat is 281, etc..
	 **/
	std::stringstream ss;
	ss << "max index: " << max_index;
	Log(ss.str());
	return 0;
}
