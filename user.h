#ifndef USER_H
#define USER_H
#include <iostream>
#include <fstream>
#include <cstring>
#include "nutrition.h"
#include "fitness.h"

using namespace std;

class UserData {
private:
	string name;
	int height;
	int weight;
	int age;
	string fitnessType;
	Macros* macro;
	Fitness* fitness;

public:
	UserData();
	
	string getName();
	int getHeight();
	int getWeight();
	int getAge();
	string getType();
	Macros* getMacros();
	Fitness* getFitness();

	void setName(string);
	void setHeight(int);
	void setWeight(int);
	void setAge(int);
	void setType(string);
	void setMacros(Macros*);
	void setFitness(Fitness*);	

	~UserData();
};

#endif
