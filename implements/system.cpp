#include <iostream>
#include <string.h>
#include "../libs/system.h"
#include "../libs/user.h"

using namespace std;


/* Constructores y Destructores */
System::System(){}

System::~System(){}

/* Getters y Setters */

void System::Set_NumUsers(int numUsers){this->numUsers=numUsers;}

int  System::Get_NumUsers(){return numUsers;}


/* Metodos */
void  System::PrintBill(){}

void  System::PrintAllUsers(){
	User *user = users;
	for(int i=0;i<Get_NumUsers();i++){
		(++user)->Detail();
	}
}

void  System::PrintUser(string name){
	User* user = FindUser(name);
	user->Detail(); 
}

void  System::PrintUser(char* phone){
	User* user = FindUser(phone);
	user->Detail(); 
}

bool  System::NewUser(){

}


bool  System::BuyPhone(){}
User* System::FindUser(string name){}
User* System::FindUser(char* phone){}
User* System::FindUser(string name,char* phone){}