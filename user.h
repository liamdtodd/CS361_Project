#ifndef USER_H
#define USER_H
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class UserData {
private:
	string name;
	int height;
	int weight;
	int age;
	string fitnessType;

public:
	UserData();
	
	string getName();
	int getHeight();
	int getWeight();
	int getAge();
	string getType();

	void setName(string);
	void setHeight(int);
	void setWeight(int);
	void setAge(int);
	void setType(string);
	
	~UserData();
};

#endif
