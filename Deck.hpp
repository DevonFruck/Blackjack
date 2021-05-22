#include <vector>
#include <string>

#include "Card.hpp"

class Deck {

	private:
   	Card* deck[52];
    	Card** top;

	std::vector<std::string> suits = {
		"Spades", "Clubs",
		"Diamonds", "Hearts"};

	std::vector<std::string> faces = {
		"Two", "Three", "Four", "Five",
		"Six", "Seven", "Eight", "Nine", "Ten",
		"Jack", "Queen", "King", "Ace"};

	public:
		Deck();
		Card* topCard();
		void shuffle();
};
