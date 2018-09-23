#pragma once

#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;



class Person
{
private:
	string name;
	string key;
	int point;
public:
	Person();
	~Person();
};

class HashTable
{
private:
	int quantity;
	int used;
	Person *list;
public:
	HashTable(int N = 100);
	void recount(int new_q);
	void add_el(string key);
	void del_el(string key);
	Person* serch(string key);
	~HashTable();
};