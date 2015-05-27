#include "pa1.h"
//constructor
ListMyJosephus::ListMyJosephus ()
{
	init (5, 2);
}

//constructor
ListMyJosephus::ListMyJosephus (int N, int M)
{
	init (N, M);
}

//destructor
ListMyJosephus::~ListMyJosephus ()
{
}

// initializes the player circle
void ListMyJosephus::init (int N, int M)
{
	int i = 0;

	while (i < N)
	{
		i++;
		this->circ.push_back(i);
	}

	this->N = N;
	this->M = M;
	this->size = N;
}

// clears the player circle of all players
void ListMyJosephus::clear ()
{
	this->circ.clear ();
}

// checks if the circle is empty
bool ListMyJosephus::isEmpty()
{
	return this->circ.empty ();
}
// returns the current size of the circle
int ListMyJosephus::currentSize()
{
	return this->size;
}

// eliminates the next player in the list to be eliminated
list<Person>::iterator ListMyJosephus::eliminateNext (list<Person>::iterator i)
{
	int j = 0, id = 0;
	list<Person>::iterator k;

	for (j = 0; j < this->M; j++)
	{
		if (i == --circ.end())
			i = circ.begin ();
		else
			i++;
	}

	k = i;
	k++;
	if (k == circ.end())
		k = circ.begin ();

	circ.erase (i);
	this->size--;

	return k;
}

// returns the id of the winner
int ListMyJosephus::returnWinner()
{
	list<Person>::iterator i;
	i = circ.begin ();
	return i->returnPosition ();
}

// prints all remaining players in the list
void ListMyJosephus::printAll ()
{
	list<Person>::iterator i;
	list<Person>::iterator j;

	int id = 0;
	cout << "People Left: ";
	for (i = circ.begin (); i != --circ.end(); i++)
	{
		id = i->returnPosition ();
		cout << id;
		cout << ", ";
	}
	id = i->returnPosition ();
	cout << id << ".\n";
}