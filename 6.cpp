#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    const int MAX_LINES = 100;
    string text[MAX_LINES];
    int lineCount = 0;
    int wordCount = 0;

    cout << "Введите строки (для окончания ввода введите finish):\n";

    
    while (true) {
        getline(cin, text[lineCount]);

        if (text[lineCount] == "finish")
            break;

        
        for (int i = 0; i < text[lineCount].length(); i++) {
            text[lineCount][i] = toupper(text[lineCount][i]);
        }

        lineCount++;
    }

    
    for (int i = 0; i < lineCount; i++) {
        bool inWord = false;
        for (int j = 0; j < text[i].length(); j++) {
            if (!isspace(text[i][j]) && !inWord) {
                wordCount++;
                inWord = true;
            }
            if (isspace(text[i][j])) {
                inWord = false;
            }
        }
    }

    
    int maxLength = 0;
    for (int i = 0; i < lineCount; i++) {
        if (text[i].length() > maxLength)
            maxLength = text[i].length();
    }

    cout << "\nКоличество слов во всём тексте: " << wordCount << endl;
    cout << "\n--- Отформатированный текст ---\n";

    
    for (int i = 0; i < lineCount; i++) {
        string s = text[i];

        int spaces = 0;
        for (int j = 0; j < s.length(); j++)
            if (s[j] == ' ')
                spaces++;

        int extra = maxLength - s.length();

        if (spaces > 0) {
            int add = extra / spaces;
            int rest = extra % spaces;

            string result = "";
            for (int j = 0; j < s.length(); j++) {
                result += s[j];
                if (s[j] == ' ') {
                    for (int k = 0; k < add; k++)
                        result += ' ';
                    if (rest > 0) {
                        result += ' ';
                        rest--;
                    }
                }
            }
            cout << result << endl;
        }
        else {
            cout << string(extra, ' ') << s << endl;
        }
    }

    return 0;
}
