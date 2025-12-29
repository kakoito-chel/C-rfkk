#include <iostream>
#include <cstring>

using namespace std;

// Структура книги
struct Book {
    char author[50];
    char title[50];
    char publisher[50];
    int circulation;
};

int main() {
    int n;
    cout << "Введите количество книг: ";
    cin >> n;
    cin.ignore();

    // Динамический массив книг
    Book* books = new Book[n];

    // Ввод данных
    for (int i = 0; i < n; i++) {
        cout << "\nКнига " << i + 1 << endl;

        cout << "Автор: ";
        cin.getline(books[i].author, 50);

        cout << "Название: ";
        cin.getline(books[i].title, 50);

        cout << "Издательство: ";
        cin.getline(books[i].publisher, 50);

        cout << "Тираж: ";
        cin >> books[i].circulation;
        cin.ignore();
    }

    char searchPublisher[50];
    int minCirculation;

    cout << "\nВведите издательство для поиска: ";
    cin.getline(searchPublisher, 50);

    cout << "Введите минимальный тираж: ";
    cin >> minCirculation;

    // Подсчёт подходящих книг
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(books[i].publisher, searchPublisher) == 0 &&
            books[i].circulation > minCirculation) {
            count++;
        }
    }

    // Динамический массив результата
    Book* result = new Book[count];
    int k = 0;

    for (int i = 0; i < n; i++) {
        if (strcmp(books[i].publisher, searchPublisher) == 0 &&
            books[i].circulation > minCirculation) {
            result[k++] = books[i];
        }
    }

    // Вывод результата
    cout << "\n=== Найденные книги ===\n";

    if (count == 0) {
        cout << "Подходящих книг нет.\n";
    } else {
        for (int i = 0; i < count; i++) {
            cout << "\nАвтор: " << result[i].author;
            cout << "\nНазвание: " << result[i].title;
            cout << "\nИздательство: " << result[i].publisher;
            cout << "\nТираж: " << result[i].circulation << endl;
        }
    }

    delete[] books;
    delete[] result;

    return 0;
}
