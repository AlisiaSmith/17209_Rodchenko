#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

 struct string
{
	char *str;
	int capacity;
	int len_now;
};

 void append(struct string *str, char c)
 {
	 str->len_now++;
	 str->str[str->len_now] = c;
	 if (str->len_now == str->capacity)
	 {
		 str->str = (char*)realloc(str->str, str->capacity * 2);
		 str->capacity *= 2;
	 }
	 str->str[str->len_now++] = c;
}

 void freee(struct string *str)
 {
	 free(str->str);
 }

 void init(struct string *str, int size)
 {
	 str->capacity = size;
	 str->str = (char*)malloc(size);
	 str->len_now = 0;
 }

int main() 
{
	char c =0;
	struct string str;
	init(&str, 100);
	for (int i = 0; c != '\n'; ++i)
	{
		scanf("%c", &c);
		append(&str, c);
	}
	freee(&str);
	return 0;
}