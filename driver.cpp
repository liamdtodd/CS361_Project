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
	file << user->getMacros()->getgCal() << endl;		//writing necessary data for microservice use

	file.close();
}

//this function will get the data sent by the microservice
void dataMicroservice(UserData* user) {
	cout << "\nCalculating Goal Macros...\n";

	fstream file;
	file.open("calculate_goals.txt", ios::in);
	double readint;

	file >> readint;
	user->getMacros()->setProtein( ((int)readint) );	//reading data from microservice
	
	file >> readint;
	user->getMacros()->setFat( ((int)readint) );
	
	file >> readint;
	user->getMacros()->setCarb( ((int)readint) );

	file.close();
}

//this function will create new fitness goals for the user
void newFitGoals(UserData* user) {
	int readint;
	cout << "Would you like to: 1 - Choose your own Fitness Plan, or 0 - Computer Generated Fitness Plan" << endl;
	cin >> readint;
	
	if (readint == 1)
		getFitData(user);
	else {
		user->getFitness()->addPush("Bench Press - 3x5");
		user->getFitness()->addPush("Incline Press - 3x8");
		user->getFitness()->addPush("Chest Flys - 3x10");
		user->getFitness()->addPush("Tricep Skullcrushers - 3x15");
		user->getFitness()->addPush("Tricep Rope Pulldowns - 3x10");
		user->getFitness()->addPush("Cable Shoulder Raises - 3x10");
		user->getFitness()->addPush("Arnold Shoulder Press - 3x12");

		user->getFitness()->addPull("Barbell Rows - 3x12");
		user->getFitness()->addPull("Lat Pulldown - 3x10");
		user->getFitness()->addPull("Cable Rows - 3x12");
		user->getFitness()->addPull("Straight-Arm Lat Pulldown - 3x10");
		user->getFitness()->addPull("Incline Bicep Curls - 3x8");
		user->getFitness()->addPull("Cross-Body Hammer Curls - 3x8");
		user->getFitness()->addPull("Preacher Curls - 2x10");

		user->getFitness()->addLegs("Back Squat - 3x5");
		user->getFitness()->addLegs("Romanian Deadlifts - 3x8");
		user->getFitness()->addLegs("Seated Calf Raise - 3x12");
		user->getFitness()->addLegs("Leg Press - 4x15");
		user->getFitness()->addLegs("Lying Leg Curl - 3x8");
		user->getFitness()->addLegs("Leg Extensions - 3x10");

		user->getFitness()->addCardio("30 min Jog");	//computer generated, the computer's recommendation
	}
	writeFittoFile(user);								//write this to user's data
}

//this function will get data from the user to fill their workout plan
void getFitData(UserData* user) {
	string readstr;

	while (readstr != "none") {
		cout << "Sample entry: 'Bench Press - 3x10'" << endl;
		cout << "Please enter Push day (chest, shoulder, tricep) workouts. Enter 'none' to stop" << endl;
		cin >> readstr;
		if (readstr != "none") 
			user->getFitness()->addPush(readstr);		//user enters own data
	}

	while (readstr != "none") {
		cout << "Please enter Pull day (back, bicep) workouts. Enter 'none' to stop" << endl;
		cin >> readstr;
		if (readstr != "none")
			user->getFitness()->addPull(readstr);		//user enters own data
	}

	while (readstr != "none") {
		cout << "Please enter Leg day (leg) workouts. Enter 'none' to stop" << endl;
		cin >> readstr;
		if (readstr != "none")
			user->getFitness()->addLegs(readstr);		//user enters own data
	}
	
	while (readstr != "none") {
		cout << "Please enter cardio (running, swimming, etc.) workouts. Enter 'none' to stop" << endl;
		cin >> readstr;
		if (readstr != "none")
			user->getFitness()->addCardio(readstr);		//user enters data
	}
	
}

//this function will write the fitness data to a separate user data file
void writeFittoFile(UserData* user) {
	fstream file;
	file.open("fitnessdata.txt", ios::out);
	
	file << user->getName() << endl;
	file << "PUSH" << endl;
	for (int x = 0; x < user->getFitness()->getPush().size(); x++)
		file << user->getFitness()->getPush()[x] << endl;	//write push data to file

	file << "\nPULL" << endl;
	for (int x = 0; x < user->getFitness()->getPull().size(); x++) 
		file << user->getFitness()->getPull()[x] << endl;	//write pull data to file

	file << "\nLEGS" << endl;
	for (int x = 0; x < user->getFitness()->getLegs().size(); x++)
		file << user->getFitness()->getLegs()[x] << endl;	//write leg data to file
	
	file << "\nCARDIO" << endl;
	for (int x = 0; x < user->getFitness()->getCardio().size(); x++)
		file << user->getFitness()->getCardio()[x] << endl;	//write cardio data to file

	file << "\n\n";
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
		dataMicroservice(user);			//microservice provides computer recommendation for user's nutrition
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
                user->getMacros()->setCarb(readint);		//user decides own nutrition plan
        }
}

//this function reads from userdata.txt to find an existing user's data
void fetchData(UserData* user, string nam) {
	fstream file;
	file.open("userdata.txt", ios::in);

	string readstr;
	int readint;

	while (!file.eof()) {				//go through file until name of user is found
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
			user->getMacros()->setCarb(readint);		//load all data of user into UserData* class
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
		} while ((ans != 1) && (ans != 0));		//error handle incorrect values
	}

        if (ans == 1) {
                cout << "Alright, let's start over!" << endl;
                newDataUser(user);				//will start updating user's data
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
	user->setType(type);					//storing user data into object 'user'

	setUserMacros(user);					//getting user's macros
	newFitGoals(user);						//getting user's fitness plan

	writeFileData(user);					//write user data to file
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
	newFitGoals(user);
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

//this function will display the user's fitness workout plan
void displayFitness(UserData* user) {
	string readstr, filestr;
	cout << "Please enter your name: ";
	cin >> readstr;
	fetchData(user, readstr);

	fstream file;
	file.open("fitnessdata.txt", ios::in);

	getline(file, filestr);
	while (!file.eof()) {				//go through file until user's name is found
		if (filestr == readstr) {
			while (!file.eof()) {
				getline(file, filestr);
				cout << filestr << endl;	//print user's fitness workout plan to screen
			}
		} else
			getline(file, filestr);
	}	
}
