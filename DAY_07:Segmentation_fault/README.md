# Day 7 — Segmentation Faults, Memory Layout & Signal Handling

## Topics covered

* Segmentation faults (SIGSEGV)
* Pointer misuse and undefined behavior
* GDB debugging (run, backtrace, inspect variables)
* Virtual memory layout (stack, heap, global)
* Signal handling in C

---

## Tasks Performed

### Task 1 — NULL Pointer Crash (Beginner)

**File:** `segfault_demo.c`

* Demonstrated segmentation fault using NULL pointer dereference
* Debugged using GDB:

  * `run` to execute program
  * `bt` to locate crash
  * `print` to inspect pointer value (`0x0`)

**Key Learning:**
Dereferencing a NULL pointer results in an immediate crash because it accesses invalid memory (address `0x0`).

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

* Memory bugs behave differently depending on context
* Some cause immediate crashes, others silently corrupt memory
* These issues are common sources of real-world vulnerabilities

---

### Task 3 — Signal Handler (Advanced)

**File:** `signal_handler.c`

* Implemented a custom handler for `SIGSEGV`
* Used `signal()` to intercept crashes
* Printed diagnostic message using async-signal-safe functions (`write`, `_exit`)

**Key Learning:**

* Signals are OS-level notifications for abnormal events
* Programs can intercept and handle crashes before termination
* This technique is used in production crash reporting systems

---

## Debugging Tools Used

### GDB Commands

* `run` → execute the program
* `bt` → show backtrace (crash location)
* `list` → view source code
* `print` → inspect variable values

---

## Core Concepts Learned

### Memory Layout

* **Stack** → stores local variables, grows downward
* **Heap** → dynamic memory allocation, grows upward
* **Data Segment** → stores global variables

### Common Memory Errors

* NULL pointer dereference
* Wild pointer access
* Heap/Buffer overflow
* Use-after-free
* Stack overflow

### Signals

* OS sends signals like `SIGSEGV` on invalid memory access
* Signal handlers allow controlled crash handling and logging

---

## Key Takeaways

* Memory safety is critical in C programming
* Undefined behavior leads to unpredictable results
* GDB is essential for low-level debugging
* Understanding memory layout improves debugging skills
* Signal handling enables controlled and informative crash reporting

##
