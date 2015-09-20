#include "Network.h"



Network::Network(unsigned int inputLayerSize, unsigned int outputLayerSize, unsigned int numberOfLayers, std::vector<unsigned int> hiddenLayers)
{
	this->inputLayerSize = (unsigned int)inputLayerSize;
	this->outputLayerSize = (unsigned int)outputLayerSize;
	this->numberOfLayers = (unsigned int)numberOfLayers;
	this->hiddenLayers = hiddenLayers;

}


Network::~Network()
{
	fann_destroy(this->ann);
}

void Network::ConstructLayers() {
	// Check there are no layers yet
	if (1 > this->layers.size()){
		this->layers.push_back(this->inputLayerSize);
		// For each hidden layer, push it onto layers vector
		for (auto &layer : this->hiddenLayers) {
			this->layers.push_back(layer);
		}
		this->layers.push_back(this->outputLayerSize);
		// Store expected network layer depth
		size_t network_depth = (size_t)this->hiddenLayers.size() + 2;
		if (this->layers.size() != network_depth) {
			throw std::runtime_error("Layer construction failed; network depth mismatch");
		}
	}
	else {
		throw std::runtime_error("Layers already exist");
	}
}

void Network::CreateNetworkFromLayers() {
	// Make sure there are some layers
	if (1 > this->layers.size()) {
		// Copy layers vector into array
		const unsigned int* fann_layers = &this->layers[0];
		size_t n_layers = this->layers.size();
		this->ann = fann_create_standard_array(n_layers, fann_layers);
	}
	else {
		throw std::runtime_error("Insufficient layers for network creation");
	}
}