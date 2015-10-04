#pragma once
#include <vector>
#include <exception>
#include <memory>
#include "Slice.h"

namespace DeepNet
{

	// Empty container class for interfacing layers
	// Inherit, overload and fill the gaps
	template<typename T>
	class Layer
	{
	public:
		Layer(size_t inputLayerSizeX, size_t inputLayerSizeY, size_t outputLayerSizeX, size_t outputLayerSizeY);
		virtual ~Layer();
		size_t inputLayerSizeX;
		size_t inputLayerSizeY;
		size_t outputLayerSizeX;
		size_t outputLayerSizeY;
		std::unique_ptr<Slice<T>> inputLayer;
		std::unique_ptr<Slice<T>> outputLayer;
	};

}
