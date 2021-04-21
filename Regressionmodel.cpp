#include "Regressionmodel.h"
#include"Linklist.h"
#include<stdio.h>
#include<iostream>
using namespace std;

Regressionmodel::Regressionmodel(char* fileaddress)
{
	FILE* learnfile;
	float x=0,y=0;
	
	learnfile = fopen(fileaddress, "r");
	fscanf(learnfile, "%f	%f\n", &x, &y);
	Pair learnpair(x,y);
	learndata.sethead(learnpair);
	while (!feof(learnfile))
	{
		fscanf(learnfile, "%f	%f\n", &x, &y);
		Pair learnpair(x, y);
		learndata.addnode(learnpair);
	}
	b1 = learndata.getb1();
	b0 = (learndata.average().gety())-(b1*learndata.average().getx());
	
}


Regressionmodel::~Regressionmodel()
{
}
float Regressionmodel::predict(float _x) const
{
	float y;
	y = b0 + b1*_x;


	return y;
}
void Regressionmodel::info() const
{
	cout << "count of learning Node: " << learndata.getnodecounter() << endl;
	cout << "Line equation of model:" << "y="<<b0<<"+"<<b1<<"x"<<endl;
	cout << "Model error: " << learndata.geterror(b0,b1)<<endl;
}