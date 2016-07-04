#include <iostream>
#ifndef USER_H
#define USER_H


using namespace std;

class User{
private:
	string  name;
	string  address;
	float   credit;
	int     numPhones;
public:
	/*Constructores y Destructores*/
	User();
	User(string,string);
	User(string,string,float);
	~User();

	
	/*Getters and Setters*/ 
	void   Set_Name(string);
	void   Set_Address(string);
	void   Set_Credit(float);
	void   Set_NumPhones(int);

	string  Get_Name();
	string  Get_Address();
	float   Get_Credit();
	int     Get_NumPhones();
	/*Metodos*/ 

	void Detail();
};

#endif
