#ifndef PLAYER_H
#define PLAYER_H
#include <string>
using namespace std;

enum RACE{HUMAN, ELF, DWARF, ORC, TROLL};

class Player
{
	private:
		string name;
		RACE race;
		int hitPoints;
		int magicPoints;
	public:
		Player(string name, RACE race, int hitPoints, int magicPoints);
		string getName() const;
		RACE getRace() const;
		string whatRace() const;
		int getHitPoints() const;
		int getMagicPoints() const;
		void setName(string name);
		void setRace(RACE race);
		void setHitPoints(int hitPoints);
		void setMagicPoints(int magicPoints);
		virtual string attack() const = 0;
};
#endif // !PLAYER_H

