#include <vector>
#include <string>

#include "Card.hpp"

class Deck {

  private:
    std::vector<Card> deck[52];

    std::vector<std::string> suits = {"Spades", "Clubs",
                                      "Diamonds", "Hearts"};

    std::vector<std::string> faces = {"Two", "Three",
      "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten"};

  public:
    Deck();
};
