#pragma once
#include "floatfann.h"
#include <vector>
#include <exception>

class Network
{
public:
	Network(unsigned int inputLayerSize, unsigned int outputLayerSize, unsigned int numberOfLayers, std::vector<unsigned int> hiddenLayers);
	virtual ~Network();
	void ConstructLayers();
	void CreateNetworkFromLayers();
private:
	unsigned int inputLayerSize;
	unsigned int outputLayerSize;
	unsigned int numberOfLayers;
	std::vector<unsigned int> hiddenLayers;
	std::vector<unsigned int> layers;
	struct fann *ann;

};

