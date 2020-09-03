#include <iostream>
#include "Hand.hpp"
#include "Card.hpp"

int main() {
  Hand* dealer = new Hand();

  std::cout << dealer->getCard1()->getFace() << "\n" << dealer->getCard2()->getFace() << "\n";
}
