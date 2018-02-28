#include "stdafx.h"
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include "Dice_Roll_Facility.h"

using namespace std;

const int Dice::rollPossibilities[6] = { 0, 0, 0, 1, 2, 3 };


Dice::Dice() 
{
	fill(rollStats, rollStats + 4, 0);	
	totalRolls = 0;

}

int Dice::rollDices() {	

	//get random number and use that as the index for the possibilities of the roll
	int nbCalculator = rand() % 6;
	currentRoll = rollPossibilities[nbCalculator];

	//increment total rolls by one
	totalRolls++;

	//keep track of the rolls
	switch (currentRoll) {
	case 0:
		rollStats[0]++;
		break;
	case 1:
		rollStats[1]++;
		break;
	case 2:
		rollStats[2]++;
		break;
	case 3:
		rollStats[3]++;
		break;

	default:
		cout << "Error";
		break;

	}

	return currentRoll;
}

//get stats of the dice (% of times x number was rolled)
void Dice::getDiceStats() {
	if (totalRolls != 0) {
		for (int i = 0; i < 4; i++) {
			double stat = rollStats[i] * 100.0 / totalRolls;
			cout << i << " has appeared " << stat << " %" << endl;
		}
	}

	else
		cout << "Please roll some dices...";
}