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

void menu(UserData*);

int main(int argc, char** arv) {
	UserData* user = new UserData();

	menu(user, argc);

	delete user;
	return 0;
}

//this function displays the menu to the user and their options to select
void menu(UserData* user) {
	int readint;
	string readstr;
	cout << "Welcome to your home of fitness and nutrition!" << endl;
	
	cout << "\n=====MENU OF OPTIONS=====" << endl;
	cout << "0. Exit" << endl;
	cout << "1. Create New User Profile\t***Will save your data for next time's use!" << endl;
	cout << "2. Load Existing User Profile" << endl;
	cout << "3. Update User Profile\t***Change every field of User Profile" << endl;
	cout << "4. Load New Nutrition Goals" << endl;
	cout << "5. Load New Fitness Goals" << endl;

	cout << "\nEnter an option: ";
	cin >> readint;

	while ((readint < 1) && (readint > 5)) {
		cout << "You have entered an invalid number, please enter 0, 1, 2, 3, 4, or 5" << endl;
		cin >> readint;
	}

	while ((readint > 0) && (readint < 6)) {
		if (readint == 1)
			createUser(user);
		else {
			cout << "\nPlease enter your name: ";
			cin >> readstr;
			fetchData(user, readstr);
		}

		if ((readint == 2) || (readint == 3))
			checkData(user);
		else if (readint == 4)
			newNutGoals(user);
		else if (readint == 5)
			newFitGoals(user);	

		clear();
		cout << "\n=====MENU OF OPITONS=====" << endl;
		cout << "0. Exit" << endl;
		cout << "1. Create New User Profile\t***Will save your data for next time's use!" << endl;
		cout << "2. Load Existing User Profile" << endl;
		cout << "3. Update User Profile\t***Change every field of User Profile" << endl;
		cout << "4. Load New Nutrition Goals" << endl;
		cout << "5. Load New Fitness Goals" << endl;

		cout << "\nEnter an option: ";
		cin >> readint;
	}
}
