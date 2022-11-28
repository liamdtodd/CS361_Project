//implementation of the fitness.h file
#include "fitness.h"
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

Fitness::Fitness() {
	//var of type 'vector' are already initialized and empty
}

/********* GETTERS ************/
vector<string> Fitness::getPush() {
	return push;
}

vector<string> Fitness::getPull() {
	return pull;
}

vector<string> Fitness::getLegs() {
	return legs;
}

vector<string> Fitness::getCardio() {
	return cardio;
}

/*********** SETTERS *************/
void Fitness::setPush(vector<string> array) {
	for (int x = 0; x < array.size(); x++) 
		push.push_back(array[x]);
}

void Fitness::setPull(vector<string> array) {
	for (int x = 0; x < array.size(); x++) 
		pull.push_back(array[x]);
}

void Fitness::setLegs(vector<string> array) {
	for (int x = 0; x < array.size(); x++) 
		legs.push_back(array[x]);
}

void Fitness::setCardio(vector<string> array) {
	for (int x = 0; x < array.size(); x++) 
		cardio.push_back(array[x]);
}

/* ADD VALUES TO FITNESS VECTORS */
void Fitness::addPush(string val) {
	push.push_back(val);
}

void Fitness::addPull(string val) {
	pull.push_back(val);
}

void Fitness::addLegs(string val) {
	legs.push_back(val);
}

void Fitness::addCardio(string val) {
	cardio.push_back(val);
}

/* Copy Constructor */
Fitness::Fitness(const Fitness& old_obj) {

    for (int x = 0; x < old_obj.push.size(); x++)
        push.push_back(old_obj.push[x]);
	for (int x = 0; x < old_obj.pull.size(); x++)
		pull.push_back(old_obj.pull[x]);
	for (int x = 0; x < old_obj.legs.size(); x++)
		legs.push_back(old_obj.legs[x]);
	for (int x = 0; x < old_obj.cardio.size(); x++)
		cardio.push_back(old_obj.cardio[x]);
}

/* Assignment Operator Overloader */
Fitness& Fitness::operator=(const Fitness& old_obj) {
	if (this != &old_obj) {

	        for (int x = 0; x < old_obj.push.size(); x++)
	                push.push_back(old_obj.push[x]);
	        for (int x = 0; x < old_obj.pull.size(); x++)
	                pull.push_back(old_obj.pull[x]);
	        for (int x = 0; x < old_obj.legs.size(); x++)
               		legs.push_back(old_obj.legs[x]);
	        for (int x = 0; x < old_obj.cardio.size(); x++)
        	        cardio.push_back(old_obj.cardio[x]);
	}

	return *this;
}

/* Deconstructor */
Fitness::~Fitness() {}
