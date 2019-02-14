#pragma once

#include "Header.h"
#include "Value.h"

struct Pair {
private:
	Key k;
	Value *elem;
    Pair *next;
public:

  Pair() = default;
	Pair(Pair& p);
	Pair(const Value& v, const Key& k);
	~Pair();



	void operator=(Pair& p);

	Key get_key() const;
	void put_key(const Key& t);
	Pair& get_next();

	void insert(const Value& v);
	void insert();

	Value& get_value() const;
	void clear();

	bool operator==(const Pair& p) const;
};
