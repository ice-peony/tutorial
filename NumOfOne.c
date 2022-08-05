#include <stdio.h>

int main()
{
    printf("Please input a nummber:\n");
    int a;
    scanf("%d",&a);

    int i = 1;
    while (a &= a-1)
    {
        i++;/* code */
    }
    
    printf("1 has : %d\n",i);
    return 0;
}
