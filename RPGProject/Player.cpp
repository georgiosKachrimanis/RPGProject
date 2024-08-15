#include "Player.h"



Player::Player(string name, Race race, int hitPoints, int magicPoints)
{
	this->name = name;
	this->race = race;
	this->hitPoints = hitPoints;
	this->magicPoints = magicPoints;
}

// --------------------------- Getters ----------------------------
string Player::getName() const
{
	return name;
}

Race Player::getRace() const
{
	return race;
}

string Player::whatRace() const
{
	// This is the code from the course
	string result = "";
	if (race == HUMAN)
	{
		result = "Human";
	}
	else if (race == ELF)
	{
		result = "Elf";
	}
	else if (race == DWARF)
	{
		result = "Dwarf";
	}
	else if (race == ORC)
	{
		result = "Orc";
	}
	else 
	{
		result = "Troll";
	}
	
	return result;

	//This is the code from my implimantation 
	/*
	switch (this->race) {
	case HUMAN: return "Human";
	case ELF: return "Elf";
	case DWARF: return "Dwarf";
	case ORC: return "Orc";
	case TROLL: return "Troll";
	default: return "Human";
	}
	*/
}

int Player::getHitPoints() const
{
	return hitPoints;
}

int Player::getMagicPoints() const
{
	return magicPoints;
}

// --------------------------- Setters ----------------------------
void Player::setName(string name)
{
	this->name = name;
}

void Player::setRace(Race race)
{
	this->race = race;
}

void Player::setHitPoints(int hitPoints)
{
	this->hitPoints = hitPoints;
}

void Player::setMagicPoints(int magicPoints)
{
	this->magicPoints = magicPoints;
}
