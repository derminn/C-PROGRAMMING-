#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *num = malloc(sizeof(int));
    int *arr = malloc(5 * sizeof(int));
    char *text = malloc(10 * sizeof(char));

    *num = 100;

    for(int i = 0; i < 5; i++)
    {
        arr[i] = i + 1;
    }

    for(int i = 0; i < 9; i++)
    {
        text[i] = 'A' + i;
    }

    text[9] = '\0';

    printf("num value: %d\n", *num);
    printf("arr values: ");

    for(int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\ntext: %s\n", text);

    printf("\nPointer addresses:\n");
    printf("num  : %p\n", num);
    printf("arr  : %p\n", arr);
    printf("text : %p\n", text);

    free(num);
    free(arr);
    free(text);

    return 0;
}
