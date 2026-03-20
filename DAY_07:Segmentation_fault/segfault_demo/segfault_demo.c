#include <stdio.h>

int main() {
    int *ptr = NULL;
    printf("About to crash...\n");
    *ptr = 10;   // SIGSEGV here
    return 0;
}
