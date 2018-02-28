#include "stdafx.h"
#include <string>;

#include "Badge.h"

//default contsrtuctor
Badge::Badge() {
	name = "";
	number = 0;
}

//constructor instantitating the name and the number on the badge
Badge::Badge(std::string n, int nb) {
	name = n;
	number = nb;
}

//get name
std::string Badge::getName() {
	return name;
}

//get number
int Badge::getNumber() {
	return number;
}

