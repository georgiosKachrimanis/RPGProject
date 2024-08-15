#ifndef WARRIOR_H
#define WARRIOR_H
#include "Player.h"

class Warrior : public Player
{

public:
	Warrior(string name, RACE race);
	string attack() const;
};

#endif // !WARRIOR_H