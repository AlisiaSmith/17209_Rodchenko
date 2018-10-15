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



bool Value::operator==(Value& v) const	{	return ((k == v.k) && (age == v.age) && (weight == v.weight));	} 
bool Value::operator==(Value *v) const { return this == v; }

bool Value::operator!=(Value& v) const { return !((k == v.k) && (age == v.age) && (weight == v.weight)); } 
bool Value::operator!=(Value *v) const { return this != v; } 



/*Pair*/



const Key Pair::get_key() const { return k; }
const Key Pair::get_key() { return k; }

void Pair::clear()
{
	flag = false;
	delete elem;
}

/*HashTable*/




HashTable::HashTable(int size = 100) : quantity(size), used(0) { list = new Pair[size]; }
HashTable::HashTable(const HashTable& other) : quantity(other.quantity), used(other.used) { for (int i = 0; i < other.quantity; ++i)	list[i] = other.list[i]; }

HashTable::~HashTable() { delete[] list; }

HashTable& HashTable::operator=(const HashTable& other)
{
	if(&other == this) return *this;
	delete[] list;
	quantity = other.quantity;
	list = new Pair[quantity];
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
	if (list[(hash + i) % quantity].flag) list[(hash + i) % quantity].clear();
	cout << "elem is deleted" << endl;
	used--;
	return true;
	// пересмотреть элементы, идущие после данного и проверить, не нужно ли их переместить выше 
} 

void HashTable::swap(HashTable& b)
{
	Pair* tmp_l = list;
	int tmp_q = quantity;
	int tmp_u = used;

	list = b.list;
	quantity = b.quantity;
	used = b.quantity;

	b.list = tmp_l;
	b.quantity = tmp_q;
	b.used = tmp_u;
}


void HashTable::recount() 
{
	Pair* new_list = new Pair[quantity * 2];
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
	
	// переписать

	//int i; Value tmp;
	//
	//for (i = 0; i < quantity; ++i)
	//	 if (list[(hash + i) % quantity] == tmp) break; 
	//
	//list[(hash + i) % quantity] = v;
	//used++;
	cout << "elem is added " << endl;
		return true;
}


bool HashTable::contains(const Key& k) const
{
	int hash = hash_count(k);

	// переписать
	
	/*for (int i = 0; i < quantity && list[(hash + i) % quantity] != nullptr; ++i)
			if(list[(hash +i) % quantity].get_key() == k) return true;*/
	return false;
}

// Вообще по-другому 

//Value& HashTable::operator[](const Key& k)
//{
//	Value tmp;
//	if (!contains(k)) return tmp;
//	int hash = hash_count(k);
//	int i = 0;
//	for (i; i < quantity; ++i)
//		if (list[(hash + i) % quantity].get_key() == k)		break;
//	return list[(hash + i) % quantity];
//}
//
//const Value& HashTable::at(const Key& k) const
//{
//	Value tmp;
//	if (!contains(k)) return tmp;
//	int hash = hash_count(k);
//	int i = 0;
//	for (i; i < quantity; ++i)
//		if (list[(hash + i) % quantity].get_key() == k)		break;
//	return list[(hash + i) % quantity];
//}



size_t HashTable::size() const { return used; }
//
//bool HashTable::empty() const
//{
//	return true;
//}
//
