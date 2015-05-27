#ifndef PLAYER
#define PLAYER

#include "PA3.h"

class Player {
	public:
		Player ();
		Player (int newID);
		Player (int newID, int newX, int newY);
		~Player ();

		bool operator<(const Player& p) const { return p.id < id; }

		void init (int newID, int newX, int newY);

		int id;
		int x;
		int y;
	private:
};

class PlayerAlt {
	public:
		PlayerAlt ();
		PlayerAlt (Player old);
		PlayerAlt (int newX, int newY);
		PlayerAlt (int newID, int newX, int newY);
		~PlayerAlt ();

		bool operator < (const PlayerAlt& p) const;
		bool operator > (const PlayerAlt& p) const;
		bool operator == (const PlayerAlt& p) const;

		void init (int newID, int newX, int newY);

		int id;
		int x;
		int y;

	private:
};

#endif