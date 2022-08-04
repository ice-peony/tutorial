#include <stdio.h>
#define MIN(a, b) ((a) - (b) > 0 ? b : a )

int main{
	int a = 1, b = 3;
	int min = 0;
	min = MIN(a, b);
	printf("small one is %d\n", min);
	printf("hello World!");
	
	return 0;
}
