#include <iostream>
#include <vector>
#include "Player.h"
#include "Priest.h"
#include "Mage.h"
#include "Warrior.h"

using namespace std;

enum PROFESSION{WARRIOR, PRIEST, MAGE};

void printPlayerInfo(vector<Player*>& playerVector);
void createNewPlayer(vector<Player*>& playerVector);
void deallocatePlayers(vector<Player*>& playerVector);
RACE chooseRace();
PROFESSION chooseProfession();

int main()
{
	bool addMorePlayers = true;
	char tempAnswer;
	vector<Player*> players;
	
	while (addMorePlayers)
	{
		cout << "Do you want to create a new player? " << endl
			<< "Yes(y) or No(n)" << endl;
		cin >> tempAnswer;
		if (tempAnswer == 'y')
		{
			createNewPlayer(players);
		}
		else
		{
			addMorePlayers = false;
		}
	}

	printPlayerInfo(players);
	deallocatePlayers(players);
	return 0;
}

void printPlayerInfo(vector<Player*>& playerVector)
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

void createNewPlayer(vector<Player*>& playerVector)
{
	string tempName;
	RACE tempRace;
	PROFESSION tempProf;
	
	tempRace = chooseRace();
	tempProf = chooseProfession();

	cout << "What is your characters name? " << endl;
	cin >> tempName;

	cout << "The race is: " << tempRace << endl;
	
	if (!tempName.empty() && tempProf>=0 && tempRace>=0) {
		switch (tempProf)
		{
			case 0: 
				playerVector.push_back(new Warrior(tempName, tempRace));
				break;
			case 1: 
				playerVector.push_back(new Priest(tempName, tempRace));
				break;
			case 2: 
				playerVector.push_back(new Mage(tempName, tempRace));
				break;
			default:
				cout << "Invalid Profession selected!";
				break;
		}	
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

RACE chooseRace()
{
	RACE tempRace;
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

PROFESSION chooseProfession()
{
	PROFESSION tempProf;
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