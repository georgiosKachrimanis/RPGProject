#include <iostream>
#include <vector>
#include <string>
#include "Player.h"
#include "Priest.h"
#include "Mage.h"
#include "Warrior.h"

using namespace std;

enum Profession{WARRIOR, PRIEST, MAGE};

void printAllInfo(vector<Player*>& playerVector);
Player* createPlayer(string playerName, Race playerRace, Profession playerProfession);
void deallocatePlayers(vector<Player*>& playerVector);
Race getRace();
Profession getProfession();
string getName();

int main()
{
	string addAnother = "y";
	vector<Player*> charactersVector;
	
	while (addAnother == "y")
	{
		cout << "Do you want to create a new player? " << endl
			<< "Yes(y) or No(n)" << endl;
		cin >> addAnother;

		if (addAnother == "y")
		{
			Race playerRace = getRace();
			Profession playerProfession = getProfession();
			string playerName = getName();
			Player * newPlayer = createPlayer(playerName, playerRace, playerProfession);
			charactersVector.push_back(newPlayer);
		}
		else
		{
			addAnother = "n";
		}
	}

	printAllInfo(charactersVector);
	deallocatePlayers(charactersVector);
	return 0;
}

void printAllInfo(vector<Player*>& playerVector)
{
	if (!playerVector.empty())
	{
		for (Player* playerPtr : playerVector)
		{
			cout << "I am a " << playerPtr->whatRace() << " and my attack is: " << endl << "\t"
				<< playerPtr->attack() << endl;
		}
	}
	else
	{
		cout << "No players were created! " << endl
			<< "Goodbye!" << endl;
	}

}

Player* createPlayer(string playerName, Race playerRace, Profession playerProfession)
{

	switch (playerProfession)
	{
	case 0:
		return new Warrior(playerName, playerRace);
	case 1:
		return new Priest(playerName, playerRace);
	case 2:
		return new Mage(playerName, playerRace);
	default:
		cout << "Invalid Profession selected!";
	}

}

void deallocatePlayers(vector<Player*>& playerVector)
{
	for (Player* playerPtr : playerVector)
	{
		delete playerPtr;
	}
	playerVector.clear();
}

Race getRace()
{
	Race tempRace;
	int userInput = 0;

	while (userInput < 1 || userInput > 5)
	{
		cout << "Please choose a Race for your character: " << endl
			<< "Available Races: " << endl
			<< "1. Human" << endl
			<< "2. Elf" << endl
			<< "3. Dwarf" << endl
			<< "4. Orc" << endl
			<< "5. Troll" << endl;
		cin >> userInput;
		cin.get(); // consume newline
	}



	switch (userInput) {
	case 1: return HUMAN;
	case 2: return ELF;
	case 3: return DWARF;
	case 4: return ORC;
	case 5: return TROLL;
	default: 
		cout << "There was an issue, your character was assigned the default Race of Humman" << endl;
		return HUMAN;
	}
		
}	

Profession getProfession()
{
	Profession tempProf;
	int userInput = 0;

	while (userInput < 1 || userInput > 3)
	{
		cout << "Please choose the Profession of your character: " << endl
			<< "Available Professions: " << endl
			<< "1. Warrior: A strong melee fighter. Me, smash!" << endl
			<< "2. Priest: A support character. Good in keeping other players alive!" << endl
			<< "3. Mage: A long rage magic user. Good at burning things from affar!" << endl;
		cin >> userInput;
	}

	switch (userInput) {
	case 1: return WARRIOR;
	case 2: return PRIEST;
	case 3: return MAGE;
	default:
		cout << "There was an issue, your character was assigned the default Profession of Warrior" << endl;
		return WARRIOR;
	}
}

string getName()
{
	string playerName;
	cout << "What is your characters name? " << endl;
	cin >> playerName;

	return playerName;

}