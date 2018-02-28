#include "stdafx.h"
#include <iostream>

#include "Region.h"

int Region::nbOfRegions = 0;

Region::Region() {
	nbTokens = 0;
	owner = "";
	piece = Misc();
	index = nbOfRegions;
	nbOfRegions++;

	std::cout << "Node created!" << std::endl;
}

Region::Region(int tokens, Misc misc) {
	owner = "";
	nbTokens = tokens;
	piece = misc;
	index = nbOfRegions;
	nbOfRegions++;
}

int Region::getIndex() {
	return index;
}

int Region::getNbTokens() {
	return nbTokens;
}

std::string Region::getOwner() {
	return owner;
}

void Region::setMisc(Misc misc) {
	piece = misc;
}

void Region::setTokens(int nb) {
	nbTokens = nb;
}

void Region::changeOwner(std::string newOwner) {
	owner = newOwner;
}