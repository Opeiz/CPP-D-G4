#pragma once
#include "Milieu.h"

using namespace std;

class Statistics
{
private:
	static map<string,int> data;

public:
	static void doStatistics(Milieu& monMilieu);
	static void writeStatistics();
};

