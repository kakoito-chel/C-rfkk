#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

const int N = 10;
void fillArray(int* arr, int size)
{
    for (int i = 0; i < size; i++)
        arr[i] = rand() % 100; 
}
void printArray(const int* arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(5) << arr[i];
    cout << endl;
}
void swapParts(int* arr, int size, int border)
{
    int temp[N];
    int k = 0;
    for (int i = border; i < size; i++)
        temp[k++] = arr[i];
    for (int i = 0; i < border; i++)
        temp[k++] = arr[i];
    for (int i = 0; i < size; i++)
        arr[i] = temp[i];
}

void findMax(const int* arr, int size, int& maxValue, int& maxIndex)
{
    maxValue = arr[0];
    maxIndex = 0;

    for (int i = 1; i < size; i++)
    {
        if (arr[i] > maxValue)
        {
            maxValue = arr[i];
            maxIndex = i;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(nullptr));

    int M[N];
    int border;
    int maxValue, maxIndex;

    fillArray(M, N);

    cout << "Исходный массив M:\n";
    printArray(M, N);

    cout << "\nВведите номер элемента-границы (от 1 до " << N - 1 << "): ";
    cin >> border;

    if (border <= 0 || border >= N)
    {
        cout << "Ошибка ввода границы!" << endl;
        return 0;
    }

    swapParts(M, N, border);

    cout << "\nМассив после перестановки частей:\n";
    printArray(M, N);

    findMax(M, N, maxValue, maxIndex);

    cout << "\nМаксимальный элемент массива = " << maxValue << endl;
    cout << "Позиция максимума (индекс) = " << maxIndex << endl;

    return 0;
}
