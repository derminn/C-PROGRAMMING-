#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr;

    ptr = (int*) malloc(5 * sizeof(int));

    if(ptr == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    ptr[0] = 10;
    ptr[1] = 20;
    ptr[2] = 30;
    ptr[3] = 40;
    ptr[4] = 50;

    for(int i = 0; i < 5; i++)
    {
        printf("Value: %d | Address: %p\n", ptr[i], &ptr[i]);
    }

    free(ptr);
    ptr = NULL;

    return 0;
}
