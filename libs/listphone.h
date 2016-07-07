#include <iostream>
#ifndef LISTPHONE_H
#define LISTPHONE_H


using namespace std;

class NodePhone{
public:
	string    *element;
	NodePhone *next;

	NodePhone(string *);
	string* Get_Element();
};

class ListPhone{
private:
	NodePhone *first;
	NodePhone *last;
	int   numElements;
public:
	ListPhone();
	int    Get_NumElements();
	bool   Empty();
	void   NewElement(string *);
	void   PrintAll();
	void   Remove(string);
};


#endif
