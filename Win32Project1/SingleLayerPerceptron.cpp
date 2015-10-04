#include "SingleLayerPerceptron.h"


template <typename T>
SingleLayerPerceptron<T>::SingleLayerPerceptron(size_t inputLayerSize, size_t outputLayerSize, size_t hiddenLayerSize, fann_activationfunc_enum activation)
{
	this->inputLayerSize = inputLayerSize;
	this->outputLayerSize = outputLayerSize;
	this->hiddenLayerSize = hiddenLayerSize;
	this->activation = activation;
}

template <typename T>
SingleLayerPerceptron<T>::~SingleLayerPerceptron()
{
	fann_destroy(this->ann);
}

template <typename T>
void SingleLayerPerceptron<T>::ConstructLayers()
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

template <typename T>
void SingleLayerPerceptron<T>::CreateLayer()
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

template <typename T>
void SingleLayerPerceptron<T>::SetActivation()
{
	if (this->ann != nullptr) {
		fann_set_activation_function_hidden(this->ann, this->activation);
		fann_set_activation_function_output(this->ann, this->activation);
	}
	else {
		throw std::runtime_error("Cannot set activation functions: network uninitialised");
	}
}
