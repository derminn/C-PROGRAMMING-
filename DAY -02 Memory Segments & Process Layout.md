# DAY -2 :Memory Segments & Process Layout

## Overview :

- Text Segment
- Data Segment
- BSS
- Heap
- Stack
- How Linux maps programs into memory

## Process Memory Layout;

A running Linux program is divided into structured regions:

┌──────────────────────────────┐
│        High Memory           │
│──────────────────────────────│
│   Stack      (grows ↓)       │  ← local variables
│──────────────────────────────│
│   Free Space              │
│──────────────────────────────│
│   Heap       (grows ↑)       │
│──────────────────────────────│
│   BSS        (uninitialized globals) │
│──────────────────────────────│
│   Data       (initialized globals)  │
│──────────────────────────────│
│   Text       (program instructions) │
│──────────────────────────────│
│        Low Memory            │
└──────────────────────────────┘

This structure is **predictable and deliberate.**

## **Memory Segments Explained :**

### (1) Text Segment

- Contains compiled instructions
- Readable + executable (`r-xp`)
- **Not writable**
- Example from `/proc/<pid>/maps`: `r-xp ... /home/xyz/program`

### (2) Data Segment

- Stores **initialized** global/static variables
- Writable

c

`int global_init = 80;  // goes here`

### (3) BSS Segment

- Stores **uninitialized** global/static variables
- Automatically zero-initialized

c

`int global_uninit;  // goes here`

### (4) Heap

- Used for dynamic allocation (`malloc`)
- Grows **upward** ↑
- Managed by allocator (`glibc malloc`)

c

`int *p = malloc(sizeof(int));`

### (5) Stack

- Stores: local variables, function parameters, return addresses
- Grows **downward** ↓
- Each function call creates a **new stack frame**

## **Global vs Local Variables :**

`int global_var = 100;       // → .data segment
int uninitialized_global;   // → .bss segment`

`int main() {
int local_var = 50;     // → stack
}`

### Sample output (addresses):

`Address of global_var:          0x555555559040
Address of uninitialized_global: 0x555555559044
Address of local_var:           0x79ffffffffe2ac`

- Global variables are **close together** (same segment)
- Local variables are **far away** (on the stack, high memory)
- Global variables are **close together** (same segment)
- Local variables are **far away** (on the stack, high memory)

## Why Is the Stack Address So High?

- Stack lives near **high virtual memory addresses**
- x86-64 CPUs use only **48 bits** for addressing
- Max user-space address: `0x00007FFFFFFFFFFF`
- Stack starts near top → addresses begin with `0x7fff...`

**Each hex digit = 4 bits → 12 digits = 48 bits** (full virtual address)

## Heap vs Stack Growth Direction :

| Region | Direction | Reason |
| --- | --- | --- |
| Heap | Grows ↑ (upward) | Starts above BSS/Data |
| Stack | Grows ↓ (downward) | Starts near high memory |

### **Why opposite directions ?**

- Efficient use of memory
- No fixed boundary required
- Flexible dynamic growth
- Simple collision detection: **if they meet → out of memory**

## Why Global Variables Are Stored Near Each Other ?

- Globals live for the **entire program duration** — grouping in persistent segment makes memory management trivial (no alloc/dealloc needed)
- Compiler knows sizes → assigns **fixed addresses ahead of time** → laid out sequentially in binary
- OS maps these segments into **contiguous virtual memory** chunks — more efficient than scattering them

## Array Writing Direction (Stack) :

Important concept:

- Stack grows **downward**
- But writing to arrays increases addresses

```python
char buffer[16];
// buffer[0] → lower address
// buffer[15] → higher address
// Overflow writes toward HIGHER addresses
```

## Why Buffer Overflow Hits the Return Address?

Typical Stack Frame Layout:

```python
┌─────────────────┐  ← Higher Address
│  Return Address │
│  Saved Base Ptr │
│  buffer[16]     │
└─────────────────┘  ← Lower Address
```

If buffer overflows → writes upward → **overwrites return address**

> **That's how stack smashing begins.**
> 

## Verifying with `/proc/<pid>/maps` :

**Steps:**

1. Add `getchar();` to pause the program
2. Run it
3. Get PID: `ps aux | grep program`
4. Inspect: `cat /proc/<PID>/maps`

**Look for:**

- `r-xp` → text
- `rw-p` → data
- `[heap]`
- `[stack]`

> This verifies actual kernel memory mapping.
> 

## Things Learned:

1. Memory is **not random**
2. The OS is **not guessing**
3. The compiler is **not improvising**

There is deterministic structure:

- Text segment (instructions)
- Data segment (initialized globals)
- BSS (zero-initialized globals)
- Heap (dynamic allocation)
- Stack (function calls, locals)

Each has a **role**, a **predictable region**, and **behaviour**.

> **That predictability is exactly what makes exploitation possible.**
>