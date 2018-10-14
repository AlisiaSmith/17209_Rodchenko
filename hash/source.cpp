//
// Created by AlisiaSmith on 17.09.18.
//

#include "Header.h"

void help()
{

}

int execution(string cmd, HashTable Table)
{


	return 0;
}

int hash_count(const Key& k)
{
	unsigned int len = (unsigned int) k.length();
	unsigned int hash = 0;
	if (len > 15) len = 15;
	vector <char> str(len);
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
	//int count_nambers = 0;
	//cin >> count_nambers; cout << endl;
//
//HashTable MyTable(&);
//	string cmd;
//
	//do {
	//	cin >> cmd; cout << endl;
	//	if (cmd == "exit") break;
//
//
	//} while (true);
//
	return 0;
}
