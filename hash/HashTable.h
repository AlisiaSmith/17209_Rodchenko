#pragma once

#include <math.h>

#include "Header.h"
#include "Pair.h"


#define _DEFAUT_HT_SIZE_ 727



class HashTable
{
private:
	size_t quantity;
	size_t used = 0u;
	Pair *list;

	Value& _at(const Key& k) const;
public:
    int hash_count(const Key& k) const;

	HashTable();
	HashTable(size_t size);
	~HashTable();

	HashTable(const HashTable& other);

	// Обменивает значения двух хэш-таблиц.
	void swap(HashTable& b);

	void operator=(const HashTable& b);

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

    Pair& getList(int i) const;

    void put_size(size_t s);
    void put_size_ht(size_t q);
    void put_list(Pair* l);
};
