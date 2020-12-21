#include <iostream>
#include "Hand.hpp"
#include "Card.hpp"
#include "Deck.hpp"

int main() {
  Hand* player = new Hand(50);

  player->stand();
  player->stillPlaying = 5;
  std::cout << isPlaying();
}
