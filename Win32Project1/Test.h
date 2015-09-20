#pragma once
#include "floatfann.h"

class Test
{
public:
	Test(const float targetError, const unsigned int maximumEpochs, const unsigned int epochsBetweenReports);
	virtual ~Test();

private:
	float targetError = (const float)0.001;
	unsigned int maximumEpochs = 500000;
	unsigned int epochsBetweenReports = 1000;
	Network network;
};

