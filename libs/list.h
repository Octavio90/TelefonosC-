#include <iostream>
#include "node.h"
#ifndef LIST_H
#define LIST_H


using namespace std;

class List{
private:
	Node *first;
	Node *last;
public:
	List();
	bool Empty();
	void NewElement();
	void PrintALL();
	void FindByName(string);
	void FindByNumPhones(int);
};

#endif
