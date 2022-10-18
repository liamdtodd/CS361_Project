#ifndef NUTRITION_H
#define NUTRITION_H
//#include "user.h"
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

class Macros {
private:
	int protein;
	int fat;
	int carb;
	int mCal;
	int gCal;

public:
	Macros();

	int getProtein();
	int getFat();
	int getCarb();
	int getmCal();
	int getgCal();

	void setProtein(int);
	void setFat(int);
	void setCarb(int);
	void setmCal(int);
	void setgCal(int);

	Macros(const Macros&);
	Macros& operator=(const Macros&);
	~Macros();
};

#endif
