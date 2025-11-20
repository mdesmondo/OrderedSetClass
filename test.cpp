#include <algorithm>
using namespace std;
#include <iostream>
#include "test.h"

void printSetInfo(const OrderedSet& set, const string& name) {
    cout << name << " = " << set << " (размер: " << set.count() << ")" << endl;
}

void testAdd(OrderedSet& set) {
    cout << "\nТест добавления элементов" << endl;

    cout << "Добавляем 5: " << (set.add(5) ? "успешно" : "дубликат") << endl;
    cout << "Добавляем 3: " << (set.add(3) ? "успешно" : "дубликат") << endl;
    cout << "Добавляем 7: " << (set.add(7) ? "успешно" : "дубликат") << endl;
    cout << "Добавляем 3 (дубликат): " << (set.add(3) ? "успешно" : "дубликат") << endl;
    cout << "Добавляем 1: " << (set.add(1) ? "успешно" : "дубликат") << endl;
    cout << "Добавляем 9: " << (set.add(9) ? "успешно" : "дубликат") << endl;

    printSetInfo(set, "Множество после добавления");

    // Тест добавления больше 10 элементов (проверка resize)
    cout << "\n--- Тест добавления больше 10 элементов ---" << endl;
    for (int i = 10; i <= 15; i++) {
        set.add(i);
    }
    printSetInfo(set, "Множество после добавления 11-15");
}

void testContains(const OrderedSet& set) {
    cout << "\nТест проверки наличия элементов" << endl;
    printSetInfo(set, "Множество");

    cout << "Содержит 7: " << (set.contains(7) ? "да" : "нет") << endl;
    cout << "Содержит 3: " << (set.contains(3) ? "да" : "нет") << endl;
    cout << "Содержит 1: " << (set.contains(1) ? "да" : "нет") << endl;
    cout << "Содержит 10: " << (set.contains(10) ? "да" : "нет") << endl;
    cout << "Содержит 0: " << (set.contains(0) ? "да" : "нет") << endl;
    cout << "Содержит 100: " << (set.contains(100) ? "да" : "нет") << endl;
}

void testPeek(const OrderedSet& set) {
    cout << "\nТест просмотра наибольшего элемента" << endl;
    printSetInfo(set, "Множество");

    int value;
    if (set.peek(value)) {
        cout << "Наибольший элемент: " << value << endl;
    } else {
        cout << "Множество пусто" << endl;
    }

    // Тест с пустым множеством
    OrderedSet emptySet;
    if (emptySet.peek(value)) {
        cout << "Наибольший в пустом: " << value << endl;
    } else {
        cout << "Пустое множество: peek вернул false (корректно)" << endl;
    }
}

void testGet(OrderedSet& set) {
    cout << "\nТест извлечения элементов" << endl;

    printSetInfo(set, "Изначальное множество");

    // Извлечение наибольшего
    int value;
    if (set.get(value)) {
        cout << "Извлечен наибольший элемент: " << value << endl;
    }
    printSetInfo(set, "После извлечения наибольшего");

    // Извлечение элементов >= определенного значения
    int* buffer = nullptr;
    int count = set.get(5, buffer);
    cout << "Извлечено элементов >= 5: " << count << endl;
    if (count > 0) {
        cout << "Извлеченные элементы: ";
        for (int i = 0; i < count; i++) {
            cout << buffer[i] << " ";
        }
        cout << endl;
        delete[] buffer;
    }
    printSetInfo(set, "После массового извлечения");

    // Тест извлечения из пустого множества
    OrderedSet emptySet;
    if (!emptySet.get(value)) {
        cout << "Извлечение из пустого множества: вернул false (корректно)" << endl;
    }
}

void testSetOperations() {
    cout << "\nТест операций над множествами" << endl;

    OrderedSet setA, setB;

    setA.add(1); setA.add(3); setA.add(5); setA.add(7); setA.add(9);
    setB.add(2); setB.add(3); setB.add(5); setB.add(6); setB.add(8);

    printSetInfo(setA, "Множество A");
    printSetInfo(setB, "Множество B");

    OrderedSet sumSet = setA + setB;
    printSetInfo(sumSet, "A + B (объединение)");

    OrderedSet interSet = setA & setB;
    printSetInfo(interSet, "A & B (пересечение)");

    OrderedSet diffSet = setA - setB;
    printSetInfo(diffSet, "A - B (разность)");

    // Сравнение
    cout << "\nТест сравнения множеств" << endl;
    cout << "A == B: " << (setA == setB ? "да" : "нет") << endl;
    cout << "A != B: " << (setA != setB ? "да" : "нет") << endl;
    cout << "A > B: " << (setA > setB ? "да" : "нет") << endl;
    cout << "A < B: " << (setA < setB ? "да" : "нет") << endl;
    cout << "A >= B: " << (setA >= setB ? "да" : "нет") << endl;
    cout << "A <= B: " << (setA <= setB ? "да" : "нет") << endl;

    // Проверка подмножества
    cout << "\nТест проверки подмножества" << endl;
    OrderedSet subset;
    subset.add(3); subset.add(5);
    printSetInfo(subset, "Множество");
    cout << "A является надмножеством для {3, 5}: " << (setA.isSupersetFor(subset) ? "да" : "нет") << endl;

    OrderedSet notSubset;
    notSubset.add(3); notSubset.add(10);
    printSetInfo(notSubset, "Множество");
    cout << "A является надмножеством для {3, 10}: " << (setA.isSupersetFor(notSubset) ? "да" : "нет") << endl;
}

void testCopy(OrderedSet& set) {
    cout << "\nТест копирования и присваивания" << endl;

    printSetInfo(set, "Изначальное множество");

    // Конструктор копирования
    OrderedSet copy1 = set;
    printSetInfo(copy1, "Копия (конструктор)");

    // Оператор присваивания
    OrderedSet copy2;
    copy2.add(100); copy2.add(200);  // Добавляем что-то свое
    printSetInfo(copy2, "До присваивания");
    copy2 = set;
    printSetInfo(copy2, "После присваивания");

    // Проверка независимости копий
    cout << "\nПроверка независимости копий" << endl;
    set.add(999);  // Меняем оригинал
    printSetInfo(set, "Оригинал после добавления 999");
    printSetInfo(copy1, "Копия 1 (не должна измениться)");
    printSetInfo(copy2, "Копия 2 (не должна измениться)");

    // Проверка самоприсваивания
    cout << "\nПроверка самоприсваивания" << endl;
    set = set;
    printSetInfo(set, "После самоприсваивания");
}

void testCount(const OrderedSet& set) {
    cout << "\nТест count с параметром" << endl;
    printSetInfo(set, "Множество");

    cout << "Всего элементов: " << set.count() << endl;
    cout << "Элементов >= 1: " << set.count(1) << endl;
    cout << "Элементов >= 5: " << set.count(5) << endl;
    cout << "Элементов >= 10: " << set.count(10) << endl;
    cout << "Элементов >= 100: " << set.count(100) << endl;

    // Тест с пустым множеством
    OrderedSet emptySet;
    cout << "В пустом множестве элементов >= 1: " << emptySet.count(1) << endl;
}

void testEdgeCases() {
    cout << "\nТест граничных случаев" << endl;

    OrderedSet emptySet;
    printSetInfo(emptySet, "Пустое множество");

    // Все операции с пустым множеством
    int value;
    cout << "Peek в пустом: " << (emptySet.peek(value) ? "есть значение" : "false") << endl;
    cout << "Get в пустом: " << (emptySet.get(value) ? "есть значение" : "false") << endl;
    cout << "Count в пустом: " << emptySet.count() << endl;
    cout << "Contains 1 в пустом: " << emptySet.contains(1) << endl;

    // Массовое извлечение из пустого
    int* buffer = nullptr;
    int count = emptySet.get(1, buffer);
    cout << "Массовое извлечение из пустого: извлечено " << count << " элементов" << endl;
    if (count > 0) {
        delete[] buffer;
    }
}

void testSingleElement() {
    cout << "\nТест с одним элементом" << endl;

    OrderedSet single;
    single.add(42);
    printSetInfo(single, "Множество с одним элементом");

    int value;
    cout << "Peek: ";
    if (single.peek(value)) cout << value << endl;

    cout << "Get: ";
    if (single.get(value)) cout << value << endl;

    printSetInfo(single, "После извлечения");
}