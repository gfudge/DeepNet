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
std::shared_ptr<Slice<T>> MaxPoolingLayer<T>::calcuateOutputLayer()
{
	// Init output slice
	std::shared_ptr<Slice<T>> maxPools = std::make_shared<Slice<T>>(this->poolSizeX, this->poolSizeY);
	
	return (std::shared_ptr<Slice<T>>)maxPools;
}

template<typename T>
T MaxPoolingLayer<T>::maxPool(size_t x, size_t y, size_t poolWidth, size_t poolHeight)
{
	T poolMax = 0;
	for (int i = y; i < (y + poolWidth); i++) {
		for (int j = x; j < (x + poolWidth); j++) {
			if (this->inputLayer.getElement(i, j) > poolMax) {
				poolMax = this->inputLayer.getElement(i, j);
			}
		}
	}/*
	for (&auto row : this->inputLayer.row()) {
		for (&auto column : this->inputLayer.column()) {

		}
	}*/
	return T();
}


