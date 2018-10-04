#include "Header.h"

HashTable::HashTable(const HashTable& b)
{

}

void HashTable::swap(HashTable& b)
{

}

HashTable& HashTable::operator=(const HashTable& b)
{

}

void HashTable::clear()
{

}

bool HashTable::erase(const Key& k)
{

}


bool HashTable::insert(const Key& k, const Value& v)
{
	if (used == quantity) recount;
	if(contains(k)) return FALSE;
	int hash = hash_count(k);
	while (TRUE)
	{
		if(!list[(hash)%quantity])
		{
			list[(hash)%quantity] = v;
			break;
		}
		hash++;
	}

}


bool HashTable::contains(const Key& k) const
{

}

Value& HashTable::operator[](const Key& k)
{

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
