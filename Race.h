#include <string>;

class Race {

public:

	Race();
	Race(std::string n, int q, int st); //constructor for deck

	std::string getName();
	int getRemainingTokens();
	int getStartingValue();
	bool getRaceState();

	void addUsableToken(int nb);
	void extinguish();
	void useTokens(int nb);

private:
	std::string name; //name of the race
	int totalTokens; //nb of tokens of the corresponding to the race in the game
	int usableTokens; //nb of tokens that can be used by player during the turn

	int startingTokens; //starting value (number on the banner)
	bool active; //active or extinct
};