#include "Mage.h"
#include <iostream>
#include <string>

using namespace std;

Mage::Mage(string name, RACE race) :
	Player(name, race, 150, 150)
{

}

string Mage::attack() const
{
	return "I will crush you with the power of my arcane missiles!";
}
