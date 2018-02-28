#include "stdafx.h"
#include <iostream>
#include <cstdlib>


#include "GameDeck.h"

//create a simple deck
GameDeck::GameDeck() {

	//Create victory coins
	coins[0] = VictoryCoin(1, 15);
	coins[1] = VictoryCoin(3, 15);
	coins[2] = VictoryCoin(5, 15);
	coins[3] = VictoryCoin(10, 30);

	//Create race tokens and banner for map
	races[0] = Race("Amazon", 15, 6);
	races[1] = Race("Dwarves", 8, 3);
	races[2] = Race("Elves", 11, 6);
	races[3] = Race("Ghouls", 10, 5);
	races[4] = Race("Ratmen", 13, 8);
	races[5] = Race("Skeletons", 20, 6);
	races[6] = Race("Sorcerers", 18, 5);
	races[7] = Race("Tritons", 11, 6);
	races[8] = Race("Giants", 11, 6);
	races[9] = Race("Halflings", 11, 6);
	races[10] = Race("Humans", 10, 5);
	races[11] = Race("Orcs", 10, 5);
	races[12] = Race("Trolls", 10, 5);
	races[13] = Race("Wizards", 10, 5);
	races[14] = Race("Lost Tribes", 18, 0);

	//create badges for the races
	badges[0] = Badge("Alchemist", 4);
	badges[1] = Badge("Berserk", 4);
	badges[2] = Badge("Bivouacking", 5);
	badges[3] = Badge("Commando", 4);
	badges[4] = Badge("Diplomat", 5);
	badges[5] = Badge("Dragon Master", 5);
	badges[6] = Badge("Flying", 5);
	badges[7] = Badge("Forest", 4);
	badges[8] = Badge("Fortified", 3);
	badges[9] = Badge("Heroic", 5);
	badges[10] = Badge("Hill", 4);
	badges[11] = Badge("Merchant", 2);
	badges[12] = Badge("Mounted", 5);
	badges[13] = Badge("Pillaging", 5);
	badges[14] = Badge("Seafaring", 5);
	badges[15] = Badge("Spirit", 5);
	badges[16] = Badge("Stout", 4);
	badges[17] = Badge("Swamp", 4);
	badges[18] = Badge("Underworld", 5);
	badges[19] = Badge("Wealthy", 4);

	//Create various extra pieces for the board
	misc[0] = Misc("Fortress", 6);
	misc[1] = Misc("Troll Lair", 10);
	misc[2] = Misc("Mountain", 9);
	misc[3] = Misc("Encampment", 5);
	misc[4] = Misc("Hole-In-The-Ground", 2);
	misc[5] = Misc("Hero", 2);
	misc[6] = Misc("Dragon", 1);
	
	//add the 5 choosable races with a random power
	for (int i = 0; i < 5; i++) {
		Race rdmRace = getRandomRace();
		Badge rdmBadge = getRandomBadge();

		rdmRace.addUsableToken(rdmBadge.getNumber());

		std::pair<Race, Badge> newEntry(rdmRace, rdmBadge);
		choosableRaces.push_back(newEntry);
	}

}

void GameDeck::listRaces() {

	std::cout << "Here are the choosable races and their badges:" << std::endl;
	int index = 1;

	//Show the 5 races to choose from
	std::cout << std::endl;
	for (std::list<std::pair<Race, Badge>>::iterator i = choosableRaces.begin(); i != choosableRaces.end(); ++i) {
		std::cout << index << ".   " << (*i).second.getName() << " " << (*i).first.getName() << std::endl;
		index++;
	}
}

//get a random race
Race GameDeck::getRandomRace() {
	bool contains(std::list<int> someList, int nb);

	//get a random number to choose a random race
	int randomNb;	
	do {
		randomNb = rand() % 14;
	} while (contains(usedRaces, randomNb));
	
	//make sure it hasn't already been chosen
	usedRaces.push_back(randomNb);
	return races[randomNb];
}

//get a random badge
Badge GameDeck::getRandomBadge() {
	bool contains(std::list<int> someList, int nb);

	//get a random number to choose a random badge
	int randomNb;
	do {
		randomNb = rand() % 20;
	} while (contains(usedBadges, randomNb));

	//make sure it hasn't been chosen
	usedBadges.push_back(randomNb);
	return badges[randomNb];
}

//get a specific race
Race GameDeck::getRace(int index) {
	return races[index];
}

//get the bank of victory coins
VictoryCoin GameDeck::getVictoryCoin(int index) {
	return coins[index];
}

//get a certain piece for the board
Misc GameDeck::getMiscPiece(int index) {
	return misc[index];
}

//get a certain badge for the board
Badge GameDeck::getBadge(int index) {
	return badges[index];
}

//add a race and badge when a player picks a race
void GameDeck::addNewEntry() {
	Race rdmRace = getRandomRace();
	Badge rdmBadge = getRandomBadge();

	rdmRace.addUsableToken(rdmBadge.getNumber());

	std::pair<Race, Badge> newEntry (rdmRace, rdmBadge);
	choosableRaces.push_back(newEntry);

	std::cout << "New race and badge added: " << newEntry.second.getName() << " " << newEntry.first.getName() << std::endl;
}


//check if number is in the list
bool contains(std::list<int> listOfNb, int nb) {

	if (!listOfNb.empty())
		for (std::list<int>::const_iterator i = listOfNb.begin(); i != listOfNb.end(); ++i)
			if (nb == *i) 
				return true;
		
	return false;
}
