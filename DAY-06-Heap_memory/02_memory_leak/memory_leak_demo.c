#include <stdio.h>
#include <stdlib.h>

int main()
{
    int iterations = 100;
    int bytes_per_alloc = 100;
    int total_bytes = 0;

    for(int i = 1; i <= iterations; i++)
    {
        char *ptr = (char*) malloc(bytes_per_alloc);

        if(ptr == NULL)
        {
            printf("Memory allocation failed\n");
            return 1;
        }

        total_bytes += bytes_per_alloc;

        printf("Allocation #%d | Total bytes allocated: %d\n", i, total_bytes);

        /* INTENTIONALLY NOT freeing memory */
    }

    printf("Program finished (memory leak occurred)\n");

    return 0;
}
