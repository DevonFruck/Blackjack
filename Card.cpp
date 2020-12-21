#include <iostream>
#include "Card.hpp"

  Card::Card(std::string newSuit, std::string newFace, int newValue) {
    suit = newSuit;
    face = newFace;
    value = newValue;
  }

  Card::Card() {}

  void Card::printCard() {
    //return std::string (face) << " of " << std::string (suit);
  }

  int Card::getValue() {
    return value;
  }

  std::string Card::getFace() {
    return face;
  }

  std::string Card::getSuit() {
    return suit;
  }
