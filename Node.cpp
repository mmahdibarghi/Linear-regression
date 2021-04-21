#include "Node.h"
#include<iostream>
#include"Pair.h"

Node::Node(Pair _data,Node* _next=NULL):data(0,0)
{
	data = _data;

}
Node::Node()
{
	//data = Pair();
	nextnode = nullptr;

}

Node::~Node()
{
}

void Node::setnext(Node* _next)
{
	nextnode = _next;
	return;
}
void Node::setdata(Pair _data)
{
	data = _data;
	return;
}
Node* Node::getnext() const
{
	return nextnode;
}
Pair Node::getdata() const
{
	return data;
}