#include "../headers/HashTable.h"


HashTable::HashTable(int size = 727) : quantity(size), used(0) { list = new Pair[size]; }
HashTable::HashTable(const HashTable& other) : quantity(other.quantity), used(other.used) { for (int i = 0; i < other.quantity; i++)	list[i] = other.list[i]; }

HashTable::~HashTable() { clear(); }

HashTable& HashTable::operator=(const HashTable& other)
{
	if(&other == this) return *this;
	clear();
	quantity = other.quantity;
	list = new Pair[quantity];
	for (int i = 0; i < quantity; ++i)
		list[i] = other.lisr[i];
	used = other.used;
	return *this;
}

void HashTable::clear() { delete[] list; }

/*{
	int i = 0;
	for (i; i < quantity; ++i)
		if (list[(hash + i) % quantity].get_key() == k) break;

	return (hash + i) % quantity;
}*/

bool HashTable::erase(const Key& k)
{
	if (!contains(k)) return true;
	int hash = hash_count(k);
	int i = _find_num(k, hash);
	if (list[i].flag) list[i].clear();
	used--;

/*	// теперь надо сместить некоторые ячейки вверх по циклу
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
	}*/
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

/*void HashTable::resize()
{
	Pair* new_list = new Pair[quantity * 2];
	for (int i = 0; i < quantity; i++)	// неправильно
		new_list[i] = list[i];
	clear();
	list = new_list;
	quantity *= 2;
//перезапись по новым хешам
}*/

bool HashTable::insert(const Key& k, const Value& v)
{
	if(contains(k)) return false;
//	if (size() == quantity) resize();

	int hash = hash_count(k);

	//int i = 0;
/*	Pair p(v,k);
	Pair tp;
	int th = hash;
	for (i = 0; i < quantity; i++)
	{
		if (list[(hash + i) % quantity].flag == false)	break;
		int tmp_hash = (list[(hash + i) % quantity].hash);
		if (th % quantity == tmp_hash % quantity) continue;
		tp = list[(hash + i) % quantity];
		list[(hash + i) % quantity] = p;
		th = tmp_hash;
	}
	list[(hash + i) % quantity] = p;
	used++;
	return true; */
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
