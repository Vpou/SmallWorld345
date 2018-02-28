#include <string>;
#ifndef Misc_H
#define Misc_H
class Misc {

public:
	Misc();
	Misc(std::string n, int q); //constructor for deck

	std::string getName();
	int getQuantity();
	void addPieceOnBoard();

private:
	std::string name; //name of the piece
	int quantity; //starting quantity
};

#endif