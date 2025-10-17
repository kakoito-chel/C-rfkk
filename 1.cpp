#include <iostream>
using namespace std;

int main() {
    int n;
    
    cout << "Введи градусы Цельсия(число должно быть не больше 15 и меньше 0): ";
    cin >> n;
    
    if (n <= 0) {
        cout << "Братик, число должно быть больше нуля :(" << endl;
        return 1;
    }
    
    if (n >= 15) {
        cout << "Друже, ты че? Я же написал НЕ БОЛЬШЕ 15" << endl;
        return 1;
    }
    
    double C, F;
    
    cout << "Введите " << n << " значений в градусах Цельсия:" << endl;
    
    for (int i = 0; i < n; i++) {
        cout << "Число " << (i + 1) << ": ";
        cin >> C;
        
        F = C * 9.0 / 5.0 + 32.0;
        
        cout << C << "°C = " << F << "°F" << endl;
    }
    
    return 0;
}
