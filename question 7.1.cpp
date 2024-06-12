Чтобы обработать тузы как 1 или 11, необходимо отслеживать не только сумму карт, но и количество тузов в руке. При подсчете очков:

Если сумма очков меньше или равна 21, туз засчитывается как 11.
Если сумма очков больше 21, туз засчитывается как 1.
Измененный код getCardValue:

int getCardValue(const Card& card) {
    switch (card.rank) {
        case Rank::Jack:
        case Rank::Queen:
        case Rank::King:
            return 10;
        case Rank::Ace:
            return 11; // Пока что туз всегда стоит 11
        default:
            return static_cast<int>(card.rank) + 2; // 2 - 10
    }
}
Измененный цикл обработки тузов:
while (
