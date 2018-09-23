#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring> // for strcpy
#include <string> 
#include <stdlib.h>

using namespace std;



class Person
{
private:
	string name;
	int point;
public:
	bool ex = false;
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
	int verify(int pos = 0);
	void recount_list(int);
	void add_el(string);
	void del_el(string);
	Person* serch(string);
	~HashTable();
};