#include <iostream>
#include "user.h"
#include "list.h"
#ifndef SYSTEM_H
#define SYSTEM_H


using namespace std;

class System{
public:
	List<User>   users;
	List<Phone>  phones;
	//List<Bill>   bills;

	/*Constructores y Destructores*/
	System();
	~System();

	/*Metodos*/
	void PrintMessage();

		/* Usuario */ 
	void NewUser();
	void FindUser();
	void ModifyUser();
	void PrintAllUsers();
	int  NumUsers();
	
		/* Telefonos */
	int  NumPhones();
	void NewPhone();
	void ModifyPhone();
	void PrintAllPhones();
	void FindPhone();
};

#endif
