#ifndef FITNESS_H
#define FITNESS_H
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

class Fitness {
private:
	vector<string> push;
	vector<string> pull;
	vetor<string> legs;
	vector<string> cardio;	

public:
	Fitness();

	vector<string> getPush();
	vector<string> getPull();
	vector<string> getLegs();
	vector<string> getCardio();

	void setPush(vector<string>);
	void setPull(vector<string>);
	void setLegs(vector<string>);
	void setCardio(vector<string>);

	Fitness(const Fitness&);
	Fitness& operator=(const Fitness&);
	~Fitness();

};

#endif
