#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>  


void sigsegv_handler(int sig) {
    const char *msg = "[CRASH REPORTER] Caught SIGSEGV!\n";

  
    write(1, msg, strlen(msg));

    _exit(1);  
}

int main() {
    signal(SIGSEGV, sigsegv_handler);

    printf("Setting up crash handler...\n");

    int *ptr = NULL;
    *ptr = 10;  

    return 0;
}
