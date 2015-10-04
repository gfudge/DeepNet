#pragma once
#include "Deepnet.h"
#include <vector>
#include <exception>
#include <memory>

class Test : public DeepNet::Network<float>
{
public:
	Test(const float targetError, const unsigned int maximumEpochs, const unsigned int epochsBetweenReports);
	virtual ~Test();

private:
	float targetError = (const float)0.001;
	unsigned int maximumEpochs = 500000;
	unsigned int epochsBetweenReports = 1000;
	std::vector<size_t> hiddenLayers[5];
	std::unique_ptr<DeepNet::Network<float>> network{ new DeepNet::Network<float>(nullptr) };
};

