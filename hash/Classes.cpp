#include "Header.h"


/*Value*/


Value::Value() {}
Value::Value(const Key name, unsigned int a, unsigned int w) : k(name), age(a), weight(w)
{
	cout << "created " << k << endl;
}
Value::Value(const Value& v) : k(v.k), age(v.age), weight(v.weight) // переделать
{
	cout << "copyed " << k << endl;
}

Value::~Value() {
	cout << "deleted " << k << endl;
}

Value& Value::operator=(const Value& v) //недоделано
{
	k = v.k;
	age = v.age;
	weight = v.weight;
	return *this;
}

const Key Value::get_key() const { return k; }



/*HashTable*/




HashTable::HashTable(int size = 100) : quantity(size)
{
	list = new Value[size];
	used = 0;
}

HashTable::~HashTable() {
	delete[] list;
}

//HashTable::HashTable(const HashTable& other)
////{
//	//list = other.list; // ПЛОХО БЕЗ СТР.13
//	//quantity = other.quantity;
//	//used = other.used;
//	//other.list = nullptr;
//	//other.quantity = 0;
//	//other.used = 0;
//}
//
//// мей би наоборот
//
////HashTable& HashTable::operator=(const HashTable& other)
////{
//	//if(other == *this) return this;
//	//free(list);
//	//list = other.list; // ПЛОХО БЕЗ СТР.27
//	//quantity = other.quantity;
//	//used = other.used;
//	//other.list = nullptr;
//	//other.quantity = 0;
//	//other.used = 0;
//	//return this;
////}


void HashTable::recount()
{

}

bool HashTable::insert(const Key& k, const Value& v)
{
	if (contains(k)) return false;
	if (used == quantity) recount();
	int hash = hash_count(k);
	//int i;
	//for (i = 0; i < quantity; ++i)
	//	if (list[(hash +i) % quantity] == nullptr) break;
	//list[(hash /*+ i*/) % quantity].k == k;
	list[(hash /*+i*/) % quantity] = v;
	used++;
	return true;
}


bool HashTable::contains(const Key& k) const
{
	int hash = hash_count(k);
	for (int i = 0; i < quantity; ++i)
		//while (!(list[(hash +i) % quantity]))
		if (list[(hash + i) % quantity].get_key() == k) return true;
	return false;
}
//
////Value& HashTable::operator[](const Key& k)
////{
////	if(contains(k))
////	{
////		int hash = hash_count(k);
////		for (int i = 0; i < quantity; ++i)
////				if(list[(hash +i) % quantity].k == k) return list[(hash +i) % quantity];
////	}
////	//else too
////}
//
////const Value& HashTable::at(const Key& k) const
////{
////
////}
//
////size_t HashTable::size() const
////{
////
////}
//
//bool HashTable::empty() const
//{
//	return true;
//}
//
