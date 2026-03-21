# Day 7 — Segmentation Faults, Memory Layout & Signal Handling


## ->Topics Covered

* Segmentation faults (SIGSEGV)
* Pointer misuse and undefined behavior
* GDB debugging (run, backtrace, inspect variables)
* Virtual memory layout (stack, heap, global)
* Signal handling in C

---

## ->Tasks Performed

### Task 1 — NULL Pointer Crash (Beginner)

**File:** `segfault_demo.c`

* Demonstrated crash using NULL pointer dereference
* Used GDB to:

  * Run program
  * Identify crash location using `bt`
  * Inspect pointer value (`0x0`)

**Key Learning:**
Dereferencing a NULL pointer leads to an immediate segmentation fault because address `0x0` is invalid.

---

### Task 2 — All Crash Types Demo (Intermediate)

**File:** `all_crashes.c`

Implemented a menu-driven program to trigger multiple memory violations:

1. NULL pointer dereference
2. Wild pointer (uninitialized pointer)
3. Heap overflow
4. Use-after-free
5. Stack overflow (infinite recursion)

**Key Learning:**

* Different memory bugs behave differently
* Some crash immediately, others cause silent corruption
* These bugs are the root of many real-world vulnerabilities

---

### Task 5 — Signal Handler (Advanced)

**File:** `signal_handler.c`

* Implemented custom handler for `SIGSEGV`
* Used `signal()` to intercept crashes
* Printed diagnostic message using async-signal-safe functions

**Key Learning:**

* Signals are OS-level notifications
* Programs can intercept crashes before termination
* Used in real-world crash reporting systems

---

## ->Debugging Tools Used

### GDB Commands

* `run` → start program
* `bt` → backtrace (find crash location)
* `list` → view source code
* `print` → inspect variables

---

## -> Core Concepts Learned

### Memory Layout

* Stack → local variables, grows downward
* Heap → dynamic memory, grows upward
* Data segment → global variables

### Common Memory Errors

* NULL dereference
* Wild pointer
* Buffer/heap overflow
* Use-after-free
* Stack overflow

### Signals

* OS sends signals like `SIGSEGV` on invalid access
* Handlers can intercept and log crashes

---

## -> Key Takeaways

* Memory safety is critical in C programming
* Undefined behavior can lead to unpredictable results
* GDB is essential for debugging low-level issues
* Understanding memory layout improves problem-solving
* Signal handling enables controlled crash reporting

