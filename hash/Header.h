#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;
typedef string Key;
 // характеристики студента
struct Value {
	unsigned age;
	unsigned weight;
};


class HashTable
{
private:
	int quantity;
	int used;

public:
	HashTable(const HashTable& b);

	// Обменивает значения двух хэш-таблиц.
  // Подумайте, зачем нужен этот метод, при наличии стандартной функции
  // std::swap.
	void swap(HashTable& b);

	HashTable& operator=(const HashTable& b);

	// Очищает контейнер.
	void clear();

	// Удаляет элемент по заданному ключу.
	bool erase(const Key& k);

	// Вставка в контейнер. Возвращаемое значение - успешность вставки.
	bool insert(const Key& k, const Value& v);

	// Проверка наличия значения по заданному ключу.
	bool contains(const Key& k) const;

	// Возвращает значение по ключу. Небезопасный метод.
	// В случае отсутствия ключа в контейнере, следует вставить в контейнер
	// значение, созданное конструктором по умолчанию и вернуть ссылку на него.
	Value& operator[](const Key& k);

	// Возвращает значение по ключу. Бросает исключение при неудаче.
	Value& at(const Key& k);
	const Value& at(const Key& k) const;

	size_t size() const;
	bool empty() const;

	friend bool operator==(const HashTable & a, const HashTable & b);
	friend bool operator!=(const HashTable & a, const HashTable & b);

	//~HashTable();
};

int hash_count(const Key& k);
