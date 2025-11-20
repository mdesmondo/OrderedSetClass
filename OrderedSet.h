#ifndef ORDEREDSET_H
#define ORDEREDSET_H

#include <iostream>
using namespace std;

class OrderedSet {
public:
    OrderedSet();
    OrderedSet(const OrderedSet &other);
    // операция присваивания
    OrderedSet& operator=(const OrderedSet &other);
    ~OrderedSet();
    [[nodiscard]] int findIndex(int value) const; // поиск индекса по значению
    // добавление элемента
    bool add(int value);
    // извлечение наибольшего элемента (с удалением из коллекции)
    bool get(int& value);
    // чтение наибольшего элемента (без удаления из коллекции)
    bool peek(int& value) const;
    // Извлечение элементов не меньших, чем value
    // элементы копируются в buffer (удаляются из множества),
    int get(int value, int*& buffer);
    // число элементов
    [[nodiscard]] int count() const;
    // число элементов не меньших, чем value
    [[nodiscard]] int count(int value) const;
    // проверка наличия элемента
    [[nodiscard]] bool contains(int value) const;
    // проверка, является ли other подмножеством для текущего множества
    [[nodiscard]] bool isSupersetFor(const OrderedSet& other) const;
    // операции объединения (c устранением дублирования элементов)
    OrderedSet operator+(const OrderedSet& other) const; // объединение двух множеств
    OrderedSet operator-(const OrderedSet& other) const; // разность двух множеств
    OrderedSet operator&(const OrderedSet& other) const; // пересечение двух множеств
    bool operator==(const OrderedSet& other) const;
    bool operator>(const OrderedSet& other) const;
    bool operator<(const OrderedSet& other) const;
    bool operator>=(const OrderedSet& other) const;
    bool operator<=(const OrderedSet& other) const;
    bool operator!=(const OrderedSet& other) const;
    // вывод коллекций через перегрузку оператора
    friend ostream& operator<<(ostream& os, const OrderedSet& set);


private:
    int size; // кол-во элементов
    int* data; // динамический массив
    int capacity; // выделенная динамическая память

    void resize(); // изменение размера
};

ostream& operator<<(ostream& os, const OrderedSet& set);

#endif // ORDEREDSET_H