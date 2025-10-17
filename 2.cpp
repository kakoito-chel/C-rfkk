#include <iostream>
#include <cmath>
using namespace std;

// Определение количества цифр в десятичной записи числа
int count_dig(int a) {
    if (a == 0) return 1; 
    int cnt = 0;
    a = abs(a); // на случай отрицательного числа
    while (a > 0) {
        cnt++;
        a /= 10;
    }
    return cnt;
}

// Вычисление суммы цифр числа
int sum_dig(int a) {
    int sum = 0;
    a = abs(a);
    while (a > 0) {
        sum += a % 10;
        a /= 10;
    }
    return sum;
}

// Удаление последней цифры (работает по ссылке)
void del_last_dig(int& a) {
    a /= 10;
}

// Удаление первой цифры (возвращаем результат по значению)
int del_first_dig(int& a) {
    int k = count_dig(a);
    if (k == 1) return 0; // если всего одна цифра, то остаётся 0
    int pow10 = pow(10, k - 1); 
    return a % pow10;
}

int main() {
    int n;
    cout << "Введите целое число: ";
    cin >> n;

    cout << "Исходное число: " << n << endl;
    cout << "Количество цифр: " << count_dig(n) << endl;
    cout << "Сумма цифр: " << sum_dig(n) << endl;

    int without_last = n;
    del_last_dig(without_last);

    int without_first = del_first_dig(n);

    cout << "Число без первой цифры: " << without_first << endl;
    cout << "Число без последней цифры: " << without_last << endl;

    return 0;
}
