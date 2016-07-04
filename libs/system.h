#include <iostream>
#include "user.h"
#include "list.h"
#ifndef SYSTEM_H
#define SYSTEM_H


using namespace std;

class System{
public:
	List users;

	/*Constructores y Destructores*/
	System();
	~System();

	/*Metodos*/ 
	void NewUser();
	void FindUser();
	void PrintAllUsers();
	int  NumUsers();
	void PrintMessage();
};

#endif
