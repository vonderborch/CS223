#include "Board.h"

Board::Board ()
{
	init (0);
}

Board::Board (int newM)
{
	init (newM);
}

Board::~Board ()
{
}

// initializes the board (and prints that out)
void Board::init (int newM)
{
	this->m = newM;
	string outputFile = "output.txt";
	ofstream output;
	output.open (outputFile.c_str (), ios::app);
	cout << "Setting up new Board" << endl;
	output << "Setting up new Board" << endl;
	output.close ();
}

// inserts a new player onto the map and returns true/false on success.
bool Board::Insert (int id, int newX, int newY)
{
	string outputFile = "output.txt";
	ofstream output;
	output.open (outputFile.c_str (), ios::app);

	bool isGood = false;

	isGood = Find (id);

	if (isGood == true)
	{
		if (n.size() < m)
		{
			int idExists;
			idExists = FindCoor (newX, newY);

			if (idExists == -1)
			{
				n.insert (Player (id, newX, newY));
			}
			else
			{
				cout << "Insert Error: Player at coordinates already exists!" << endl;
				output << "Insert Error: Player at coordinates already exists!" << endl;
				isGood = false;
			}
		}
		else
		{
			cout << "Insert Error: Too many Players already inserted!" << endl;
			output << "Insert Error: Too many Players already inserted!" << endl;
			isGood = false;
		}
	}
	else
	{
		cout << "Insert Error: Player already exists!" << endl;
		output << "Insert Error: Player already exists!" << endl;
	}

	output.close();
	return isGood;
}

// removes a player from the board and returns true/false on success
bool Board::Remove (int id)
{
	bool isGood = true;

	set<Player>::iterator i;
	set<Player>::iterator end;

	i = this->n.find (id);
	end = this->n.end ();

	if (i != end)
	{
		n.erase (i);
		isGood = true;
	}

	return isGood;
}

// finds a player based on id and returns true/false based on whether player exists.
bool Board::Find (int checkID)
{
	bool dne = true;

	set<Player>::iterator i;
	set<Player>::iterator end;

	i = this->n.find (checkID);
	end = this->n.end ();

	if (i != end)
	{
		dne = false;
	}

	return dne;
}

// finds a player based on x and y coords and returns the id number of the player found (or -1 if none found)
int Board::FindCoor (int checkX, int checkY)
{
	int exists = -1;

	set<Player>::iterator i;
	set<PlayerAlt> temp;
	set<PlayerAlt>::iterator end;
	pair<set<PlayerAlt>::iterator,set<PlayerAlt>::iterator> r;

	for (i = n.begin () ; i != n.end (); i++)
	{
		temp.insert (Player (i->id, i->x, i->y));
	}

	r = temp.equal_range (PlayerAlt (checkX, checkY));
	end = temp.end ();

	if (r.first->id != end->id)
	{
		if (r.first->x == checkX && r.first->y == checkY)
		{
			exists = r.first->id;
		}
	}

	return exists;
}

// finds a player based on x and y coords and returns an iterator to that player
set<Player>::iterator Board::FindCoorPlayer (int checkX, int checkY)
{
	set<Player>::iterator i;
	int exists = -1;

	for (i = n.begin (); i != n.end (); i++)
	{
		if (i->id != n.end ()->id)
		{
			if (i->x == checkX && i->y == checkY)
			{
				exists = i->id;
			}
		}
	}

	if (exists != -1)
	{
		return FindPlayer (exists);
	}
	else
	{
		return n.end ();
	}
}

// finds a player based on id number and returns an iterator to that player
set<Player>::iterator Board::FindPlayer (int checkID)
{
	set<Player>::iterator i;

	i = this->n.find (checkID);

	return i;
}

// moves a player (given id and valid destination coords) to a new spot on the map (and removes any player already there)
bool Board::MoveTo (int id, int destX, int destY)
{
	string outputFile = "output.txt";
	ofstream output;
	output.open (outputFile.c_str (), ios::app);

	bool isGood = false;

	if (destX > this->m || destY > this->m)
	{
		cout << "Move Error: Destination is Out of Bounds!" << endl;
		output << "Move Error: Destination is Out of Bounds!" << endl;
	}
	else
	{
		set<Player>::iterator i = FindPlayer (id);
		if (i != n.end ())
		{
			int xDiff = (int)fabs ((double)i->x - (double)destX);
			int yDiff = (int)fabs ((double)i->y - (double)destY);

			// if the difference along x and y are not 0, and the changes in x and y are not the same, then this is a bad move
			if (xDiff != 0 && yDiff != 0 && xDiff != yDiff)
			{
				cout << "Move Error: Invalid Move!" << endl;
			}
			// otherwise it must be good
			else
			{
				cout << "Moving Player " << id << endl;
				output << "Moving Player " << id << endl;
				// first we'll check if a player exists at the new coords (and if one does, we'll remove it)
 				set<Player>::iterator j = FindCoorPlayer (destX, destY);

				// if j is a real player, then we must remove the player
				if (j != n.end ())
				{
					cout << "Player " << j->id << " Removed!" << endl;
					output << "Player " << j->id << " Removed!" << endl;
					Remove (j->id);
				}

				// then we'll move the player to the new coordinates! (by deleting and recreating it)
				Remove (id);
				Insert (id, destX, destY);
				isGood = true;
			}
		}
		else
		{
			cout << "Move Error: Player does not exist!" << endl;
			output << "Move Error: Player does not exist!" << endl;
		}
	}

	output.close();
	return isGood;
}

// prints the players on the board in decending ID# order
void Board::PrintByID (void)
{
	string outputFile = "output.txt";
	ofstream output;
	output.open (outputFile.c_str (), ios::app);

	set<Player>::iterator i;

	for (i = n.begin () ; i != n.end (); i++)
	{
		cout << "ID: " << i->id << " (" << i->x << ", " << i->y << ")" << endl;
		output << "ID: " << i->id << " (" << i->x << ", " << i->y << ")" << endl;
	}
	output.close();
}