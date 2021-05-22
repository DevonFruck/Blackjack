#include <iostream>
#include <vector>
#include "Hand.hpp"
#include "Card.hpp"
#include "Deck.hpp"

Hand::Hand(double wager, Card* card1, Card* card2) {
   totalValue = 0;
   stillPlaying = true;
   bet = wager;

   std::vector<Card*> playingHand;
   playingHand.reserve(10);

   fillHand(card1, card2);
}

void Hand::fillHand(Card* card1,Card* card2) {
   playingHand.push_back(card1);
   playingHand.push_back(card2);
   checkHand();
}

void Hand::hit(Card* newCard) {
   playingHand.push_back(newCard);
   checkHand();
   std::cout << "\n" << (softAce ? "SOFT " : "") << totalValue << "\n";
}

void Hand::checkHand() {
   int newVal = 0;
   int numOfAces = 0;
   for (Card* x : playingHand) {
      int cardVal = x->getValue();
      newVal += cardVal;

      if (cardVal == 11) { // Found an Ace in hand
         numOfAces += 1;
      }
   }

   while (numOfAces > 0 && newVal > 21) {
      newVal -= 10;
      numOfAces -= 1;
   }
   if(numOfAces > 0) {
      softAce = true;
   } else {
      softAce = false;
   }

   totalValue = newVal;
}

int Hand::checkFirstCard() {
   return playingHand[0]->getValue();
}

bool Hand::isPlaying() {
   return stillPlaying;
}

void Hand::stand() {
   stillPlaying = false;
}

int Hand::getTotalValue() {
   return totalValue;
}

Hand::~Hand() {
   //delete playingHand;
}
