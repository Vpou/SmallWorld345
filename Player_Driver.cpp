// Small_World.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>

#include "Player.h"

using namespace std;

/*
int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(NULL));
	GameDeck game = GameDeck();
	Player me = Player("Vic");

	game.listRaces();
	me.picks_Race(game.choosableRaces);
	game.addNewEntry();
	cout << endl;

	cout << "Roll dice 3 times" << endl;

	Dice myDice = me.getDice();
	int roll = myDice.rollDices();
	int roll2 = myDice.rollDices();
	int roll3 = myDice.rollDices();

	cout << roll << " " << roll2 << " " << roll3 << endl;
	myDice.getDiceStats();

	cout << endl;

	int myTokens = me.getRace().getRemainingTokens();

	cout << me.getName() << " has " << myTokens << " tokens." << endl;
	
	me.conquers();
	me.scores();

	return 0;
}

*/