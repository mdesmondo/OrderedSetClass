#include "autoTests.h"
#include <iostream>
using namespace std;

void printAutoMenu() {
    cout << "Автоматическое тестирование класса OrderedSet" << endl;
    cout << "1 - Тест добавления элементов" << endl;
    cout << "2 - Тест проверки наличия элементов" << endl;
    cout << "3 - Тест просмотра наибольшего" << endl;
    cout << "4 - Тест извлечения элементов" << endl;
    cout << "5 - Тест операций над множествами" << endl;
    cout << "6 - Тест копирования" << endl;
    cout << "7 - Тест count с параметром" << endl;
    cout << "8 - Тест граничных случаев" << endl;
    cout << "9 - Тест с одним элементом" << endl;
    cout << "0 - Вернуться в главное меню" << endl;
}

int autoTest() {
    char command;
    string inputString;

    do {
        cout << "\nВыберите тест: ";
        cin >> inputString;

        if (inputString.length() == 1) {
            command = inputString[0];
            switch (command) {
                case '1': {
                    OrderedSet set;
                    testAdd(set);
                    break;
                }
                case '2': {
                    OrderedSet set;
                    set.add(5); set.add(3); set.add(7); set.add(1);
                    testContains(set);
                    break;
                }
                case '3': {
                    OrderedSet set;
                    set.add(5); set.add(3); set.add(7);
                    testPeek(set);
                    break;
                }
                case '4': {
                    OrderedSet set;
                    set.add(5); set.add(3); set.add(7); set.add(1); set.add(9);
                    testGet(set);
                    break;
                }
                case '5': testSetOperations(); break;
                case '6': {
                    OrderedSet set;
                    set.add(5); set.add(3); set.add(7);
                    testCopy(set);
                    break;
                }
                case '7': {
                    OrderedSet set;
                    set.add(1); set.add(3); set.add(5); set.add(7); set.add(9);
                    testCount(set);
                    break;
                }
                case '8': testEdgeCases(); break;
                case '9': testSingleElement(); break;
                case '0': cout << "Возвращение в главное меню..." << endl; break;
                default: cout << "Ошибка! Неверная команда." << endl;
            }
        } else {
            cout << "Ошибка! Введите один символ." << endl;
        }

    } while (command != '0');

    return 0;
}