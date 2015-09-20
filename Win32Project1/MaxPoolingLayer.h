#pragma once
#include "Layer.h"
template<typename T>
class MaxPoolingLayer :
	public Layer<T>
{
public:
	MaxPoolingLayer(Slice<T> inputLayer, Slice<T> outputLayer, size_t poolSizeX, size_t poolSizeY);
	virtual ~MaxPoolingLayer();
	std::vector<T> calcuateOutputLayer();

private:
	size_t poolSizeX;
	size_t poolSizeY;
	std::vector<T> inputLayer;
};

