#include "Value.h"

Value::Value() : name("Ivanov Ivan Ivanivich"), age(23), weight(78) {}
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

string Value::get_name() const {	return name;	}
unsigned int Value::get_age() const { return age; }
unsigned int Value::get_weight() const {	return weight;	}

bool Value::operator==(Value& v) const { return ((name == v.name) && (age == v.age) && (weight == v.weight)); }
bool Value::operator==(Value *v) const { return this == v; }

bool Value::operator!=(Value& v) const { return !((name == v.name) && (age == v.age) && (weight == v.weight)); }
bool Value::operator!=(Value *v) const { return this != v; }
