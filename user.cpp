#include "user.h"
#include "nutrition.h"
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
	macro = new Macros();
	fitness = new Fitness();
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

Macros* UserData::getMacros() {
	return macro;
}

Fitness* UserData::getFitness() {
	return fitness;
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

void UserData::setMacros(Macros* m) {
	macro = m;
}

void UserData::setFitness(Fitness* fit) {
	fitness = fit;
}

//Deconstructor of UserData class
UserData::~UserData() {
//	delete macros;
}
