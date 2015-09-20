#include "Test.h"
#include "Network.h"


Test::Test(const float targetError, const unsigned int maximumEpochs, const unsigned int epochsBetweenReports)
{
	this->targetError = targetError;
	this->maximumEpochs = maximumEpochs;
	this->epochsBetweenReports = epochsBetweenReports;
	//this->network = Network();
}


Test::~Test()
{
}
