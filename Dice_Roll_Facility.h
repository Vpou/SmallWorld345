class Dice {

public:

	Dice();
	int rollDices();
	void getDiceStats();

private:
	static const int rollPossibilities[6]; //possibilities from rolls
	int rollStats[4]; //keep track of the rolls from the dice
	int currentRoll; // current value of last roll
	int totalRolls; // total rolls done by the dice

};

