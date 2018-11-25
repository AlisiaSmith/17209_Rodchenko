#pragma once

#include "Header.h"

struct Pair {
private:
	Key k;
	Value *elem;
public:
	unsigned int hash;
	bool flag;

	Pair();
	Pair(Pair& p);
	Pair(Value& v, Key& k);
	Pair(const Value& v, const Key& k);
	~Pair();

	Pair& operator=(Pair& p);

	const Key get_key() const;
	Key get_key();
	void put_key(const Key& t);
	void put_key(Key& t);

	void insert(const Value& v);
	void insert(Value& v);
	void insert();

	const Value& get_value() const;
	Value& get_value();
	void clear();

	bool operator==(const Pair& p) const;
};
