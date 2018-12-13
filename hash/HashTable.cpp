#include "HashTable.h"

int hash_count(const Key& k)
{
    unsigned int len = (unsigned int) k.length();
    unsigned int hash = 0;
    if (len > 15) len = 15;
    for (unsigned int i = 0; i < len; ++i)
        hash = +(unsigned int)(k[i]*pow(3, i));
    return hash;
}


HashTable::HashTable() : quantity(_DEFAUT_HT_SIZE_) { list = new Pair[_DEFAUT_HT_SIZE_]; }
HashTable::HashTable(size_t size) : quantity(size) { list = new Pair[size]; }
HashTable::HashTable(const HashTable& other) : quantity(other.quantity), used(other.used) { for (int i = 0; i < other.quantity; i++)	list[i] = other.list[i]; }

HashTable::~HashTable() { delete[] list; }

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

void HashTable::clear()
{
    if(empty()) return;
    delete[] list;
    list = new Pair[quantity];
    used = 0u;
}

bool HashTable::erase(const Key& k)
{
	if (!contains(k)) return true;
	int hash = hash_count(k);

    Pair *tmp = &(list[hash]);
    Pair *tmp_prev = nullptr;

    while(tmp->get_key() != k)
    {
        tmp_prev = tmp;
        tmp = tmp->next;
    }

    if(tmp_prev)
        tmp_prev->next = tmp->next;
    else list[hash] = *(tmp->next);

    tmp->next = nullptr;
    delete tmp;

    used--;

	return true;
}

void HashTable::swap(HashTable& b)
{
	Pair* tmp_l = list;
    size_t tmp_q = quantity;
	int tmp_u = used;

	list = b.list;
	quantity = b.quantity;
	used = b.quantity;

	b.list = tmp_l;
	b.quantity = tmp_q;
	b.used = tmp_u;
}


bool HashTable::insert(const Key& k, const Value& v)
{
	if(contains(k)) return false;

	int hash = hash_count(k);

    Pair *tmp = &(list[hash]);
    while (tmp->flag) tmp = tmp->next;

    tmp = new Pair;
    Pair t(v, k);
    *tmp = t;
    tmp->flag = true;

    return true;
}

bool HashTable::contains(const Key& k) const
{
	int hash = hash_count(k);

    Pair *tmp = &(list[hash]);
    while(tmp && tmp->flag)
        if (tmp->get_key() == k) return true;
        else tmp = tmp->next;

	return false;
}

Value& HashTable::operator[](const Key& k)
{
    if (!contains(k)) insert(k, Value());
    return _at(k);
}

Value& HashTable::_at(const Key& k) const
{
	try
	{
		if (!contains(k)) throw 1;
	}
	catch (...) { cout << "You have failed" << endl; }

    int hash = hash_count(k);
    Pair *tmp = &(list[hash]);
    while(tmp->get_key() != k)
        tmp = tmp->next;
    return tmp->get_value();
}
const Value& HashTable::at(const Key& k) const { return _at(k); }
Value& HashTable::at(const Key& k) { return _at(k); }

size_t HashTable::size() const { return used; }
size_t HashTable::size_ht() const { return quantity; }

bool HashTable::empty() const { return used == 0; }
