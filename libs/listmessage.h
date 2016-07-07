#include <iostream>
#include "message.h"
#ifndef LISTMESSAGE_H
#define LISTMESSAGE_H


using namespace std;

class NodeMessage{
public:
	Message     element;
	NodeMessage *next;

	NodeMessage(Message &);
	Message* Get_Element();
};

class ListMessage{
private:
	NodeMessage *first;
	NodeMessage *last;
	int   numElements;
public:
	ListMessage();
	int    Get_NumElements();
	bool   Empty();
	void   NewElement(Message &);
	void   PrintAll();
};


#endif