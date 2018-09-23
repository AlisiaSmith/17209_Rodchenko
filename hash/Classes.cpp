#include "Header.h"

int count_hash(string key)
{
	char *str = new char[key.length() + 1];
	strcpy(str, key.c_str());

	int hash = 0;
	for (int i = 0; i < key.length(); i++)
		hash += ((int)str[i] % 257) * (i % 23);
	return hash;
}

int recount_hash(int old_hash)
{
	int new_hash = old_hash;




	return new_hash;
}
// то, что выше - вынести в новый фаил

Person::Person()
	{
		cout << "person created" << endl;
	}
	
Person::~Person()
	{
		cout << "person deleted" << endl;
	}

HashTable::HashTable(int N) : quantity(N)
	{
		cout << "hash created" << endl;
		used = 0;
		list = (Person*)calloc(N, sizeof(Person));
	}


int HashTable:: verify(int pos)
{
	if (!&(list[pos])) return 0; // выглядит очень странно на самом деле
	return list[pos].ex;
	}

void HashTable::recount_list(int new_q)
	{
	list = (Person*)realloc(list, quantity * 2);
	quantity *= quantity;
	}


void HashTable::add_el(string key)
	{
	int hash = count_hash(key);
	while (verify(hash))	hash = recount_hash(hash); 
	//во-первых надо точно пройти по всем элементам массива!
	//во-вторых как-то учесть динамическое рассширение
	}

Person* HashTable::serch(string key)
	{
	return this->list; // is wrong
	}

void HashTable::del_el(string key)
	{

	}


HashTable::~HashTable()
	{
		free(list);
		cout << "hash deleted" << endl;
	}
