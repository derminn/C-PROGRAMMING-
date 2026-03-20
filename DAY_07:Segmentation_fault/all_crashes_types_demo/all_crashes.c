#include <stdio.h>
#include <stdlib.h>

/*
Crash Type 1: NULL Pointer Dereference
- Pointer explicitly set to NULL (0x0)
- Writing causes immediate SIGSEGV
*/
void null_deref() {
    int *p = NULL;
    *p = 1;
}

/*
Crash Type 2: Wild Pointer
- Pointer is uninitialized (contains garbage address)
- May crash or corrupt random memory
*/
void wild_pointer() {
    int *p;
    *p = 1;
}

/*
Crash Type 3: Heap Overflow
- Allocated space for 3 integers
- Writing far beyond boundary (index 10)
- Corrupts heap memory
*/
void heap_overflow() {
    int *a = malloc(3 * sizeof(int));
    a[10] = 1;   // out-of-bounds write
    free(a);
}

/*
Crash Type 4: Use-After-Free
- Memory is freed but pointer still used
- Undefined behavior (dangerous in real systems)
*/
void use_after_free() {
    int *p = malloc(sizeof(int));
    free(p);
    *p = 1;   // accessing freed memory
}

/*
Crash Type 5: Stack Overflow
- Infinite recursion
- Stack keeps growing until limit exceeded
*/
void stack_overflow() {
    stack_overflow();
}

int main() {
    int choice;

    printf("\nChoose crash type:\n");
    printf("1. NULL Dereference\n");
    printf("2. Wild Pointer\n");
    printf("3. Heap Overflow\n");
    printf("4. Use After Free\n");
    printf("5. Stack Overflow\n");
    printf("Enter choice: ");

    scanf("%d", &choice);

    if (choice == 1) null_deref();
    else if (choice == 2) wild_pointer();
    else if (choice == 3) heap_overflow();
    else if (choice == 4) use_after_free();
    else if (choice == 5) stack_overflow();
    else printf("Invalid choice\n");

    return 0;
}
