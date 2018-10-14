#include "Header.h"



/*Value*/



Value::Value() : k(""), age(0), weight(0) {}
Value::Value(const Key name, unsigned int a, unsigned int w) : k(name), age(a), weight(w) {}
Value::Value(const Value& v) : k(v.k), age(v.age), weight(v.weight) {}

Value::~Value() {}

Value& Value::operator=(const Value& v)
{
	k = v.k;
	age = v.age;
	weight = v.weight;
	return *this;
}

const Key Value::get_key() const {	return k; }
const Key Value::get_key() { return k; } 

void Value::clear()
{
	k = "";
	age = NULL;
	weight = NULL;
} 

bool Value::operator==(Value& v) const	{	return ((k == v.k) && (age == v.age) && (weight == v.weight));	} 
bool Value::operator==(Value *v) const { return this == v; } 

bool Value::operator!=(Value& v) const { return !((k == v.k) && (age == v.age) && (weight == v.weight)); } 
bool Value::operator!=(Value *v) const { return this != v; } 




/*HashTable*/




HashTable::HashTable(int size = 100) : quantity(size)
{
	list = new Value [size]; 
	used = 0;
	cout << "table size of " << size << " is created" << endl;
}
HashTable::HashTable(const HashTable& other)
{
	for (int i = 0; i < other.quantity; ++i)
		list[i] = other.list[i];
	
	quantity = other.quantity;
	used = other.used;	
}

HashTable::~HashTable() {
	delete[] list;
	cout << "table size of " << quantity << " is deleted" << endl;
}

HashTable& HashTable::operator=(const HashTable& other)
{
	if(&other == this) return *this;
	delete[] list;
	quantity = other.quantity;
	list = new Value[quantity];
	for (int i = 0; i < quantity; ++i)
		list[i] = other.list[i];
	used = other.used;
	return *this;
}

bool HashTable::erase(const Key& k)
{
	if (!contains(k)) return false;
	int hash = hash_count(k);
	int i = 0;
	for (i; i < quantity; ++i)
		if (list[(hash + i) % quantity].get_key() == k) break;
	list[(hash + i) % quantity].clear();
	cout << "elem is deleted" << endl;
	return true;
	// пересмотреть элементы, идущие после данного и проверить, не нужно ли их переместить выше 
} //+


void HashTable::recount() 
{
	Value* new_list = new Value[quantity * 2];
	for (int i = 0; i < quantity; i++)		
		new_list[i] = list[i];
	delete[] list;
	list = new_list;
	quantity *= 2;
//перезапись по новым хешам
} // +

bool HashTable::insert(const Key& k, const Value& v)
{
	if(contains(k)) return false;
	if (used == quantity) recount();

	int hash = hash_count(k);
	int i; Value tmp;
	
	for (i = 0; i < quantity; ++i)
		 if (list[(hash + i) % quantity] == tmp) break; 
	
	list[(hash + i) % quantity] = v;
	used++;
	cout << "elem is added " << endl;
		return true;
}

bool HashTable::contains(const Key& k) const
{
	int hash = hash_count(k);
	for (int i = 0; i < quantity && list[(hash + i) % quantity] != nullptr; ++i)
			if(list[(hash +i) % quantity].get_key() == k) return true;
	return false;
}
