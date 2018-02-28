#include "stdafx.h"
#include <string>;

#include "Race.h"

//default constructor
Race::Race() {
	name = "";
	totalTokens = 0;
	active = true;
}

//constructor instantiating the name, the total tokens and the starting number
Race::Race(std::string n, int q, int st) {
	name = n;
	totalTokens = q;
	startingTokens = st;
	usableTokens = st;
}

//when a race goes extinct
void Race::extinguish() {
	active = false;
}

//get the state of the race
bool Race::getRaceState() {
	return active;
}

//when a user uses tokens of the race, lower the remaining token
void Race::useTokens(int nb){
	usableTokens -= nb;
}

//add tokens to the ones you may use
void Race::addUsableToken(int nb) {
	usableTokens += nb;
}

//get name
std::string Race::getName() {
	return name;
}

//get remaining token
int Race::getRemainingTokens() {
	return usableTokens;
}

//value on banner
int Race::getStartingValue() {
	return startingTokens;
}

