#include <iostream>
#include <array>

enum class ItemType { HealthPotion, Torch, Arrow };

int countTotalItems(const std::array<int, static_cast<int>(ItemType::Arrow) + 1>& inventory) {
    int total = 0;
    for (int count : inventory) {
        total += count;
    }
    return total;
}

int main() {
    // Массив для хранения количества каждого элемента
    std::array<int, static_cast<int>(ItemType::Arrow) + 1> inventory = { 2, 5, 10 };

    // Вывод общего количества элементов
    std::cout << "Total items: " << countTotalItems(inventory) << std::endl;

    // Вывод количества факелов
    std::cout << "Torches: " << inventory[static_cast<int>(ItemType::Torch)] << std::endl;

    return 0;
}
