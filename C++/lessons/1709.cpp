#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


class string
{
	int capacity;
	int len_now;

public:

	char *str;
	void append(char c)
	{
		this->len_now++;
		this->str[this->len_now] = c;
		if (this->len_now == this->capacity)
		{
			this->str = (char*)realloc(this->str, this->capacity * 2);
			this->capacity *= 2;
		}
		this->str[this->len_now++] = c;
	}

	~string()
	{
		free(this->str);
	}

	string(int size)
	{
		std::cout << "" << std::endl;
		capacity = size;
		str = (char*)malloc(size);
		len_now = 0;
	}
};

int main()
{
	string str(10);
	string str1(1);

	char c = 0;
	for (int i = 0; c != '\n'; ++i)
	{
		scanf("%c", &c);
		str.append(c);
	}
	//str.freee();
	printf("%s", str.str);
	return 0;
}