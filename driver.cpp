#include "user.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;

//this function print's all of the user's data to the screen
void print(UserData* user) {
	cout << "Name: " << user->getName() << endl;
	cout << "Age: " << user->getAge() << " years" << endl;
	cout << "Height: " << user->getHeight() << " inches" << endl;
	cout << "Weight: " << user->getWeight() << " pounds" << endl;
	cout << "Fitness Goal: " << user->getType() << endl;
}

//this function reads from userdata.txt to find an existing user's data
void fetchData(UserData* user, string nam) {
	fstream file;
	file.open("userdata.txt", ios::in);

	string readstr;
	int readint;

	while (!file.eof()) {
		file >> readstr;
		if (readstr == nam) {
			user->setName(readstr);
			
			file >> readint;
			user->setAge(readint);
	
			file >> readint;
			user->setHeight(readint);
			
			file >> readint;
			user->setWeight(readint);
	
			file >> readstr;
			user->setType(readstr);
		}
	}
		
	file.close();
}

//this function writes all the user's data into the userdata.txt file
void writeFileData(UserData* user) {
	fstream file;

	if (file.eof()) {
		file.open("userdata.txt", ios::out);
		file << user->getName() << endl;
		file << user->getAge() << endl;
		file << user->getHeight() << endl;
		file << user->getWeight() << endl;
		file << user->getType() << endl;
	} 					//first entry of data into userdata.txt
	else {
		file.open("userdata.txt", ios::out | ios::app);
		file << endl;
		file << user->getName() << endl;
		file << user->getAge() << endl;
		file << user->getHeight() << endl;
		file << user->getWeight() << endl;
		file << user->getType() << endl;
	}					//entry of a new user's data into userdata.txt with existing data from other users
	
	file.close();
}

//this function takes in a UserData object and fills it with the corresponding data
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

	user->setName(nam);
	user->setAge(a);
	user->setHeight(h);
	user->setWeight(w);
	user->setType(type);

	writeFileData(user);
}

//this function will delete wrong information in the file and replace it with the new, correct information
void newDataUser(UserData* user) {
	string nam = user->getName();
	string readstr;
	int readint;
	int pos;
	fstream file;
	file.open("userdata.txt", ios::in | ios:: out);

	while (!file.eof()) {
		file >> readstr;	
		if (readstr == nam) {
			pos = file.tellg();
			file.seekg(pos - nam.length());		//getting to position of incorrect data position
			
			cout << "Please enter your name: ";
			cin >> readstr;
			user->setName(readstr);
			file << readstr << endl;	//setting new name info in user and text file

			cout << "\nEnter your age: ";
			cin >> readint;
			user->setAge(readint);
			file << readint << endl;	//setting new age infor in user and text file

			cout << "\nEnter your height: ";
			cin >> readint;
			user->setHeight(readint);
			file << readint << endl;	//setting new height info in user and text file
	
			cout << "\nEnter your weight: ";
			cin >> readint;
			user->setWeight(readint);
			file << readint << endl;	//setting new weight infor in user and text file
	
			cout << "\nAre you 'bulk' or 'cut' weight: ";
			cin >> readstr;
			user->setType(readstr);
			file << readstr << endl;	//setting new goal info in user and text file
		}
	}
	
	file.close();
}

//this function prints the user's data to the screen and verifies that it's correct
void checkData(UserData* user) {
        int ans;

        print(user);
        cout << "Does this information look correct? 1 - yes, 0 - no" << endl;
        cin >> ans;

	if ((ans != 1) && (ans != 0)) {
		do {
			cout << "Wrong value entered! Please enter 1 - yes, 0 - no" << endl;
			cin >> ans;
		} while ((ans != 1) && (ans != 0));
	}

        if (ans == 0) {
                cout << "Alright, let's start over!" << endl;
                newDataUser(user);
		checkData(user);
        }

}

int main(int argc, char** argv) {
	int ans;
	string nam;

	UserData* user = new UserData();

	cout << "Welcome to your home of fitness and nutrition!" << endl;
	
	if (argc == 1) {
		cout << "You have started the software without a file name. Are you a new user? 1 - yes, 0 - no" << endl;
		cin >> ans;
	
		if ((ans != 1) && (ans != 0)) {
			do {
				cout << "Wrong value entered! Please enter: 1 - yes, 0 - no" << endl;
				cin >> ans;
			} while ((ans != 1) && (ans != 0));
		}
		if (ans == 1)
			createUser(user);
		else {
			cout << "For future use, you can run the software with 'userdata.txt' as an additional arg. Please enter your name: ";
			cin >> nam;
			cout << endl;
		}
	}
	
	else {
		cout << "Please enter your name: ";
		cin >> nam;
		cout << endl;
		fetchData(user, nam);		
	}

	checkData(user);

	delete user;
	return 0;
}
