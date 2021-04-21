#include<iostream>
#include<stdio.h>
#include"Pair.h"
#include"Node.h"
#include"Linklist.h"
#include"Regressionmodel.h"
using namespace std;

int main()
{
	/*
	//Pair p1(0, 0);
	cout << Pair::getcounter()<<endl;
	Pair p1;
	Pair p2(3, 3);
	Pair p3(4, 4);
	Pair p5(2, 2);
	Pair p6(5, 5);
	cout<<p2.getx()<<endl;
	cout << p2.gety()<<endl;
	cout << Pair::getcounter() << endl;
	//Node n2(p2, NULL);
	//Node n1(p1, NULL);
	//cout << (n1.getdata()).getx()<<endl;
	cout << "************\n";
	Linklist l1(p2);
	l1.addnode(p1);
	l1.addnode(p3);
	l1.addnode(p5)->addnode(p6);
	l1.printlist();
	
	cout << "***********\n";
	cout << Pair::getcounter() << endl;
	cout << "***********\n";
	cout << Linklist::getnodecounter() << endl;
	cout << "***********\n";
	cout << l1.average().getx()<<endl;
	*/
	cout << "************\n";
	cout << "************\n";
	cout << "model test:\n";
	cout << "************\n";
	Regressionmodel r1("data.txt");
	r1.info();
	cout<<r1.predict(7)<<endl;
	return 0;
}