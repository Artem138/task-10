#include <iostream>
#include <array>
#include <random>
#include <algorithm>

enum class Rank { Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace };
enum class Suit { Clubs, Diamonds, Hearts, Spades };

struct Card {
    Rank rank;
    Suit suit;
};

void printCard(const Card& card) {
    char rankChar;
    switch (card.rank) {
        case Rank::Two:   rankChar = '2'; break;
        case Rank::Three:  rankChar = '3'; break;
        case Rank::Four:   rankChar = '4'; break;
        case Rank::Five:   rankChar = '5'; break;
        case Rank::Six:    rankChar = '6'; break;
        case Rank::Seven:  rankChar = '7'; break;
        case Rank::Eight:  rankChar = '8'; break;
        case Rank::Nine:   rankChar = '9'; break;
        case Rank::Ten:   rankChar = 'T'; break;
        case Rank::Jack:   rankChar = 'J'; break;
        case Rank::Queen:  rankChar = 'Q'; break;
        case Rank::King:   rankChar = 'K'; break;
        case Rank::Ace:    rankChar = 'A'; break;
    }
    char suitChar;
    switch (card.suit) {
        case Suit::Clubs:    suitChar = 'C'; break;
        case Suit::Diamonds: suitChar = 'D'; break;
        case Suit::Hearts:   suitChar = 'H'; break;
        case Suit::Spades:   suitChar = 'S'; break;
    }
    std::cout << rankChar << suitChar << " ";
}

std::array<Card, 52> createDeck() {
    std::array<Card, 52> deck;
    int index = 0;
    for (int suit = 0; suit < 4; ++suit) {
        for (int rank = 0; rank < 13; ++rank) {
            deck[index].suit = static_cast<Suit>(suit);
            deck[index].rank = static_cast<Rank>(rank);
            ++index;
        }
    }
    return deck;
}

void printDeck(const std::array<Card, 52>& deck) {
    for (const auto& card : deck) {
        printCard(card);
    }
    std::cout << std::endl;
}

void shuffleDeck(std::array<Card, 52>& deck) {
    static std::random_device rd;
    static std::mt19937 g(rd());
    std::shuffle(deck.begin(), deck.end(), g);
}

int getCardValue(const Card& card) {
    switch (card.rank) {
        case Rank::Jack:
        case Rank::Queen:
        case Rank::King:
            return 10;
        case Rank::Ace:
            return 11;
        default:
            return static_cast<int>(card.rank) + 2; // 2 - 10
    }
}

int main() {
    std::array<Card, 52> deck = createDeck();
    printDeck(deck);

    shuffleDeck(deck);
    std::cout << "Shuffled deck: " << std::endl;
    printDeck(deck);

    return 0;
}
