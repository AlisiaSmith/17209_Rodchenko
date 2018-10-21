#include "Header.h"




/*Value*/




Value::Value() : name(""), age(0), weight(0) {}
Value::Value(const Key name, unsigned int a, unsigned int w) : name(name), age(a), weight(w) {}
Value::Value(const Value& v) : name(v.name), age(v.age), weight(v.weight) {}

Value::~Value() {}

Value& Value::operator=(const Value& v)
{
	name = v.name;
	age = v.age;
	weight = v.weight;
	return *this;
}

bool Value::operator==(Value& v) const { return ((name == v.name) && (age == v.age) && (weight == v.weight)); }
bool Value::operator==(Value *v) const { return this == v; }

bool Value::operator!=(Value& v) const { return !((name == v.name) && (age == v.age) && (weight == v.weight)); } 
bool Value::operator!=(Value *v) const { return this != v; } 




/*Pair*/




Pair::Pair() {};
Pair::~Pair() { if (elem != nullptr) delete elem; }

Pair& Pair::operator=(Pair & p)
{
	if (*this == p) return *this;
	if (elem != nullptr) delete elem;
	elem = p.elem; 
	hash = p.hash;
	flag = true;
	return *this;
}

const Key Pair::get_key() const { return k; }
Key Pair::get_key() { return k; }
void Pair::put_key(const Key& t) { k = t; }
void Pair::put_key(Key& t) { k = t; }


void Pair::insert(const Value& v)
{
	flag = true;
	elem = new Value;
	*elem = v;
	hash = hash_count(k);
}
void Pair::insert(Value& v)
{
	flag = true;
	elem = new Value;
	*elem = v;
	hash = hash_count(k);
}
void Pair::insert()
{
	flag = true;
	elem = new Value;
	hash = hash_count(k);
}

const Value& Pair::get_value() const { return *elem; }
Value& Pair::get_value() { return *elem; }

void Pair::clear()
{
	k.clear();
	flag = false;
	delete elem;
}

bool Pair::operator==(const Pair& p) const { return ((k == p.k) && (elem == p.elem) &&(flag == p.flag)); }


/*HashTable*/




HashTable::HashTable(int size = 100) : quantity(size), used(0) { list = new Pair[size]; }
HashTable::HashTable(const HashTable& other) : quantity(other.quantity), used(other.used) { for (int i = 0; i < other.quantity; i++)	list[i] = other.list[i]; }

HashTable::~HashTable() { clear(); }

HashTable& HashTable::operator=(const HashTable& other)
{
	if(&other == this) return *this;
	clear();
	quantity = other.quantity;
	list = new Pair[quantity];
	for (int i = 0; i < quantity; ++i)
		list[i] = other.list[i];
	used = other.used;
	return *this;
}

void HashTable::clear() { delete[] list; }

int HashTable::_find_num(const Key& k, int hash) const
{
	int i = 0;
	for (i; i < quantity; ++i)
		if (list[(hash + i) % quantity].get_key() == k) break;

	return (hash + i) % quantity;
}

bool HashTable::erase(const Key& k)
{
	if (!contains(k)) return true;
	int hash = hash_count(k);
	int i = _find_num(k, hash);
	if (list[i].flag) list[i].clear();
	used--;

	// теперь надо сместить некоторые ячейки вверх по циклу
	int tmp = quantity - 1; 
	int j = ((i + 1) % quantity);									// следующая ячейка
	while (list[j].flag && tmp)
	{
		int tmp_hash = list[j].hash % quantity;						// хэш ключа следующей ячейки
		if (tmp_hash == hash)										// если хэши равны, то сместим ячейку на одну вверх
		{															// настоящая ячейка всегда заведомо очищена
			list[i] = list[j]; 
			list[j].clear();
		}
		else														// иначе
		{
			hash = tmp_hash;										// обновим дефолтный хэш
			if (j == hash) break;									// если он совподвет с номеров ячейки, все хорошо, уходим
		}
		i = j;
		j = ((i + 1) % quantity);									// передвигаемся на следующую ячейку по циклу
		tmp--;														// минус одна пройденная ячейка
	}
	return true;
} 
	//int tmp = quantity - 1;											
	//i = ((i + 1) % quantity);										// начнем со следующей ячейки
	//while (list[i].flag && tmp)
	//{
	//	int tmp_hash = list[i].hash % quantity;						// хэш ключа текущей ячейки
	//	if (tmp_hash == hash)										// если хэши равны, то сместим ячейку на одну вверх
	//	{															// предыдущая ячейка всегда заведомо очищена
	//		list[i - 1] = list[i]; // если i == 0 ? 
	//		list[i].clear();
	//	}
	//	else														// иначе
	//	{
	//		hash = tmp_hash;										// обновим дефолтный хэш
	//		if (i == hash) break;									// если он совподвет с номеров ячейки, все хорошо, уходим
	//	}
	//	i = ((i + 1) % quantity);									// передвигаемся на следующую ячейку по циклу
	//	tmp--;														// минус одна пройденная ячейка
	//}
	//return true;

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

void HashTable::resize() 
{
	Pair* new_list = new Pair[quantity * 2];
	for (int i = 0; i < quantity; i++)		
		new_list[i] = list[i];
	clear();
	list = new_list;
	quantity *= 2;
//перезапись по новым хешам
} 

bool HashTable::insert(const Key& k, const Value& v)
{
	if(contains(k)) return false;
	if (size() == quantity) resize();

	int hash = hash_count(k);
	
	int i = 0;
	for (i = 0; i < quantity; i++)
		if (list[(hash + i) % quantity].flag == false) //true?
		{
			int tmp_hash = (list[(hash + i) % quantity].hash) % quantity;
			if (hash == tmp_hash) continue;
			else
			{

			}
		}
	list[(hash + i) % quantity].put_key(k);
	list[(hash + i) % quantity].insert(v);
	used++;
	return true;
}

bool HashTable::contains(const Key& k) const
{
	int hash = hash_count(k);
	for (int i = 0; i < quantity && &list[(hash + i) % quantity] != nullptr; ++i)
		if(list[(hash +i) % quantity].get_key() == k) return true;

	return false;
}

Value& HashTable::operator[](const Key& k)
{
	int hash = hash_count(k);
	
	if (!contains(k))
		for (int i = 0; i < quantity; i++) //?
			if (list[(hash + i) % quantity].flag) 
			{
				list[(hash + i) % quantity].insert();
				return list[(hash + i) % quantity].get_value();
			}

	int i = _find_num(k, hash);
	return list[i].get_value();
}

Value& HashTable::_at(const Key& k) const
{
	try
	{
		if (!contains(k)) throw 1;
		int hash = hash_count(k);
		int i = _find_num(k, hash);
		return list[i].get_value();
	}
	catch (...) { cout << "You have failed" << endl; }
}
const Value& HashTable::at(const Key& k) const { return _at(k); }
Value& HashTable::at(const Key& k) { return _at(k); }

size_t HashTable::size() const { return used; }

bool HashTable::empty() const { return used == 0; }