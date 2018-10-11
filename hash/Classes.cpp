#include "Header.h"

HashTable::HashTable(int size = 100) : quantity(size)
{
	list = (Value*)calloc(size, sizeof(Value));
	used = 0;
}
HashTable::HashTable(const HashTable& other)
{
	//list = other.list; // ПЛОХО БЕЗ СТР.13
	//quantity = other.quantity;
	//used = other.used;
	//other.list = nullptr;
	//other.quantity = 0;
	//other.used = 0;
}

// мей би наоборот

HashTable& HashTable::operator=(const HashTable& other)
{
	//if(other == *this) return this;
	//free(list);
	//list = other.list; // ПЛОХО БЕЗ СТР.27
	//quantity = other.quantity;
	//used = other.used;
	//other.list = nullptr;
	//other.quantity = 0;
	//other.used = 0;
	//return this;
}

void HashTable::swap(HashTable& b)
{

}

void HashTable::clear()
{
//mb
	if(list)
		free(list);
}

bool HashTable::erase(const Key& k)
{

}

void HashTable::recount()
{

}

bool HashTable::insert(const Key& k, const Value& v)
{
	if(contains(k)) return false;
	if (used == quantity) recount();
	int hash = hash_count(k);
	int i;
	for (i = 0; i < quantity; ++i)
		while (list[(hash +i) % quantity] != NULL)
			if(list[(hash +i) % quantity].k == k) continue;
	list[(hash +i) % quantity] = v;
	used++;
}


bool HashTable::contains(const Key& k) const
{
	int hash = hash_count(k);
	for (int i = 0; i < quantity; ++i)
		while (list[(hash +i) % quantity] != NULL)
			if(list[(hash +i) % quantity].k == k) return true;
	return false;
}

Value& HashTable::operator[](const Key& k)
{
	if(contains(k))
	{
		int hash = hash_count(k);
		for (int i = 0; i < quantity; ++i)
				if(list[(hash +i) % quantity].k == k) return list[(hash +i) % quantity];
	}
	//else too
}

const Value& HashTable::at(const Key& k) const
{

}

size_t HashTable::size() const
{

}

bool HashTable::empty() const
{

}

HashTable::~HashTable(){
	clear();
}
