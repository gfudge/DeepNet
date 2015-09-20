#include "SingleLayerPerceptron.h"



SingleLayerPerceptron::SingleLayerPerceptron(size_t inputLayerSize, size_t outputLayerSize, size_t hiddenLayerSize, fann_activationfunc_enum activation)
{
	this->inputLayerSize = inputLayerSize;
	this->outputLayerSize = outputLayerSize;
	this->hiddenLayerSize = hiddenLayerSize;
	this->activation = activation;
}

SingleLayerPerceptron::~SingleLayerPerceptron()
{
	fann_destroy(this->ann);
}

void SingleLayerPerceptron::ConstructLayers()
{
	if (1 > this->layers.size()) {
		// Create the layers vector
		this->layers = {this->inputLayerSize, this->hiddenLayerSize, this->outputLayerSize};
		// Check the layers vector is a reasonable size
		if (3 != this->layers.size())
		{
			throw std::runtime_error("Constructed layer of incorrect depth");
		}
	}
	else {
		throw std::runtime_error("Cannot construct layer: Layer already exists");
	}
}

void SingleLayerPerceptron::CreateLayer()
{
	// Check there are some layers
	if (1 > this->layers.size()) {
		// Create copy of layer vector as array
		const size_t* fann_layers = &this->layers[0];
		// Grab the size of layers
		const size_t n_layers = this->layers.size();
		this->ann = fann_create_standard_array(n_layers, fann_layers);
	}
	else {
		throw std::runtime_error("Incorrect number of layers for creation");
	}
}

void SingleLayerPerceptron::SetActivation()
{
	if (this->ann != nullptr) {
		fann_set_activation_function_hidden(this->ann, this->activation);
		fann_set_activation_function_output(this->ann, this->activation);
	}
	else {
		throw std::runtime_error("Cannot set activation functions: network uninitialised");
	}
}
