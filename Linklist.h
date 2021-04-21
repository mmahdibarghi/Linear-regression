#pragma once
#include"Node.h"
class Linklist
{
public:
	
	Linklist(Pair _head);
	Linklist();
	~Linklist();
	Linklist(const Linklist &oldlinklist);
	void sethead(Pair _head);
	Linklist* addnode(Pair _newnode);
	void printlist() const;
	static int getnodecounter();
	Pair average() const;
	float geterror(float _b0, float _b1) const;
	//float getb0();
	float getb1();
private:
	Node* head;
	Node* end;
	static int nodecounter;
};


