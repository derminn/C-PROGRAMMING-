# Signal Handler Demo (SIGSEGV)

## Objective
Demonstrate how to intercept segmentation faults using custom signal handlers.

## Key Concept

Operating systems send signals (like SIGSEGV) when a program performs illegal operations.

By registering a handler using `signal()`, we can intercept the signal and execute custom logic.

## Implementation

- Registered handler for SIGSEGV
- Used async-signal-safe functions (`write`, `_exit`)
- Triggered crash using NULL pointer dereference

## Output

Instead of default crash:
Segmentation fault

Custom output:
[CRASH REPORTER] Caught SIGSEGV!

## Key Learning

- Signals are OS-level interrupts
- Programs can intercept and handle them
- Used in real-world crash reporting systems
