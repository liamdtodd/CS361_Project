#include "user.h"
#include "driver.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;
using namespace chrono;
using namespace this_thread;

//this function will calculate the maintenance calories for the user based on their data
void calcmCal(UserData* user) {
	double hold = 0.0;
	hold = (88.4 + (13.4 * user->getWeight())) + (4.8 * user->getHeight()) - (5.68 * user->getAge());
	int calc = (int) hold;
	user->getMacros()->setmCal(calc);
}

//this function will request data from the microservice
void reqMicroservice(UserData* user) {
	fstream file;
	file.open("calculate_goals.txt", ios::out);
	
	file << "run\n";			//by writing 'run' to file, microservice now understands it's been requested
	file << user->getMacros()->getmCal() << endl;	
	file << user->getMacros()->getgCal() << endl;

	file.close();
}

//this function will get the data sent by the microservice
void dataMicroservice(UserData* user) {
	cout << "\nCalculating Goal Macros...\n";
	sleep_for(seconds(10));

	fstream file;
	file.open("calculate_goals.txt", ios::in);
	double readint;

	file >> readint;
	user->getMacros()->setProtein( ((int)readint) );
	
	file >> readint;
	user->getMacros()->setFat( ((int)readint) );
	
	file >> readint;
	user->getMacros()->setCarb( ((int)readint) );

	file.close();
}
	
//this function will set the macronutrient goals to the UserData object
void setUserMacros(UserData* user) {
        int readint;
        cout << "Would you like to: 1 - Choose your own macronutrient goals, or 0 - Use Computer generated macronutrient goals? ";
        cin >> readint;

        while ((readint != 1) && (readint != 0)) {
                cout << "\nWrong value entered. Please enter 1 or 0" << endl;
                cin >> readint;
        }

        calcmCal(user);

        if (readint == 0) {
                if (user->getType() == "bulk")
                        user->getMacros()->setgCal(user->getMacros()->getmCal() + 500);
                else
                        user->getMacros()->setgCal(user->getMacros()->getmCal() - 500);
 
		reqMicroservice(user);
		dataMicroservice(user);
        }

        else {
                cout << "Your maintenance calories were calculated to be: " << user->getMacros()->getmCal() << endl;
                cout << "Enter your goal for calories consumed in a day: ";
                cin >> readint;
                user->getMacros()->setgCal(readint);

                cout << "\nEnter your goal for grams of protein in a day: ";
                cin >> readint;
                user->getMacros()->setProtein(readint);

                cout << "\nEnter your goal for grams of fat in a day: ";
                cin >> readint;
                user->getMacros()->setFat(readint);

                cout << "\nEnter your goal for grams of carbohydrates in a day: ";
                cin >> readint;
                user->getMacros()->setCarb(readint);
        }
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
		
			file >> readint;
			user->getMacros()->setmCal(readint);
	
			file >> readint;
			user->getMacros()->setgCal(readint);
			
			file >> readint;
			user->getMacros()->setProtein(readint);
		
			file >> readint;
			user->getMacros()->setFat(readint);
			
			file >> readint;	
			user->getMacros()->setCarb(readint);
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
		file << user->getMacros()->getmCal() << " " << user->getMacros()->getgCal() << endl;
		file << user->getMacros()->getProtein() << " " << user->getMacros()->getFat() << " " << user->getMacros()->getCarb() << endl;
	} 					//first entry of data into userdata.txt
	else {
		file.open("userdata.txt", ios::out | ios::app);
		file << endl;
		file << user->getName() << endl;
		file << user->getAge() << endl;
		file << user->getHeight() << endl;
		file << user->getWeight() << endl;
		file << user->getType() << endl;
		file << user->getMacros()->getmCal() << " " << user->getMacros()->getgCal() << endl;
		file << user->getMacros()->getProtein() << " " << user->getMacros()->getFat() << " " << user->getMacros()->getCarb() << endl;
	}					//entry of a new user's data into userdata.txt with existing data from other users
	
	file.close();
}

//this function prints the user's data to the screen and verifies that it's correct
void checkData(UserData* user) {
        int ans;

        print(user);
        cout << "Would you like to change this data? 1 - yes, 0 - no" << endl;
        cin >> ans;

	if ((ans != 1) && (ans != 0)) {
		do {
			cout << "Wrong value entered! Please enter 1 - yes, 0 - no" << endl;
			cin >> ans;
		} while ((ans != 1) && (ans != 0));
	}

        if (ans == 1) {
                cout << "Alright, let's start over!" << endl;
                newDataUser(user);
		checkData(user);
        }

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

	setUserMacros(user);

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
		
			setUserMacros(user);
			file << user->getMacros()->getmCal() << " " << user->getMacros()->getgCal() << endl;
			file << user->getMacros()->getProtein() << " " << user->getMacros()->getFat() << " " << user->getMacros()->getCarb() << endl;
		}
	}
	
	file << "\n";
	file.close();
}

//this function print's all of the user's data to the screen
void print(UserData* user) {
	cout << "\n=====USER PROFILE=====" << endl;
	cout << "Name: " << user->getName() << endl;
	cout << "Age: " << user->getAge() << " years" << endl;
	cout << "Height: " << user->getHeight() << " inches" << endl;
	cout << "Weight: " << user->getWeight() << " pounds" << endl;
	cout << "Fitness Goal: " << user->getType() << endl;
	cout << "Maintenance Calories: " << user->getMacros()->getmCal() << endl;
	cout << "Goal Calories: " << user->getMacros()->getgCal() << endl;
	cout << "Grams of Protein: " << user->getMacros()->getProtein() << endl;
	cout << "Grams of Fat: " << user->getMacros()->getFat() << endl;
	cout << "Grams of Carbohydrates: " << user->getMacros()->getCarb() << endl << endl;
}