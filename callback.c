#include <stdio.h>

void ck_1(int a){
	printf("hua No:%d\n", a);
}

void ck_2(int a){
	printf("hua No:%d\n", a);
}


void pfun(int num, void(*ck)(int))
{
	printf("entering callbackFunc\n");
	int a = num;
	printf("hello everyone I'm little tree Number is %d \n",a);
	printf("-----------------\n");
}

int main()
{
	pfun(176, ck_1);
	pfun(9, ck_2);
	return 0;
}