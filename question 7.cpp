#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <locale>

enum class Rank {
    Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace
};
enum class Suit {
    Clubs, Diamonds, Hearts, Spades
};

struct Card {
    Rank rank;
    Suit suit;
};

void printCard(const Card& card) {
    char rankChar{};
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
    char suitChar{};
    switch (card.suit) {
    case Suit::Clubs:    suitChar = 'C'; break;
    case Suit::Diamonds: suitChar = 'D'; break;
    case Suit::Hearts:   suitChar = 'H'; break;
    case Suit::Spades:   suitChar = 'S'; break;
    }
    std::cout << rankChar << suitChar << " ";
}

std::vector<Card> createDeck() {
    std::vector<Card> deck;
    for (int suit = 0; suit < 4; ++suit) {
        for (int rank = 0; rank < 13; ++rank) {
            deck.push_back({ static_cast<Rank>(rank), static_cast<Suit>(suit) });
        }
    }
    return deck;
}

void shuffleDeck(std::vector<Card>& deck) {
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
        return static_cast<int>(card.rank) + 2;
    }
}

bool playBlackjack(std::vector<Card>& deck) {
    static std::random_device rd;
    static std::mt19937 g(rd());

    int dealerScore = getCardValue(deck[0]);
    deck.erase(deck.begin());
    int playerScore = getCardValue(deck[0]) + getCardValue(deck[1]);
    deck.erase(deck.begin(), deck.begin() + 2);

    std::cout << "Дилер получил " << dealerScore << " очков.\n";
    std::cout << "Игрок получил " << playerScore << " очков.\n";

    while (true) {
        std::cout << "Игрок, хотите еще карту? (да/нет): ";
        std::string answer;
        std::cin >> answer;

        if (answer == "да") {
            playerScore += getCardValue(deck[0]);
            deck.erase(deck.begin());
            std::cout << "Игрок получил еще одну карту. Новый счет: " << playerScore << std::endl;
            if (playerScore > 21) {
                std::cout << "Игрок проиграл! Перебор!\n";
                return false;
            }
        }
        else if (answer == "нет") {
            break;
        }
        else {
            std::cout << "Неверный ввод. Введите да или нет.\n";
        }
    }

    std::cout << "Дилер тянет карты.\n";
    while (dealerScore < 17) {
        dealerScore += getCardValue(deck[0]);
        deck.erase(deck.begin());
        std::cout << "Дилер получил еще одну карту. Новый счет: " << dealerScore << std::endl;
    }

    std::cout << "Дилер остановился. Счет дилера: " << dealerScore << std::endl;
    std::cout << "Счет игрока: " << playerScore << std::endl;

    if (dealerScore > 21) {
        std::cout << "Дилер проиграл! Перебор!\n";
        return true;
    }
    else if (playerScore > dealerScore) {
        std::cout << "Игрок выиграл!\n";
        return true;
    }
    else {
        std::cout << "Игрок проиграл!\n";
        return false;
    }
}

int main() {
    std::locale::global(std::locale("ru_RU.UTF-8"));

    std::cout << "Добро пожаловать в игру Блэкджек!\n";
    while (true) {
        std::vector<Card> deck = createDeck();
        shuffleDeck(deck);

        if (playBlackjack(deck)) {
            std::cout << "Вы выиграли!\n";
        }
        else {
            std::cout << "Вы проиграли!\n";
        }

        std::cout << "Хотите сыграть еще? (да/нет): ";
        std::string answer;
        std::cin >> answer;

        if (answer != "да") {
            break;
        }
    }

    std::cout << "Спасибо за игру!\n";
    return 0;
}
