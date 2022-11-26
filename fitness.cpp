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
	push.clear();

	for (int x = 0; x < array.size(); x++) 
		push.push_back(array[x]);
}

void Fitness::setPull(vector<string> array) {
	pull.clear();

	for (int x = 0; x < array.size(); x++) 
		pull.push_back(array[x]);
}

void Fitness::setLegs(vector<string> array) {
	legs.clear();

	for (int x = 0; x < array.size(); x++) 
		legs.push_back(array[x]);
}

void Fitness::setCardio(vector<string> array) {
	cardio.clear();

	for (int x = 0; x < array.size(); x++) 
		cardio.push_back(array[x]);
}

/* Copy Constructor */
Fitness::Fitness(const Fitness& old_obj) {
	push.clear();
	pull.clear();
	legs.clear();
	cardio.clear();

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
		 push.clear();
	        pull.clear();
	        legs.clear();
	        cardio.clear();

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
