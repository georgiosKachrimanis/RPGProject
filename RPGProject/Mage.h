#ifndef MAGE_H
#define MAGE_H
#include "Player.h"


using namespace std;

class Mage : public Player
{
	public:
		Mage(string name, RACE race);
		string attack() const;
};

#endif // !MAGE_H
