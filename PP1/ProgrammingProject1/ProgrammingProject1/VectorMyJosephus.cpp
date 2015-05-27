#include "pa1.h"

//destructor
VectorMyJosephus::~VectorMyJosephus()
{
}
//constructor
VectorMyJosephus::VectorMyJosephus()
{
	init (5, 2);
}

//constructor
VectorMyJosephus::VectorMyJosephus(int N,int M)
{
	init (N, M);
}

// initializes the player circle
void VectorMyJosephus::init(int N,int M)
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
void VectorMyJosephus::clear()
{
	this->circ.clear ();
}

// returns the current size of the circle
int VectorMyJosephus::currentSize()
{
	return this->circ.size ();
}

// checks if the circle is empty
bool VectorMyJosephus::isEmpty()
{
	return this->circ.empty ();
}

// eliminates the next player in the list to be eliminated
int VectorMyJosephus::eliminateNext (int i)
{
	int j = 0, id = 0, k = 0;
	for (j = 0; j < this->M; j++)
	{
		if (i >= size - 1)
			i = 0;
		else
			i++;
	}

	this->size--;
	if (i == -1)
		i = 0;
	k = i;
	if (k >= size)
		k = 0;

	circ.erase (circ.begin () + i);

	return k;
}

// returns the id of the winner
int VectorMyJosephus::returnWinner(void)
{
	return circ.at(0).returnPosition();
}

// prints all remaining players in the list
void VectorMyJosephus::printAll()
{
	vector<Person>::iterator i;
	vector<Person>::iterator j;

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