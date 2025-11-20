#include "OrderedSet.h"
#include <algorithm>
#include <iostream>
using namespace std;

OrderedSet::OrderedSet() {
    size = 0;
    capacity = 10;
    try {
        data = new int[capacity];
    } catch (const bad_alloc&) {
        exit(1);
    }
}

OrderedSet::OrderedSet(const OrderedSet &other) {
    size = other.size;
    capacity = other.capacity;

    data = new int[capacity];

    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}

OrderedSet& OrderedSet::operator=(const OrderedSet &other) {
    if (*this != other) {
        delete[] data;

        size = other.size;
        capacity = other.capacity;

        try {
            data = new int[capacity];
            for (int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        }
        catch (const bad_alloc&) {
            size = 0;
            capacity = 10;
            data = new int[capacity];
            throw;
        }
    }
    return *this;
}

OrderedSet::~OrderedSet() {
    delete[] data;
}

void OrderedSet::resize() {
    int newCapacity = capacity * 2;
    int* newData = nullptr;
    try {
        newData = new int[newCapacity];
    } catch (const bad_alloc&) {
        exit(1);
    }
    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
}

int OrderedSet::findIndex(int value) const {
    // используем бинарный поиск
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (data[mid] == value) {
            return mid;
        }
        if (data[mid] < value) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

// добавление элемента
bool OrderedSet::add(int value) {
    if (findIndex(value) != -1) {
        return false;
    }

    if (size >= capacity) {
        resize();
    }

    int index = size;
    while (index > 0 && data[index - 1] < value) {
        data[index] = data[index - 1];
        index--;
    }
    data[index] = value;
    size++;
    return true;
}

// извлечение наибольшего элемента (с удалением из коллекции)
bool OrderedSet::get(int &value) {
    if (size == 0) {
        return false;
    }

    value = data[0];
    for (int i = 0; i < size - 1; i++) {
        data[i] = data[i + 1];
    }
    size--;
    return true;
}

// чтение наибольшего элемента (без удаления из коллекции)
bool OrderedSet::peek(int &value) const {
    if (size == 0) {
        return false;
    }

    value = data[0];
    return true;
}

// Извлечение элементов не меньших, чем value
// элементы копируются в buffer (удаляются из множества)
int OrderedSet::get(int value, int *&buffer) {
    int index = 0;
    while (index < size && data[index] >= value) {
        index++;
    }
    buffer = new int[index];
    for (int i = 0; i < index; i++) {
        buffer[i] = data[i];
    }
    for (int i = index; i < size; i++) {
        data[i - index] = data[i];
    }
    size -= index;
    return index;
}

// число элементов
int OrderedSet::count() const {
    return size;
}

// число элементов не меньших, чем value
int OrderedSet::count(int value) const {
    int k = 0;
    for (int i = 0; i < size; i++) {
        if (data[i] >= value) {
            k += 1;
        } else {
            break;
        }
    }
    return k;
}

// проверка наличия элемента
bool OrderedSet::contains(int value) const {
    return findIndex(value) != -1;
}

// проверка, является ли other подмножеством для текущего множества
bool OrderedSet::isSupersetFor(const OrderedSet &other) const {
    if (other.size == 0) {
        return true;
    } else if (other.size > size) {
        return false;
    }
    int i = 0, j = 0;
    while (i < size && j < other.size) {
        if (data[i] == other.data[j]) {
            j++;
        }
        i++;
    }
    return j == other.size;
}

OrderedSet OrderedSet::operator+(const OrderedSet &other) const {
    OrderedSet result;
    for (int i = 0; i < size; i++) {
        result.add(data[i]);
    }
    for (int i = 0; i < other.size; i++) {
        result.add(other.data[i]);
    }
    return result;
}

OrderedSet OrderedSet::operator-(const OrderedSet &other) const {
    OrderedSet result;
    for (int i = 0; i < size; i++) {
        if (!other.contains(data[i])) {
            result.add(data[i]);
        }
    }
    return result;
}

OrderedSet OrderedSet::operator&(const OrderedSet &other) const {
    OrderedSet result;
    for (int i = 0; i < size; i++) {
        if (other.contains(data[i])) {
            result.add(data[i]);
        }
    }
    return result;
}

bool OrderedSet::operator==(const OrderedSet &other) const {
    if (size == other.size) {
        for (int i = 0; i < size; i++) {
            if (data[i] != other.data[i]) {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool OrderedSet::operator!=(const OrderedSet &other) const {
    return !(*this == other);
}

bool OrderedSet::operator>(const OrderedSet &other) const {
    if (size > other.size) {
        return true;
    }
    if (size < other.size) {
        return false;
    }
    for (int i = 0; i < size; i++) {
        if (data[i] > other.data[i]) {
            return true;
        }
        if (data[i] < other.data[i]) {
            return false;
        }
    }
    return false;
}

bool OrderedSet::operator<(const OrderedSet &other) const {
    if (size < other.size) {
        return true;
    }
    if (size > other.size) {
        return false;
    }
    for (int i = 0; i < size; i++) {
        if (data[i] < other.data[i]) {
            return true;
        }
        if (data[i] > other.data[i]) {
            return false;
        }
    }
    return false;
}

bool OrderedSet::operator>=(const OrderedSet &other) const {
    if (*this == other || *this > other) {
        return true;
    }
    return false;
}

bool OrderedSet::operator<=(const OrderedSet &other) const {
    if (*this == other || *this < other) {
        return true;
    }
    return false;
}

ostream& operator<<(ostream& os, const OrderedSet& set) {
    os << "{";
    for (int i = 0; i < set.size; i++) {
        os << set.data[i];
        if (i < set.size - 1) {
            os << ", ";
        }
    }
    os << "}";
    return os;
}