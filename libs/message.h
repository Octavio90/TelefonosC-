#include <iostream>
#ifndef MESSAGE_H
#define MESSAGE_H

using namespace std;

class Message{
private:
	bool    flag;
	string  text;
	string  date;
	string  sender;
	string  numSender;        
public:
	Message();
	Message(string,string,string,string,bool);
	~Message();

	bool   Get_Flag();
	string Get_Text();
	string Get_Date();
	string Get_Sender();
	string Get_NumSender();

 	void Set_Flag(bool);	
 	void Set_Text(string);
 	void Set_Date(string);
 	void Set_Sender(string);
 	void Set_NumSender(string);

	void Detail();
};

#endif