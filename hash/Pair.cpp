#include "Pair.h"



Pair::Pair(){}
Pair::Pair(const Key& k) : k(k) {  insert();   }
Pair::Pair(const Value& v, const Key& k) : k(k) { insert(v); }
Pair::Pair(Pair& p)
{
    elem = new Value;
    *elem = p.get_value();
    k = p.get_key();
    if(p.get_next()) next = new Pair(*(p.get_next()));
}

Pair::~Pair() {
    if (elem) delete elem;
    if(next) delete next;
}

bool Pair::is_empty() const { return  !elem;    }

void Pair::operator=(Pair & p)
{
	if (this == &p) return;
	if (elem != nullptr) delete elem;
	if (next != nullptr) delete next;
	if (!p.is_empty())
	{
        elem = new Value(p.get_value());
        k = p.get_key();
    }
	if(p.get_next())  next = new Pair(*p.get_next());
}

Pair* Pair::get_next() const        { return next;  }
Key Pair::get_key() const           { return k; }
Value& Pair::get_value() const      { return *elem; }
void Pair::put_key(const Key& t)    { k = t; }
void Pair::put_next(Pair p)
{
    if(next) delete next;
    next = new Pair(p);
}

void Pair::insert(const Value& v)
{
    if (elem) delete elem;
    elem = new Value(v);
}

void Pair::insert()
{
    if(elem) delete elem;
	elem = new Value;
}

void Pair::insert_back(const Value& v, const Key& k)
{
    Pair *tmp = this;
    Pair *prev_tmp = nullptr;
    if(tmp)
    {
        prev_tmp = tmp;
        tmp = tmp->get_next();
    }
    tmp = new Pair(v, k);

    prev_tmp->put_next(*tmp);
}


void Pair::clear()
{
    *this = *next;
}



bool Pair::operator==(const Pair& p) const
{
    if( this == &p ) return true;

    if(p.is_empty() != is_empty()) return false;

    if(!(p.is_empty() && is_empty())){
        if(!((k == p.get_key()) && (*elem == p.get_value()))) return false;}

    if (! (next && p.get_next())) {
        if (next) return false;
        if (p.get_next()) return false;
        return true;
    }
    return *next == *p.get_next();
}
bool Pair::operator!=(const Pair& p) const { return !(*this == p);  }