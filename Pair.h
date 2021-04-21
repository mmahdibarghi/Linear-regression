#pragma once
class Pair
{
public:
	Pair(float _x,float _y);
	Pair(float _x, float _y,int _dontcount);
	Pair();
	~Pair();
	Pair(const Pair &p);
	static int getcounter();
	float getx()const;
	float gety() const;
	
	
private:

	float x;
	float y;
	static int counter;
};

