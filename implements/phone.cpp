#include <iostream>
#include <string.h>
#include <string>
#include "../libs/user.h"
#include "../libs/phone.h"

using namespace std;


Phone::Phone(){
	Set_Company("Motorola");
	Set_Model("X Play");
	Set_Version_SO("Android");
	Set_Camera_t("5 Mpx");
	Set_Camera_t("20 Mpx");
	Set_Owner("");
	Set_Mem_r(512);
	Set_Mem_rom(16);
	Set_Wight(200);
	Set_Price(5006.5);
	Set_PhoneNumber("");
}

Phone::~Phone(){}

