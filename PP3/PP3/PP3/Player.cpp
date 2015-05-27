#include "Player.h"

Player::Player ()
{
	init (-1, -1, -1);
}

Player::Player (int newID)
{
	init (newID, -1, -1);
}

Player::Player (int newID, int newX, int newY)
{
	init (newID, newX, newY);
}

Player::~Player ()
{
}

// initializes the player with the id, x, and y
void Player::init (int newID, int newX, int newY)
{
	this->id = newID;
	this->x = newX;
	this->y = newY;
}

PlayerAlt::PlayerAlt ()
{
	init (-1, -1, -1);
}

PlayerAlt::PlayerAlt (Player old)
{
	init (old.id, old.x, old.y);
}

PlayerAlt::PlayerAlt (int newX, int newY)
{
	init (-1, newX, newY);
}

PlayerAlt::PlayerAlt (int newID, int newX, int newY)
{
	init (newID, newX, newY);
}

PlayerAlt::~PlayerAlt ()
{
}

// initializes the player with the id, x, and y
void PlayerAlt::init (int newID, int newX, int newY)
{
	this->id = newID;
	this->x = newX;
	this->y = newY;
}

// < operator for playeralt class
bool PlayerAlt::operator < (const PlayerAlt& p) const
{
	bool isLessThan = false;

	if (p.x < x && p.y < y)
		isLessThan = true;

	return isLessThan;
}

// > operator for playeralt class
bool PlayerAlt::operator > (const PlayerAlt& p) const
{
	bool isLessThan = false;

	if (p.x > x && p.y > y)
		isLessThan = true;

	return isLessThan;
}

// == operator for playeralt class
bool PlayerAlt::operator == (const PlayerAlt& p) const
{
	bool isLessThan = false;

	if (p.x == x && p.y == y)
		isLessThan = true;

	return isLessThan;
}