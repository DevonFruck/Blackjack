#include <iostream>
#include "Hand.hpp"
#include "Card.hpp"
#include "Deck.hpp"
#include <vector>

int main() {

  std::cout << "Welcome to the BlackJack table. \n";

  int wager;
  std::cout << "Enter how much you would like to wager: ";
  std::cin >> wager;

  Deck* deck = new Deck();

  Hand* dealer = new Hand(0, deck->topCard(), deck->topCard());
  Hand* player = new Hand(wager, deck->topCard(), deck->topCard());

  int hit_or_stand;
  while (player->isPlaying() == 1 && player->getTotalValue() <= 21) {
    std::cout << "1 for hit, 2 for stand: ";
    std::cin >> hit_or_stand;

    std::cout << player->getTotalValue() << "\n";

    if (hit_or_stand == 1) {
      std::cout<<"\nYou've chosen to hit.\n";
      player->hit(deck->topCard());
    }
    else if (hit_or_stand == 2) {
      std::cout<<"\nYou've chosen to stand.\n";
      player->stand();
      break;
    }
    else {
      std::cout << "Invalid choice. Try again\n";
    }
  }
  std::cout << player->getTotalValue() << "\n";

std::cout << "\n\nNow it's the dealer's turn.\n\n";
  // Dealer's turn

  while (dealer->isPlaying() && dealer->getTotalValue() <= 21) {
    if (dealer->getTotalValue() < 17) {
      dealer->hit(deck->topCard());
    }
    else {
      dealer->stand();
    }
  }

}
