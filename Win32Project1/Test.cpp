#include "Test.h"



Test::Test(const float targetError, const unsigned int maximumEpochs, const unsigned int epochsBetweenReports)
{
	this->targetError = targetError;
	this->maximumEpochs = maximumEpochs;
	this->epochsBetweenReports = epochsBetweenReports;
	const size_t totalLayers = (size_t) this->hiddenLayers.length();
	this->network = DeepNet::Network<float>(5, 2, totalLayers, this->hiddenLayers);
}

Test::~Test()
{
}
