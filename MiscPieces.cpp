#include "stdafx.h"

#include "MiscPieces.h"

//default contsrtuctor
Misc::Misc() {
	name = "";
	quantity = 0;
}

//constructor instantitating the name and the number on the badge
Misc::Misc(std::string n, int nb) {
	name = n;
	quantity = nb;
}

//get name
std::string Misc::getName() {
	return name;
}

//get quantity
int Misc::getQuantity() {
	return quantity;
}

//when adding a piece, remove one from tray
void Misc::addPieceOnBoard() {
	quantity--;
}