#pragma once

#include "Pair.h"

Pair::Pair() {};
Pair::Pair(Pair& p)
{
	elem = new Value;
	*elem = *(p.elem);
	hash = p.hash;
	k = p.k;
	flag = true;
}
Pair::Pair(Value& v, Key& k) : k(k) { insert(v); }
Pair::Pair(const Value& v, const Key& k) : k(k) { insert(v); }
Pair::~Pair() { if (elem != nullptr) delete elem; }

Pair& Pair::operator=(Pair & p)
{
	if (*this == p) return *this;
	if (elem != nullptr) delete elem;
	elem = new Value;
	*elem = *(p.elem);
	hash = p.hash;
	k = p.k;
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
	hash = NULL;
	flag = false;
	delete elem;
}

bool Pair::operator==(const Pair& p) const { return ((k == p.k) && (elem == p.elem) &&(flag == p.flag)); }
