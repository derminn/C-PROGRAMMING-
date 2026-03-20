## Objective

Understand segmentation faults, how they occur, and how to debug them using GDB.

---

##  Program Overview

This program simulates a segmentation fault caused by passing a NULL pointer through multiple function calls.

### Key Functions:

* `main()` → initializes pointer
* `fetch_data()` → passes pointer
* `validate_data()` → checks pointer (but fails to handle properly)
* `process_data()` → causes crash

---

##  Root Cause of Crash

```c
int *data = NULL;
fetch_data(data);
```

The pointer remains NULL and is dereferenced later:

```c
*ptr = 42;
```

---

##  GDB Debugging Process

### Step 1: Compile with debug symbols

```bash
gcc -g deep_segfault.c -o deep_segfault
```

### Step 2: Run in GDB

```bash
gdb ./deep_segfault
run
```

### Step 3: Analyze crash

```bash
bt
```

### Output:

```
#0 process_data (ptr=0x0)
#1 validate_data (ptr=0x0)
#2 fetch_data (ptr=0x0)
#3 main ()
```

### Step 4: Inspect variable

```bash
print ptr
```

Output:

```
(int *) 0x0
```

---

##  Key Learnings

* Segmentation fault occurs due to invalid memory access
* NULL pointer dereference is a common cause
* Bugs can originate in one function and crash in another
* `bt` (backtrace) helps trace function call chain
* Always validate pointers before use

---

## Fix Applied

```c
if (ptr == NULL) {
    printf("Error: NULL pointer\n");
    exit(1);
}
```

## Advanced Insights

* Segfaults are enforced by OS + hardware (MMU)
* Pointer bugs can propagate across multiple functions
* Debugging requires tracing *origin*, not just crash point

---

