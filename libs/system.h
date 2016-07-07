#include <iostream>
#include "list.h"
#ifndef SYSTEM_H
#define SYSTEM_H


using namespace std;

class System{
private:
	int contUser;
	int contPhone;
	int contBill; 

public:
	List<User>   users;
	List<Phone>  phones;
	List<Bill>   bills;

	/*Constructores y Destructores*/
	System();
	~System();

	/* Getters and Setters*/

	void Set_ContUser(int);
	void Set_ContPhone(int);
	void Set_ContBill(int); 

	int Get_ContUser();
	int Get_ContPhone();
	int Get_ContBill(); 

	/*Metodos*/
	void PrintMessage();
	void BuyPhone();
	void SendMessage();
	void ViewMessage();
	
		/* Facturas */
	void NewBill(User &, Phone &);
	void FindBill();
	void PrintAllBills();

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
