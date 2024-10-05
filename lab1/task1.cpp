#include <iostream>
#include <cstdlib>
#include <ctime> 

int main() {
    short arr[10];

    std::srand(std::time(0));

    for (int i = 0; i < 10; i++) {
        arr[i] = std::rand() % 100;
    }

    std::cout << "Массив: ";

    for (int i = 0; i < 10; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
    std::cout << "Расстояния от первого элемента в байтах:" << std::endl;

    for (int i = 0; i < 10; ++i) {
        std::cout << i + 1 << ": " << i * sizeof(short) << std::endl;
    }

    return 0;
}
