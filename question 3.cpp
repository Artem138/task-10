#include <iostream>

// Функция для обмена значениями двух целочисленных переменных
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 5;
    int y = 10;

    std::cout << "Before swap: x = " << x << ", y = " << y << std::endl;

    swap(x, y);

    std::cout << "After swap: x = " << x << ", y = " << y << std::endl;

    return 0;
}
