#include <iostream>

// все в минуты
int toMin(int hours, int minutes) {
    return hours * 60 + minutes;
}

// в часы и мин
void fromMin(int totalMinutes, int& hours, int& minutes) { //& переменные передаются по ссылке. функции меняют значения переменных hours и minutes в main(), без возврата через return.
    hours = totalMinutes / 60;
    minutes = totalMinutes % 60; // остаток от деления
}

int main() {
    setlocale(LC_ALL, "RU");
    int h1, min1, h2, min2;

    std::cout << "Введите время начала (часы и минуты): ";
    std::cin >> h1 >> min1;

    std::cout << "Введите время окончания (часы и минуты): ";
    std::cin >> h2 >> min2;

    int start = toMin(h1, min1);
    int end = toMin(h2, min2);

    // Если студент закончил после полуночи
    if (end < start) {
        end += 24 * 60; // добавляем сутки
    }

    int time = end - start;

    int hours, minutes;
    fromMin(time, hours, minutes);

    std::cout << "Студент решал задачи " << hours << " ч. " << minutes << " мин.";

    return 0;
}
