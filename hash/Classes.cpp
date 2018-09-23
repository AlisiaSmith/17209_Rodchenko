#include "Header.h"


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

void HashTable::recount(int new_q)
	{

	}

void HashTable::add_el(string key)
	{

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
