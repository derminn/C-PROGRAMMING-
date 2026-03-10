# DAY-1 : What is ELF? How C Becomes a Process

## What is ELF??

ELF (Executable and Linkable Format) is a file format used on Linux/Unix systems to store:

- Executable programs
- Object files
- Shared libraries

### ELF File Types :

| Type | Extension | Description |
| --- | --- | --- |
| Executable | `a.out` / no ext | Ready to run |
| Object file | `.o` | Compiled but not linked |
| Shared library | `.so` | Like `.dll` on Windows |
| Core dump | `core` | Crash memory snapshot |

### ELF Structure :

┌─────────────────────────────────────────────────┐
│ ELF Header       → File type, architecture info │
│ Program Headers  → How to load into memory      │
│   .text          → Your actual code             │
│   .data          → Initialized variables        │
│   .bss           → Uninitialized variables      │
│ Section Headers  → Map of all sections          │
└─────────────────────────────────────────────────┘

 

### Key sections :

| # | Section | Contains |
| --- | --- | --- |
| 1 | `.text` | Compiled code / functions |
| 2 | `.data` | Global variables with values |
| 3 | `.bss` | Global variables without values |
| 4 | `.rodata` | Constants, string literals |
| 5 | `.heap` | Dynamic memory (malloc) |
| 6 | `.stack` | Local variables, function calls |

### How It Actually Works:

**Most people think:** `Code → Compiler → Magic → Program runs`

**What actually happens:**

Code → Preprocessor → Compiler → Assembler → Linker
↓
Runs ← OS loads it ← ELF file ←──────────┘