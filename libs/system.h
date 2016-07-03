#include <iostream>
#include "user.h"
#include "phone.h"
#ifndef SYSTEM_H
#define SYSTEM_H


using namespace std;

class System{
private:
	User*  users;
	int    numUsers;

	Phone* phones;
	int    numPhones;
	
	User* FindUser(string);
	User* FindUser(char *);
	User* FindUser(int);
	//Telefono
	
public:
	/*Constructores y Destructores*/
	System();
	~System();

	/*Getters and Setters*/
	void Set_NumUsers(int);
	//telefono
	void Set_NumPhones(int);

	int  Get_NumUsers();
	//getter telefono
	int Get_NumPhones();
	
	/*Metodos*/ 
	bool  NewUser();
	void  PrintBill();
	bool  BuyPhone();
	void  PrintUser(int);
	void  PrintUser(string);
	void  PrintUser(char *);
	void  PrintAllUsers();
	//metodos de telefono
	void  Detail_Phone();
};

#endif
