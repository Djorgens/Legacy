#pragma once
#include "People & Creatures.h"

class Household
{
private:
	int cap;
	int nrOfPpl;
	Person **PersonList;
	void expand();
	void initialize(const int from = 0);

public:
	Household();
	~Household();
	Household(const Household &obj);
	inline int size()const {return this->nrOfPpl;};
	Person& operator[](const int index);
	void operator=(const Household &obj);
	void addPerson(Person &person);
	void removePerson(int index);
};
