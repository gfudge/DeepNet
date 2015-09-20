#include "Layer.h"

template<typename T>
Layer<T>::Layer(size_t inputLayerSizeX, size_t inputLayerSizeY, size_t outputLayerSizeX, size_t outputLayerSizeY)
{
	this->inputLayerSizeX = inputLayerSizeX;
	this->inputLayerSizeY = inputLayerSizeY;
	this->outputLayerSizeX = outputLayerSizeX;
	this->outputLayerSizeY = outputLayerSizeY;
	// Init input & output slices
	this->inputLayer = std::unique_ptr<Slice<T>>(this->inputLayerSizeX, this->inputLayerSizeY);
	this->outputLayer = std::unique_ptr<Slice<T>>(this->outputLayerSizeX, this->outputLayerSizeY);
}

template<typename T>
Layer<T>::~Layer()
{
}
