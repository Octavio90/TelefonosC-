#include <iostream>
#include "user.h"
#include "phone.h"
#ifndef BILL_H
#define BILL_H

using namespace std;


class Bill{
private:
	int    idBill;
	float  amount;
	User*  user;
	Phone* phone;
	string date;
public:
	/*Constructores y Destructores*/
	Bill();
	Bill(User &,Phone &,float,string,int);
	~Bill();
	/*Getters and Setters*/ 
	User*  Get_User();
	Phone* Get_Phone();
	string Get_Date();
	float  Get_Amount();
	int    Get_IdBill();

	void Set_User(User*);
	void Set_Phone(Phone*);
	void Set_Amount(float);
	void Set_Date(string);	 
	void Set_IdBill(int);

	/*Metodos*/
	void   Detail();
};

#endif
