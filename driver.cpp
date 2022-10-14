#include "user.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;

void writeFileData(UserData* user) {
	string tempPath = "test.txt";
	fstream file;
	file.open("test.txt", ios::out);

	file << user->getName() << endl;
	file << user->getAge() << endl;
	file << user->getHeight() << endl;
	file << user->getWeight() << endl;
	file << user->getType() << endl;
	file << user->getfilePath() << endl;
	
	file.close();
}

void createUser(UserData* user) {
	string nam, type, path;
	int h, w, a;
	cout << "Please enter your name: ";
	cin >> nam;
	
	cout << endl << "Welcome " << nam << "! Let's get some basic information first." << endl;
	cout << "Please enter your age: ";
	cin >> a;
	
	cout << endl << "Please enter your height in inches (for reference, 6 feet is 72 inches): ";
	cin >> h;

	cout << endl << "Please enter your weight in pounds: ";
	cin >> w;
	
	cout << endl << "Are you looking to 'bulk' or 'cut' weight? ";
	cin >> type;

	cout << endl << "Please enter a name for text file where we will store your data: ";
	cin >> path;

	user->setName(nam);
	user->setAge(a);
	user->setHeight(h);
	user->setWeight(w);
	user->setType(type);
	user->setfilePath(path);

	writeFileData(user);
}

int main(int argc, char** argv) {
	int ans;
	string filepath;

	UserData* user = new UserData();

	cout << "Welcome to your home of fitness and nutrition!" << endl;
	
	if (argc == 1) {
		cout << "You have started the software without a file name. Are you a new user? 1 - yes, 0 - no" << endl;
		cin >> ans;
	
		if (ans == 1)
			createUser(user);
		else {
			cout << "Please enter a text file, so we can load your user data." << endl;
			cin >> filepath;
		}
	}
	
	else {
		filepath = argv[1];
		
	}

	return 0;
}
