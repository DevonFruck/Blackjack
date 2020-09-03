#ifndef HAND_H
#define HAND_H

#include "Card.hpp"

class Hand {

  private:
    Card* card1;
    Card* card2;

  public:

    Hand();
    void fillHand();

    Card* getCard1();
    Card* getCard2();

    ~Hand();
};

#endif
