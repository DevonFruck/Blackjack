#include "Deck.hpp"
#include <vector>
#include <string>

Deck::Deck() {

	int count=0;  //Keep track of number of cards put in
  	int value = 2;

  	// Putting number value cards in the deck
  	for (int i=0; i<9; i++) {
    	for (int j=0; j<4; j++) {
      deck[count] = new Card(suits[j], faces[i], value);
      count++;
   	}
   	value ++;
  	}
  	// Putting face cards in the deck
  	for (int l=9; l<=11; l++) {
    	for (int m=0; m<4; m++) {
      deck[count] = new Card(suits[m], faces[l], 10);
      count ++;
   	}
  	}
  	// Putting Aces in the deck
  	for (int k=0; k<4; k++) {
    	deck[count] = new Card(suits[k], "Ace", 11);
    	count ++;
  	}

  	shuffle();
}

void Deck::shuffle() {

	srand((unsigned int)time(NULL));
  	int maxIter = 1000 + rand()%500;  //random number of shuffles

  	for (int iter=0; iter < maxIter; iter++) {
    	// rand1 and rand2 are positions in the deck that will
    	// swap places to simulate shuffling of the deck
    	int rand1 = rand() % 52;
    	int rand2 = rand() % 52;

    	Card* ptr = deck[rand1];
    	deck[rand1] = deck[rand2];
    	deck[rand2] = ptr;

    	top = &deck[0];
  	}
}

Card* Deck::topCard() {
  	Card* ptr = *top;
  	top += 1;
  	return ptr;
}
