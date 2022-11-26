/*******************
 * This file contains all the function declarations that are implemented in
 * driver.cpp
 * ****************/
#ifndef DRIVER_H
#define DRIVER_H
#include "user.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

void calcmCal(UserData*);
int calcProtein(UserData*);
int calcFat(UserData*);
int calcCarb(UserData*);

void reqMicroservice(UserData*);
void dataMicroservice(UserData*);

void setUserMacros(UserData*);
void fetchData(UserData*, string);
void writeFileData(UserData*);
void checkData(UserData*);

void createUser(UserData*);
void newDataUser(UserData*);

void print(UserData*);
//void menu(UserData*, int);

#endif
