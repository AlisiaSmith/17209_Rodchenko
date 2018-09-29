#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring> // for strcpy
#include <string> 
#include <stdlib.h>

using namespace std;
typedef string Key;

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

	// ���������� �������� ���� ���-������
	void swap(HashTable& b);
	
	HashTable& operator=(const HashTable& b);
	
	// ������� ���������.
	void clear();
	
	// ������� ������� �� ��������� �����.
	bool erase(const Key& k);
	
	// ������� � ���������. ������������ �������� - ���������� �������.
	bool insert(const Key& k, const Value& v);
	
	// �������� ������� �������� �� ��������� �����.
	bool contains(const Key& k) const;
	
	// ���������� �������� �� �����. ������������ �����.
	// � ������ ���������� ����� � ����������, ������� �������� � ���������
	// ��������, ��������� ������������� �� ��������� � ������� ������ �� ����. 
	Value& operator[](const Key& k);

	// ���������� �������� �� �����. ������� ���������� ��� �������.
	Value& at(const Key& k);
	const Value& at(const Key& k) const;

	size_t size() const;
	bool empty() const;

	friend bool operator==(const HashTable & a, const HashTable & b);
	friend bool operator!=(const HashTable & a, const HashTable & b);
	
	//~HashTable();
};