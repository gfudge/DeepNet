#pragma once
#include "Layer.h"
#include <exception>
#include <memory>
template<typename T>
class MaxPoolingLayer :
	public Layer<T>
{
public:
	MaxPoolingLayer(Slice<T> inputLayer, Slice<T> outputLayer, size_t poolSizeX, size_t poolSizeY);
	virtual ~MaxPoolingLayer();
	std::shared_ptr<Slice<T>> calcuateOutputLayer();

private:
	size_t poolSizeX;
	size_t poolSizeY;
	Slice<T> inputLayer;
	Slice<T> outputLayer;
	T maxPool(size_t x, size_t y, size_t poolWidth, size_t poolHeight);
};

