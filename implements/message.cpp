#include <iostream>
#include <string.h>
#include <iomanip>
#include <stdlib.h>
#include "../libs/message.h"

using namespace std;


/* Constructores y Destructores */
Message::Message(){}
Message::~Message(){}
Message::Message(string text,string date,string sender,string numSender,bool flag){
    Set_Text(text);
    Set_Date(date);
    Set_Sender(sender);
    Set_NumSender(numSender);
    Set_Flag(flag);	
}

/* Getters and Setters*/
string Message::Get_Text(){return text;}
string Message::Get_Date(){return date;}
string Message::Get_Sender(){return sender;}
string Message::Get_NumSender(){return numSender;}
bool   Message::Get_Flag(){return flag;}

void   Message::Set_Text(string text){this->text=text;}
void   Message::Set_Date(string date){this->date=date;}
void   Message::Set_Sender(string sender){this->sender=sender;}
void   Message::Set_NumSender(string numSender){this->numSender=numSender;}
void   Message::Set_Flag(bool flag){this->flag=flag;}

/* Metodos */

void Message::Detail(){
	cout << endl;
	cout << "====================================================" << endl;
	cout << "Rcibido el dia: " << Get_Date() << endl;
	cout << "Nombre del Remitente: " << Get_Sender() << endl;
	cout << "Numero Telefonico: " << Get_NumSender() << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "                Mensaje "<<endl;
	cout << "----------------------------------------------------" << endl;
	cout << Get_Text() << endl;
	cout << "====================================================" << endl << endl;

}