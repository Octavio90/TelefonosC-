#include <iostream>
#include "listphone.h"
#ifndef USER_H
#define USER_H

using namespace std;


class User{
private:
	int       numPhones;
	int 	  idUser;
	float     credit;
	string    name;
	string    address;
	ListPhone phones;

public:
	/*Constructores y Destructores*/
	User();
	User(string,string);
	User(string,string,float,int);
	~User();
	
	/*Getters and Setters*/ 
	void    Set_Name(string);
	void    Set_Address(string);
	void    Set_Credit(float);
	void    Set_IdUser(int);


	string  Get_Name();
	string  Get_Address();
	float   Get_Credit();
	int     Get_NumPhones();
	int     Get_IdUser();
	ListPhone* Get_Phones();	 
	/*Metodos*/
	void   Detail();
};

#endif
