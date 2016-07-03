#include <iostream>
#include "libs/list.h"

using namespace std;

int main(){
	char op;
	List lista;
	lista.PrintALL();
	cout << "======================" << endl;	
	lista.NewElement();
	cout << "======================" << endl;
	lista.PrintALL();
	cout << "Quieres otro usuario? (y/n): ";
	cin  >>  op;
	while(op != 'n'){
		lista.NewElement();
		cout << "Quieres otro usuario? (y/n): ";
		cin  >>  op;
	}
	lista.PrintALL();
	lista.FindByName("octavio");
	lista.FindByNumPhones(2);
	return 0;
}
