#include "user.h"
#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

UserData::UserData() {
	name = " ";
	height = 0;
	weight = 0;
	age = 0;
	fitnessType = " ";
}

/**************************
 * ACCESSOR FUNCTIONS FOR THE USERDATA CLASS
 * ************************/
string UserData::getName() {
	return name;
}

int UserData::getHeight() {
	return height;
}

int UserData::getWeight() {
	return weight;
}

int UserData::getAge() {
	return age;
}

string UserData::getType() {
	return fitnessType;
}


/************************
 * SETTER FUNCTIONS FOR THE USERDATA CLASS
 * *********************/
void UserData::setName(string nam) {
	name = nam;
}

void UserData::setHeight(int h) {
	height = h;
}

void UserData::setWeight(int w) {
	weight = w;
}

void UserData::setAge(int a) {
	age = a;
}

void UserData::setType(string fit) {
	fitnessType = fit;
}

//Deconstructor of UserData class
UserData::~UserData() {}
