#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <fstream>

#include "Player.h"

Player::Player() {
	name = "";
	dice = Dice();
	budget[0] = VictoryCoin(1, 0);
	budget[1] = VictoryCoin(3, 0);
	budget[2] = VictoryCoin(5, 0);
	budget[3] = VictoryCoin(10, 0);

}

//create a player
Player::Player(std::string n) {
	name = n;
	dice = Dice();
	budget[0] = VictoryCoin(1, 0);
	budget[1] = VictoryCoin(3, 0);
	budget[2] = VictoryCoin(5, 0);
	budget[3] = VictoryCoin(10, 0);
}

//get player's name
std::string Player::getName() {
	return name;
}

//get player's race
Race Player::getRace() {
	return race;
}

//get player's badge
Badge Player::getBadge() {
	return badge;
}

//get total of victory coins
int Player::getVictoryCoins() {
	int total = 0;
	for (int i = 0; i < 4; i++)
		total += (budget[i].getQuantity() * budget[i].getValue());

	return total;
}

Dice Player::getDice() {
	return dice;
}

//choose his race
void Player::picks_Race(std::list<std::pair<Race, Badge>>& choosableRaces) {
	std::cout << "Please type the number of the race you would like to choose" << std::endl;

	int index;
	std::cin >> index;

	int iterator = 1;

	//when player chooses race, erase from list
	for (std::list<std::pair<Race, Badge>>::iterator i = choosableRaces.begin(); i != choosableRaces.end(); ++i) {
		if (index == iterator)
		{
			race = (*i).first;
			badge = (*i).second;
			choosableRaces.erase(i);
			break;
		}
		iterator++;
	}

	std::cout << "You have chosen the " << badge.getName() << " " << race.getName() << std::endl;

}

//conquers a region
void Player::conquers( Region target ) {

	race.useTokens( target.getNbTokens() + 1 );
	target.changeOwner(name); 

	ownedRegions.push_back(target);

	std::cout << "Congratulations you conquered the region, you have " << race.getRemainingTokens() << " tokens left." << std::endl;

}

//add victory coins
void Player::scores() {

	int regionTotal = 5;//ownedRegions.size;
	
	std::cout << "You have scored " << regionTotal << " points!" << std::endl;

	// add tokens to "bank"
	if (regionTotal >= 10) {
		int token10 = regionTotal / 10;
		regionTotal -= (token10 * 10);
		budget[3].getCoin(token10);
	}

	if (regionTotal >= 5) {
		int token5 = regionTotal / 5;
		regionTotal -= (token5 * 5);
		budget[2].getCoin(token5);
	}

	if (regionTotal >= 3) {
		int token3 = regionTotal / 3;
		regionTotal -= (token3 * 3);
		budget[1].getCoin(token3);
	}

	if (regionTotal >= 1) {
		int token1 = regionTotal / 1;
		regionTotal -= (token1 * 1);
		budget[0].getCoin(token1);
	}

}

//open summary sheet --> will be changed later
void Player::openSummarySheet() {

	std::string line;
	std::ifstream summary;
	summary.open("SummarySheet.txt");
	if (summary.is_open())
	{
		while (getline(summary, line)) {
			std::cout << line << std::endl;
		}
		summary.close();
	}

	else std::cout << "Unable to open file";

}