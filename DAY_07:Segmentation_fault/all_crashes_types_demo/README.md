# All Crash Types Demo

## Objective
Demonstrate multiple types of memory errors in C.

## Crash Types Implemented

### 1. NULL Pointer Dereference
Accessing memory at address 0x0 → SIGSEGV

### 2. Wild Pointer
Uninitialized pointer leads to random memory access

### 3. Heap Overflow
Writing beyond allocated memory corrupts heap

### 4. Use-After-Free
Accessing memory after it has been freed

### 5. Stack Overflow
Infinite recursion exhausts stack memory

## GDB Observations

- `bt` shows exact crash location
- Stack overflow shows deep recursive calls
- NULL deref shows pointer = 0x0

## Key Learning

Memory safety issues lead to:
- Crashes (SIGSEGV)
- Undefined behavior
- Security vulnerabilities

