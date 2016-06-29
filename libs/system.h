#include <iostream>
#include "user.h"
//#include "phone.h"
#ifndef SYSTEM_H
#define SYSTEM_H


using namespace std;

class System{
private:
	User*  users;
	int    numUsers;
	//Phone* phones;
	User* FindUser(string);
	User* FindUser(char *);
	User* FindUser(string,char*);

public:
	/*Constructores y Destructores*/
	System();
	~System();

	/*Getters and Setters*/
	void Set_NumUsers(int);

	int  Get_NumUsers();
	
	/*Metodos*/ 
	bool  NewUser();
	void  PrintBill();
	bool  BuyPhone();
	void  PrintAllUsers();
	void  PrintUser(string);
	void  PrintUser(char *);
};

#endif
