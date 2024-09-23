#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int x = 123;
    int *px = &x;
    printf("x   = %i -> variable direct value\n", x);
    printf("*x  = %i -> variable dereference value \n", x);
    printf("&x  = %p -> variable mem address\n", &x);
    printf("px  = %p -> pointer direct value\n", px);
    printf("*px = %i -> pointer deference value\n", *px);
    printf("&px = %p -> pointer mem address\n\n", &px);

    printf("Some random garbage values:\n");
    for (int i = 0; i < 10; i++)
    {
        px = &x + i;
        printf("px = &x + %i = %i\n", i, *px);
    }

    printf("\nPress the <ENTER> key to exit.\n");
    (void) getchar();

}
