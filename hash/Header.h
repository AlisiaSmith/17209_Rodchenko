#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <math.h>

using namespace std;
typedef string Key;
 // характеристики студента
struct Value {
private:
	string name;
	unsigned int age;
	unsigned int weight;

public:
	Value();
	Value(const Key name, unsigned int a, unsigned int w);
	Value(const Value& v);
	~Value();
	const Key get_key() const;
	const Key get_key();
	Value& operator=(const Value& v);

	bool operator==(Value& v) const;
	bool operator==(Value *v) const;

	bool operator!=(Value& v) const;
	bool operator!=(Value *v) const;
};

struct Pair {
private:
	Key k;
	Value *elem;
public:
	bool flag;														
	Pair();
	~Pair();

	Pair& operator=(Pair & p);
	
	const Key get_key() const;
	Key get_key();
	
	void insert(const Value& v);
	void insert(Value& v);
	void insert();

	Value& get_value() const;

	void clear();
	
	friend bool operator==(const Pair& a, const Pair& b);

};


class HashTable
{
private:
	int quantity;
	int used;
	Pair *list;

	Value& _at(const Key k) const;
public:
	HashTable(int size);
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

	void resize();


	size_t size() const;
	bool empty() const;

	friend bool operator==(const HashTable & a, const HashTable & b);
	friend bool operator!=(const HashTable & a, const HashTable & b);

	//~HashTable();
};

int hash_count(const Key& k);
