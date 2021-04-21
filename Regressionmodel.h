#pragma once
#include"Linklist.h"
class Regressionmodel
{
public:
	Regressionmodel(char* fileaddress);
	~Regressionmodel();
	float predict(float _x) const;
	void info() const;
private:
	Linklist learndata;
	float b0;
	float b1;
};

