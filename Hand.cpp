#include <iostream>
#include "Hand.hpp"
#include "Card.hpp"

  Hand::Hand() {
    fillHand();
  }

  Card* Hand::getCard1() {
    return card1;
  }

  Card* Hand::getCard2() {
    return card2;
  }

  void Hand::fillHand() {
    card1 = new Card("Spades", "Ace", 11);
    card2 = new Card("Diamonds", "King", 10);
  }

  Hand::~Hand() {
    delete card1;
    delete card2;
  }
