#include <iostream>
#include "libs/user.h"
#include "libs/system.h"

using namespace std;

int main(){

	System system;

	char numero[250];
	User u("Octavio","5548262345");

	cout << "Numero Valido: " <<  u.ValidNumber("55345678") << endl;
	u.Detail();
	cout << "Ingrese Nuevo numero: " ;
	cin  >> numero;
	u.Set_PhoneNumber(numero);
	u.Detail();
	return 0;	
}