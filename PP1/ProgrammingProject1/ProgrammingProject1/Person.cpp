#include "pa1.h"

// person constructor
Person::Person ()
{
	this->position = 1;
}

// person constructor
Person::Person (int ID)
{
	this->position = ID;
}

// person destructor
Person::~Person ()
{
}

// return the id of the person
int Person::returnPosition ()
{
	return this->position;
}

// print the id of the person
void Person::print ()
{
	cout << this->position;
}