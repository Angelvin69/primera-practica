#include <stdio.h>


int main()
{
    int x =10;
    int *p =&x;
    printf ("puntero %p \n",p);
    

    int y = 10;
    int *p = *y;

    printf("printo por referancia %p " , p)
    return 0;
}
