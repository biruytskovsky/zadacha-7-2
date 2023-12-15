#include <iostream>
#include <vector>
#include <algorithm>

// Функция для вычисления суммы цифр числа
int sumOfDigits(int num) {
    int sum = 0;
    while (num != 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main() {
    // Исходная последовательность чисел
    std::vector<int> sequence = { 53, 72, 19, 87, 45 };

    // Сортировка по условиям
    std::sort(sequence.begin(), sequence.end(), [](int a, int b) {
        int sumA = sumOfDigits(a);
        int sumB = sumOfDigits(b);

        if (sumA == sumB) {
            if (a % 10 == b % 10) {
                return a < b;
            }
            return (a % 10) < (b % 10);
        }

        return sumA < sumB;
        });

    // Вывод упорядоченной последовательности
    for (int number : sequence) {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    return 0;
}