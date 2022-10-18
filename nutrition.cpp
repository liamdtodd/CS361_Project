#include "nutrition.h"
#include "user.h"
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

/********************
 * CONSTRUCTOR
 * *****************/
Macros::Macros() {
	protein = 0;
	fat = 0;
	carb = 0;
	mCal = 0;
	gCal = 0;
}

/********************
 * ACCESSOR FUNCTIONS FOR MACROS
 * ******************/
int Macros::getProtein() {
	return protein;
}

int Macros::getFat() {
	return fat;
}

int Macros::getCarb() {
	return carb;
}

int Macros::getmCal() {
	return mCal;
}

int Macros::getgCal() {
	return gCal;
}

/**********************
 * SETTER FUNCTIONS FOR MACROS
 * *******************/
void Macros::setProtein(int p) {
	protein = p;
}

void Macros::setFat(int f) {
	fat = f;
}

void Macros::setCarb(int c) {
	carb = c;
}

void Macros::setmCal(int m) {
	mCal = m;
}

void Macros::setgCal(int g) {
	gCal = g;
}

/********************
 * COPY CONSTRUCTOR
 * *****************/
Macros::Macros(const Macros& old_obj) {
	protein = old_obj.protein;
	fat = old_obj.fat;
	carb = old_obj.carb;
	mCal = old_obj.mCal;
	gCal = old_obj.gCal;
}

/**********************
 * ASSIGNMENT OPERATOR OVERLOADER
 * *******************/
Macros& Macros::operator=(const Macros& old_obj) {
	if (this != &old_obj) {
		protein = old_obj.protein;
		fat = old_obj.fat;
		carb = old_obj.carb;
		mCal = old_obj.mCal;
		gCal = old_obj.gCal;
	}
	return *this;
}

/***********************
 * DECONSTRUCTOR
 * ********************/
Macros::~Macros() {}
