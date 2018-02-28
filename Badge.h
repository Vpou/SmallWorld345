#include <string>;

class Badge {

public:

	Badge();
	Badge(std::string n, int nb); //constructor for deck

	std::string getName();
	int getNumber();

private:
	std::string name; //name of the badge
	int number; //starting number on the badge

};