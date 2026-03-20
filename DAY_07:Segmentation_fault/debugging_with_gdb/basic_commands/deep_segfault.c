//////UNFIXED_CODE///////


#include <stdio.h>
#include <stdlib.h>

void process_data(int *ptr) {
    printf("Processing data...\n");

    *ptr = 42;   // 💥 CRASH happens here
}

void validate_data(int *ptr) {
    printf("Validating data...\n");

    if (ptr == NULL) {
        printf("Warning: pointer is NULL, but continuing...\n");
    }

    process_data(ptr);   // passing bad pointer forward
}

void fetch_data(int *ptr) {
    printf("Fetching data...\n");

    // Simulate bug: pointer never initialized
    validate_data(ptr);
}

int main() {
    int *data = NULL;   // ❌ root cause

    printf("Program started\n");

    fetch_data(data);

    printf("Program finished\n");
    return 0;
}
