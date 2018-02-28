#include <list>

#include "VictoryCoins.h"
#include "Race.h"
#include "Badge.h"
#include "MiscPieces.h"


class GameDeck
{

public:
	GameDeck();
	void listRaces();

	Race getRandomRace();
	Badge getRandomBadge();
	void addNewEntry();

	Race getRace(int index);
	VictoryCoin getVictoryCoin(int index);
	Misc getMiscPiece(int index);
	Badge getBadge(int index);
	
	std::list<std::pair<Race, Badge>> choosableRaces;


private:
	VictoryCoin coins[4]; //array containing the coins
	Race races[15]; //array containing the races
	Badge badges[20]; //array containing the badges
	Misc misc[7]; //array containing the other board pieces
	
	std::list<int> usedRaces; //list containing the races already used
	std::list<int> usedBadges; //list containing the badges already used

};

