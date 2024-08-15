#include "Priest.h"
#include <iostream>
#include <string>

using namespace std;

Priest::Priest(string name, RACE race) : 
	Player(name,race, 100,200)
{

}

string Priest::attack() const
{
	return "I will assault you with Holy Wrath!";
}

