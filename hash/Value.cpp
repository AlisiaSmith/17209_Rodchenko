#pragma once

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


bool Value::operator==(Value& v) const { return ((name == v.name) && (age == v.age) && (weight == v.weight)); }
bool Value::operator==(Value *v) const { return this == v; }

bool Value::operator!=(Value& v) const { return !((name == v.name) && (age == v.age) && (weight == v.weight)); }
bool Value::operator!=(Value *v) const { return this != v; }
