#include "interactiveTests.h"
#include "OrderedSet.h"
#include <iostream>
#include <limits>
using namespace std;

void printInterMenu() {
    cout << "\nИнтерактивное тестирование класса OrderedSet" << endl;
    cout << "q - Вывести меню" << endl;
    cout << "1 - Добавить элемент" << endl;
    cout << "2 - Извлечь наибольший элемент" << endl;
    cout << "3 - Показать наибольший элемент" << endl;
    cout << "4 - Проверить наличие элемента" << endl;
    cout << "5 - Извлечь элементы >= значения" << endl;
    cout << "6 - Показать количество элементов" << endl;
    cout << "7 - Показать количество элементов >= значения" << endl;
    cout << "8 - Показать все множество" << endl;
    cout << "9 - Очистить множество" << endl;
    cout << "0 - Вернуться в главное меню" << endl;
}

int interTest() {
    OrderedSet set;
    char command;
    string inputString;

    do {
        cout << "Текущее множество: " << set << endl;
        cout << "Размер: " << set.count() << " элементов" << endl;

        cout << "\nВыберите действие: ";
        cin >> inputString;

        if (inputString.length() == 1) {
            command = inputString[0];
            switch (command) {
                case 'q':
                    case 'Q': {
                    printInterMenu();
                    break;
                }
                case '1': {
                    int value;
                    cout << "Введите элемент для добавления: ";
                    if (cin >> value) {
                        if (set.add(value)) {
                            cout << "Элемент " << value << " успешно добавлен" << endl;
                        } else {
                            cout << "Элемент " << value << " уже существует" << endl;
                        }
                    } else {
                        cout << "Ошибка ввода! Введите целое число." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    break;
                }

                case '2': {
                    int value;
                    if (set.get(value)) {
                        cout << "Извлечен наибольший элемент: " << value << endl;
                    } else {
                        cout << "Множество пусто" << endl;
                    }
                    break;
                }

                case '3': {
                    int value;
                    if (set.peek(value)) {
                        cout << "Наибольший элемент: " << value << endl;
                    } else {
                        cout << "Множество пусто" << endl;
                    }
                    break;
                }

                case '4': {
                    int value;
                    cout << "Введите элемент для проверки: ";
                    if (cin >> value) {
                        if (set.contains(value)) {
                            cout << "Элемент " << value << " найден в множестве" << endl;
                        } else {
                            cout << "Элемент " << value << " не найден" << endl;
                        }
                    } else {
                        cout << "Ошибка ввода! Введите целое число." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    break;
                }

                case '5': {
                    int value;
                    cout << "Введите минимальное значение: ";
                    if (cin >> value) {
                        int* buffer = nullptr;
                        int count = set.get(value, buffer);
                        cout << "Извлечено элементов >= " << value << ": " << count << endl;
                        if (count > 0) {
                            cout << "Извлеченные элементы: ";
                            for (int i = 0; i < count; i++) {
                                cout << buffer[i] << " ";
                            }
                            cout << endl;
                            delete[] buffer;
                        }
                    } else {
                        cout << "Ошибка ввода! Введите целое число." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    break;
                }

                case '6': {
                    cout << "Количество элементов в множестве: " << set.count() << endl;
                    break;
                }

                case '7': {
                    int value;
                    cout << "Введите значение: ";
                    if (cin >> value) {
                        cout << "Элементов >= " << value << ": " << set.count(value) << endl;
                    } else {
                        cout << "Ошибка ввода! Введите целое число." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    break;
                }

                case '8': {
                    cout << "Текущее множество: " << set << endl;
                    break;
                }

                case '9': {
                    set = OrderedSet();
                    cout << "Множество очищено" << endl;
                    break;
                }

                case '0': {
                    cout << "Возвращение в главное меню..." << endl;
                    break;
                }

                default: {
                    cout << "Ошибка! Неверная команда." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
        } else {
            cout << "Ошибка! Введите один символ." << endl;
        }

    } while (command != '0');

    return 0;
}