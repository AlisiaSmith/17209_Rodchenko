//
// Created by AlisiaSmith on 17.09.18.
//

#include "Header.h"


int hash_count(const Key& k)
{
	unsigned int len = (unsigned int) k.length();
	unsigned int hash = 0;
	if (len > 15) len = 15;
	for (unsigned int i = 0; i < len; ++i)
		hash = +(unsigned int)(k[i]*pow(3, i));
	return hash;
}

void error()
{
	cout << "The command is wrong." << endl << "Ener a \"help\" to get instruction." << endl;
}

int main ()
{
	const Value v("Anna", 17, 45);
	const Value w("Ivan", 19, 66);
	const Value x("Kate", 18, 52);
	const Value y("Tony", 17, 58);

	

	return 0;
}
