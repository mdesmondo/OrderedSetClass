#ifndef TEST_H
#define TEST_H

#include "OrderedSet.h"

void printSetInfo(const OrderedSet& set, const string& name); // вывод информации о множестве
void testAdd(OrderedSet& set); // тест добавления элементов
void testContains(const OrderedSet& set); // тест проверки наличия элементов
void testPeek(const OrderedSet& set); // тест просмотра наибольшего элемента
void testGet(OrderedSet& set); // тест извлечения элементов
void testSetOperations(); // тест операций над множествами
void testCopy(OrderedSet& set); // тест копирования и присваивания
void testCount(const OrderedSet& set); // тест count с параметром
void testEdgeCases(); // тест граничных случаев
void testSingleElement(); // тест с одним элементом

#endif