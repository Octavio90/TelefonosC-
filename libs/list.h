#include <iostream>
#include "node.h"
#include "user.h"
#ifndef LIST_H
#define LIST_H


using namespace std;

class List{
private:
	Node <User> *first;
	Node <User> *last;
	int   numElements;
public:
	List();
	int   Get_NumElements();
	bool  Empty();
	void  NewElement(User &);
	void  PrintALL();
	User* FindByID(int);
	void  FindByName(string);
	void  FindByNumPhones(int);
};

#endif
