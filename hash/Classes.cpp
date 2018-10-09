#include "Header.h"

HashTable::HashTable(int size = 100) : quantity(size)
{
	list = (Value*)calloc(size, sizeof(Value));
	used = 0;
}
HashTable::HashTable(const HashTable& other)
{
	ohter.list = this.list;
	other.quantity = this.quantity;
	oter.used = this.used;
	this.list = nullptr;
	this.quantity = 0;
	this.used = 0;
}

// мей би наоборот

HashTable& HashTable::operator=(const HashTable& other)
{
	if(other == this) return other;
	free(0oter.list);
	ohter.list = this.list;
	other.quantity = this.quantity;
	oter.used = this.used;
	this.list = nullptr;
	this.quantity = 0;
	this.used = 0;
	return other;
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


bool HashTable::insert(const Key& k, const Value& v)
{
	if(contains(k)) return false;
	if (used == quantity) recount;
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
				if(list[(hash +i) % quantity];.k == k) return list[(hash +i) % quantity];
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
