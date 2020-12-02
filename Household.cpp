#include "Household.h"

Household::Household()
{
	this->cap = 5;
	this->nrOfPpl = 0;
	this->PersonList = new Person*[cap];
	this->initialize();
}

Household::~Household()
{
	for (size_t i = 0; i < this->nrOfPpl; i++)
	{
		delete this->PersonList[i];
	}
	delete[] this->PersonList;
}

Household::Household(const Household &obj)
{
	this->cap = obj.cap;
	this->nrOfPpl = obj.nrOfPpl;
	this->PersonList = new Person*[this->cap];

	for (size_t i = 0; i < this->nrOfPpl; i++)
	{
		this->PersonList[i] = obj.PersonList[i]->clone();
	}

	initialize(this->nrOfPpl);
}

Person& Household::operator[](const int index)
{
	if (index < 0 || index >= this->nrOfPpl)
		throw("BAD INDEX!");

	return *this->PersonList[index];
}

void Household::operator=(const Household &obj)
{
	for (size_t i = 0; i < this->nrOfPpl; i++)
	{
		delete this->PersonList[i];
	}
	delete[] this->PersonList;

	this->cap = obj.cap;
	this->nrOfPpl = obj.nrOfPpl;
	this->PersonList = new Person*[this->cap];

	for (size_t i = 0; i < this->nrOfPpl; i++)
	{
		this->PersonList[i] = obj.PersonList[i]->clone();
	}

	initialize(this->nrOfPpl);
}

void Household::expand()
{
	this->cap *= 2;

	Person **tempArr = new Person*[this->cap];

	for (size_t i = 0; i < this->nrOfPpl; i++)
	{
		tempArr[i] = this->PersonList[i];
	}

	delete[] this->PersonList;

	this->PersonList = tempArr;

	this->initialize(this->nrOfPpl);
}

void Household::initialize(const int from)
{
	for (size_t i = from; i < cap; i++)
	{
		this->PersonList[i] = nullptr;
	}
}

void Household::addPerson(Person &person)
{
	if (this->nrOfPpl >= this->cap)
	{
		expand();
	}

	this->PersonList[this->nrOfPpl++] = person.clone();
}

void Household::removePerson(int index)
{
	if (index < 0 || index >= this->nrOfPpl)
		throw("OUT OF BOUNDS REMOVE ITEM INVENTORY");

	delete this->PersonList[index];
	this->PersonList[index] = this->PersonList[this->nrOfPpl - 1];
	this->PersonList[--this->nrOfPpl] = nullptr;
}

