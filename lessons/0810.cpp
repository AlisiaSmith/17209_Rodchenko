#include <iostream>

int *arr1 = new int[100];
int *arr2 = new int[100];

int main(){
	for (int i = 0; i < 100; i++)
	{
		arr2[i] = arr1[i];
	}

	std::fill(arr1, arr1 + 100, 0);
	std::copy(arr1, arr1 + 100, arr2);
	return 0;
}