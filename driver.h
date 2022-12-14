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

/* Calculate Maintenance Cals */
void calcmCal(UserData*);

/* Microservice */
void reqMicroservice(UserData*);
void dataMicroservice(UserData*);

/* New Goals */
void newFitGoals(UserData*);
void writeFittoFile(UserData*);
void getFitData(UserData*);

/* User's Data */
void setUserMacros(UserData*);
void fetchData(UserData*, string);
void writeFileData(UserData*);
void checkData(UserData*);

/* Create/New Data */
void createUser(UserData*);
void newDataUser(UserData*);

/* Printing User's Data */
void print(UserData*);
void displayFitness(UserData*);

#endif
