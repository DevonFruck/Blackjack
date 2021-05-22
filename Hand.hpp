#ifndef HAND_H
#define HAND_H

#include "Card.hpp"
#include <vector>

class Hand {

   private:
      double bet;
      bool stillPlaying, softAce;
      int totalValue;
      std::vector<Card*> playingHand;

      void checkHand();
      void fillHand(Card* card1, Card* card2);

   public:
      Hand(double wager, Card* firCard, Card* secCard);
      void hit(Card* newCard);
      void stand();
      bool isPlaying();
      int getTotalValue();
      int checkFirstCard();

      ~Hand();
};
#endif
