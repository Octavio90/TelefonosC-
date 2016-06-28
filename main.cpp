#include <iostream>
#include "libs/user.h"

using namespace std;

int main(){
	char numero[250];
	User u("Octavio","55482623");

	cout << "Numero Valido: " <<  u.ValidNumber("55345678") << endl;
	u.Detail();
	cout << "Ingrese Nuevo numero: " ;
	cin  >> numero;
	u.Set_PhoneNumber(exit
		numero);
	u.Detail();
	return 0;	
}