
#include "Dice_Roll_Facility.h"
#include "GameDeck.h"
#include "Region.h"

class Player {

public:

	Player();
	Player(std::string n);
	std::string getName();
	int getVictoryCoins();
	Race getRace();
	Badge getBadge();
	Dice getDice();

	void picks_Race(std::list<std::pair<Race, Badge>>& choosableRaces); //picks a new race
	void conquers(Region target); // conquers a region
	void scores(); //calculate the number of victory coins you get

	void openSummarySheet(); // opens a txt file and reads from it --> will be changed later

private:
	std::string name; //name of player
	Dice dice; // dice rolling facility
	Race race; // player's race
	Badge badge; // player's badge
	VictoryCoin budget[4]; // victory coins of player
	std::list<Region> ownedRegions;
};
