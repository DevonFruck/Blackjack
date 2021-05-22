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

    std::cout << "\nThe dealer's flipped card is " << dealer->checkFirstCard() <<
    "\n\nIt's your turn\n";
    std::cout << "your starting hand is a " << player->getTotalValue() << "\n";

    int hit_or_stand;
    while (player->isPlaying() == 1) {
        std::cout << "1 for hit, 2 for stand: ";
        std::cin >> hit_or_stand;

        std::cout << player->getTotalValue() << "\n";

        if (player->getTotalValue() > 21) {
            std::cout << "\nBust. You lose\n\n";
            exit(1);
        }

        if (hit_or_stand == 1) {
            std::cout<<"\nYou've chosen to hit.\n";
            player->hit(deck->topCard());
            //std::cout << player->getTotalValue();
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

    std::cout << "\n\nNow it's the dealer's turn.\n\n";
    // Dealer's turn
    std::cout << dealer->getTotalValue() << "\n";

    while (dealer->isPlaying() && dealer->getTotalValue() <= 21) {
        if (dealer->getTotalValue() < 17) {
            dealer->hit(deck->topCard());
            //std::cout << player->getTotalValue() << "\n";
        }
        else {
            dealer->stand();
        }
    }
    int playerScore = player->getTotalValue();
    int dealerScore = dealer->getTotalValue();
    if (playerScore > dealerScore && playerScore <= 21) {
        std::cout << "\nYou Win!\n\n";
    }
    else if (playerScore == dealerScore && playerScore <= 21) {
        std::cout << "\nIt's a push.\n\n";
    }
    else {
        std::cout << "\nYou Lose.\n\n";
    }
}
