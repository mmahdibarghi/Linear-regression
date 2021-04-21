#include "Pair.h"
#include<stdio.h>
#include<iostream>


Pair::Pair(float _x=0,float _y=0)
{
	x = _x;
	y = _y;
	
	counter++;

}
Pair::Pair(float _x, float _y, int _dontcount=1)
{
	x = _x;
	y = _y;
}
Pair::Pair()
{
	x = 0;
	y = 0;
	counter++;
}

Pair::~Pair()
{
	counter--;
}
int Pair::counter = 0;
Pair::Pair(const Pair &p)
{
	x = p.x;
	y = p.y;
	counter = p.counter;
	counter++;
}
float Pair::getx() const
{
	return x;

}
float Pair::gety() const
{
	return y;

}
int Pair::getcounter()
{
	return counter;
}