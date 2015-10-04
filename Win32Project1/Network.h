#pragma once
#include "floatfann.h"
#include <vector>
#include <exception>

namespace DeepNet 
{
	template <typename T>
	class Network
	{
	public:
		Network(size_t inputLayerSize, size_t outputLayerSize, size_t numberOfLayers, std::vector<size_t> hiddenLayers);
		virtual ~Network();
		void ConstructLayers();
		void CreateNetworkFromLayers();
	private:
		size_t inputLayerSize;
		size_t outputLayerSize;
		size_t numberOfLayers;
		std::vector<unsigned int> hiddenLayers;
		std::vector<unsigned int> layers;
		struct fann *ann;

	};

}
