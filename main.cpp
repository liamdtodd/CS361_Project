/***********************
 * Liam Todd
 * This file will run the entire software
 * ********************/
#include "user.h"
#include "nutrition.h"
#include "driver.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main(int argc, char** arv) {
	UserData* user = new UserData();

	menu(user, argc);

	delete user;
	return 0;
}
