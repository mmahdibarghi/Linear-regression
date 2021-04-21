#pragma once
#include"Pair.h"
class Node
{
public:
	Node(Pair _data,Node* _next);
	Node();
	~Node();
	void setnext(Node* _next);
	void setdata(Pair _data);
	Node* getnext() const;
	Pair getdata() const;
private:
	Node* nextnode;
	Pair data;
};

