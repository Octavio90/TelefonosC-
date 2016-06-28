#include <iostream>
#include <string.h>
#include "../libs/user.h"

using namespace std;


/* Constructores y Destructores */
User::User(){

}

User::User(string name ,const char* phoneNumber){

}

User::User(string name,string address,const char* phoneNumber,float credit,int numPhones){

}

User::~User(){

}

/* Getters y Setters */
void   User::Set_Name(string name){}
void   User::Set_Address(string address){}
void   User::Set_PhoneNumber(const char* phoneNumber){}
void   User::Set_Credit(float credit){}
void   User::Set_NumPhones(int numPhones){}

string User::Get_Name(){return this->name;}
string User::Get_Address(){return this->address;}
char*  User::Get_PhoneNumber(){return this->phoneNumber;}
float  User::Get_Credit(){return this->credit;}
int    User::Get_NumPhones(){return this->numPhones;}

/* Metodos */
void   User::Detail(){}
bool   User::validNumber(char*){return false;}