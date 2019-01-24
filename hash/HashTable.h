#pragma once

#include "Header.h"
#include "Pair.h"

#define _DEFAUT_HT_SIZE_ 727

int hash_count(const Key& k);

class HashTable
{
private:
	size_t quantity;
	size_t used = 0u;
	Pair *list;

	Value& _at(const Key& k) const;
	int _find_num(const Key& k, int hash) const;
public:
	HashTable();
	HashTable(size_t size);
	~HashTable();

	HashTable(const HashTable& other);

	// Обменивает значения двух хэш-таблиц.
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
	size_t size_ht() const;
	bool empty() const;

    bool operator==(const HashTable & a) const;
	bool operator!=(const HashTable & a) const;

    Pair* getList(int i) const;
//	friend bool operator==(const HashTable & a, const HashTable & b);
//	friend bool operator!=(const HashTable & a, const HashTable & b);

	//~HashTable();
};

int hash_count(const Key& k);
