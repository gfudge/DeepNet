#pragma once
#include "Layer.h"
#include "fann.h"

class SingleLayerPerceptron :
	public Layer
{
public:
	SingleLayerPerceptron(size_t inputLayerSize, size_t outputLayerSize, size_t hiddenLayerSize, fann_activationfunc_enum activation = FANN_SIGMOID_SYMMETRIC);
	virtual ~SingleLayerPerceptron();
	void ConstructLayers();
	void CreateLayer();
	void SetActivation();
private:
	size_t hiddenLayerSize;
	size_t numberOfLayers = 3;
	std::vector<size_t> layers;
	struct fann *ann;
	fann_activationfunc_enum activation;
};

