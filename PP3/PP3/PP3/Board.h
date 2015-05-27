#ifndef BOARD
#define BOARD

#include "PA3.h"
#include "Player.h"

class Board {
	public:
		Board ();
		Board (int newM);
		~Board ();
		void init (int newM);

		bool Insert (int id, int newX, int newY);
		bool Remove (int id);
		bool Find (int checkID);
		int FindCoor (int checkX, int checkY);
		set<Player>::iterator FindCoorPlayer (int checkX, int checkY);
		set<Player>::iterator FindPlayer (int checkID);
		bool MoveTo (int id, int destX, int destY);
		void PrintByID (void);

	private:
		int m;
		set<Player> n;
};

#endif