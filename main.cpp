#include <iostream>
#include "libs/user.h"

using namespace std;

int main(){
	char numero[250];
	User u("Octavio","55482623");

	cout << "Numero Valido: " <<  u.validNumber("55345678") << endl;
	u.Detail();
	cout << "Ingrese Nuevo numero: " ;
	cin  >> numero;
	u.Set_PhoneNumber(numero);
	u.Detail();
	return 0;	
}