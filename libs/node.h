#include <iostream>
#include <string>
#include "user.h"
#ifndef NODE_H
#define NODE_H


using namespace std;

class Node{
public:
	User  element;
	Node  *next;

	Node(User &);
	User* Get_Element();
};

#endif
