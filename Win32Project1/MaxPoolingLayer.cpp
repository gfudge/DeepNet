#include "MaxPoolingLayer.h"


template<typename T>
MaxPoolingLayer<T>::MaxPoolingLayer(Slice<T> inputLayer, Slice<T> outputLayer, size_t poolSizeX, size_t poolSizeY)
{
	this->inputLayer = inputLayer;
	this->outputLayer = outputLayer;
	this->inputLayerSize = inputLayerSize;
	this->outputLayerSize = outputLayerSize;
	// Check pooling size is valid
	if (inputLayer.column % poolSizeX == 0) && (inputLayer.row % poolSizeY == 0) {
		if (outputLayer.column % poolSizeX == 0) && (inputLayer.row % poolSizeY == 0) {
			this->poolSizeX = poolSizeX;
			this->poolSizeY = poolSizeY;
		}
		else {
			throw std::runtime_error("Pooling size does not match output layer");
		}
	}
	else {
		throw std::runtime_error("Pooling size does not match input layer size");
	}
}

template<typename T>
MaxPoolingLayer<T>::~MaxPoolingLayer()
{
}

// Algorithm for calculating max pool
template<typename T>
std::vector<T> MaxPoolingLayer<T>::calcuateOutputLayer()
{
	// Check boundaries
	return std::vector<T>();
}
