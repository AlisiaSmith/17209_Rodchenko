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

void error() 
{
	cout << "The command is wrong." << endl << "Ener a \"help\" to get instruction." << endl;
}

int main ()
{
	int count_nambers = 0;
	cin >> count_nambers; cout << endl;
	
	HashTable MyTable(count_nambers);
	string cmd;
	
	do {
		cin >> cmd; cout << endl;
		if (cmd == "exit") break;
		
		if (!execution(cmd, MyTable)) error();
		

	} while (true);

	return 0;
}
