#include "Header.h"

int count_hash(string key)
{
	char *str = new char[key.length() + 1];
	strcpy(str, key.c_str());

	int hash = 0;
	for (int i = 0; i < key.length(); i++)
		hash += ((int)str[i] % 257) * (i % 23);
	return hash;
}

int recount_hash(int old_hash)
{
	int new_hash = old_hash;




	return new_hash;
}
// то, что выше - вынести в новый фаил

