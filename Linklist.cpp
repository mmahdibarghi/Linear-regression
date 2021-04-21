#include "Linklist.h"
#include"Node.h"
#include<iostream>

using namespace std;
int Linklist::nodecounter = 0;
int Linklist::getnodecounter()
{
	return nodecounter;
}
Linklist::Linklist()
{

	
	head = nullptr;
	end = nullptr;
	//nodecounter++;
}
Linklist::Linklist(Pair _head)
{
	
	Node* headnode = (Node*)malloc(sizeof(Node));
	headnode->setdata(_head);
	headnode->setnext(nullptr);
	
	//Node* headnode=new Node(_head,nullptr);
	
	
	head = headnode;
	end = headnode;
	nodecounter++;
}

void Linklist::sethead(Pair _head)
{
	Node* headnode = (Node*)malloc(sizeof(Node));
	headnode->setdata(_head);
	headnode->setnext(nullptr);

	//Node* headnode=new Node(_head,nullptr);


	head = headnode;
	end = headnode;
	nodecounter++;
}
Linklist::~Linklist()
{
	Node* remove=head;
	Node* wait = head->getnext();
	while (wait != nullptr)
	{
		delete remove;
		remove = wait;
		wait = wait->getnext();
	}
	delete remove;
	nodecounter--;
}
Linklist::Linklist(const Linklist &oldlinklist)
{
	Node* head = new (Node);
	this->head = oldlinklist.head;
	Node* end = new (Node);
	this->end = oldlinklist.end;
	nodecounter++;
}
Linklist* Linklist::addnode(Pair _newnode)
{
	if (head == nullptr)
	{
		this->sethead(_newnode);
		return this;
	}
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->setdata(_newnode);
	newnode->setnext(nullptr);
	
	//Node* newnode=new Node(_newnode,nullptr);
	end->setnext(newnode);
	end = newnode;
	nodecounter++;
	return this;
}
void Linklist::printlist() const
{
	Node* tmp;
	tmp = head;
	while (tmp!=nullptr)
	{
		cout << tmp->getdata().getx() <<" "<< tmp->getdata().getx()<<endl;
		tmp = tmp->getnext();
	}
}
Pair Linklist::average() const
{
	float sumx = 0;
	float sumy = 0;
	Node* tmp;
	tmp = head;
	while (tmp != nullptr)
	{
		sumx += tmp->getdata().getx();
		sumy += tmp->getdata().gety();
		tmp = tmp->getnext();
	}
	Pair avg(sumx/nodecounter, sumy/nodecounter, 1);
	return avg;
}
float Linklist::geterror(float _b0, float _b1) const
{
	float error=0;
	float modely;
	float ei;
	Node* tmp;
	tmp = head;
	while (tmp != nullptr)
	{
		//ei = 0;
		modely = (tmp->getdata().getx()*_b1) + _b0;
		if (modely >= tmp->getdata().gety())
		{
			ei = modely - tmp->getdata().gety();
		}
		else
		{
			ei = tmp->getdata().gety() - modely;
		}
		ei *= ei;
		error += ei;
		tmp = tmp->getnext();
	}
	error /= nodecounter;
	return error;
}
float Linklist::getb1()
{
	float sorat=0;
	float makhraj=0;
	float b1;
	Node* tmp;
	tmp = head;
	//Linklist test = *this;
	while (tmp != nullptr)
	{
		sorat += (((tmp->getdata().getx()) - (this->average().getx()))*((tmp->getdata().gety()) - (this->average().gety())));
		makhraj += (((tmp->getdata().getx()) - (this->average().getx()))*((tmp->getdata().getx()) - (this->average().getx())));
		tmp = tmp->getnext();
	}
	b1 = sorat / makhraj;
	return b1;
}