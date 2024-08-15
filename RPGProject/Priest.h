#ifndef PRIEST_H
#define PRIEST_H
#include "Player.h"

class Priest : public Player
{
public:
	Priest(string name, RACE race);
	string attack() const;
};

#endif // !PRIEST_H
