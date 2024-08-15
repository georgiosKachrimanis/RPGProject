#include "Warrior.h"
#include <iostream>
#include <string>

using namespace std;

Warrior::Warrior(string name, RACE race ) :
	Player(name, race, 200, 0)
{

}

string Warrior::attack() const
{
	return "I will destroy you with my sword, foul demon!";
}
