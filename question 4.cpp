#include <iostream>

void printString(const char* str) {
    while (*str != '\0') {  // Пока не встречен нулевой терминатор
        std::cout << *str;  // Вывод текущего символа
        str++;              // Переход к следующему символу
    }
    std::cout << std::endl; // Вывод новой строки
}

int main() {
    const char* str = "Hello, world!"; 
    printString(str);

    return 0;
}
