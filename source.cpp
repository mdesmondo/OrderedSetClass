#include <iostream>
#include "OrderedSet.h"
#include "test.h"
#include "interactiveTests.h"
#include "autoTests.h"
using namespace std;
#include <string>


void printMenu() {
    cout << "\nГЛАВНОЕ МЕНЮ" << endl;
    cout << "1 - Автоматические тесты" << endl;
    cout << "2 - Интерактивное тестирование" << endl;
    cout << "f - Выход из программы" << endl;
}

int main() {
    char command;
    string inputString;

    do {
        printMenu();
        cout << "Выберите режим: ";
        cin >> inputString;
        if (inputString.length() == 1) {
            command = inputString[0];
            switch (command) {
                case '1': {
                    printAutoMenu();
                    autoTest();
                    break;
                }
                case '2': {
                    printInterMenu();
                    interTest();
                    break;
                }
                case 'f':
                case 'F': {
                    cout << "Выход из программы..." << endl;
                    break;
                }
                default: {
                    cout << "Неверная команда!" << endl;
                }
            }
        } else {
            cout << "Введите один символ!" << endl;
        }
    } while (command != 'f' && command != 'F');
}