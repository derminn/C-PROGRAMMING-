# DAY-3 :  Stack Frames, Return Address & GDB

# What is the Stack?

The stack is a memory region used by a program to manage **function calls and local variables**.

## **Key Properties:**

- Stores local variables
- Stores function parameters
- Stores return addresses
- Works in **LIFO** (Last In First Out) order
- Grows **downward** in memory

---

# What is a Stack Frame?

A stack frame is the **portion of the stack allocated for a single function call**.

Every function call creates a new stack frame. Each frame stores:

- Return addresses
- Saved base pointer (RBP)
- Local variables

```python
┌──────────────────┐  ← Higher Address
│  Return Address  │
│  Saved RBP       │
│  Local Variables │
└──────────────────┘  ← Lower Address
```

---

# Function Call Example:

```python
int main() {
    func1();
}

void func1() {
    func2();
}
```

**Execution order:** `main → func1 → func2`

## **Stack representation:**

```python
Top of Stack
────────────
func2 frame
func1 frame
main frame
────────────
Bottom
```

> The **latest function call** is always on top of the stack.
> 

---

# Return Address

The return address is the memory location where the program should continue after a function finishes execution.

## **Example:**

```python
func1();
printf("done");  // ← CPU stores address of THIS line on stack
```

- When `func1()` is called → CPU stores address of `printf("done")` on the stack
- When function finishes → CPU jumps back to that address

---

# Important CPU Registers

| Register | Name | Purpose |
| --- | --- | --- |
| `RSP` | Stack Pointer | Points to top of the stack |
| `RBP` | Base Pointer | Marks start of current stack frame |
| `RIP` | Instruction Pointer | Contains address of next instruction to execute |

> **Controlling RIP = Controlling program execution**
> 

---

## Buffer Overflow Concept

```python
void vuln() {
    char buffer[16];
    gets(buffer);  // ⚠️ does NOT check input size
}
```

**Problem:** `gets()` does not check input size.

If user enters more than 16 characters → memory gets overwritten.

**Example input:** `AAAAAAAAAAAAAAAA` (more than 16 A's)

## **Memory becomes:**

```python
┌─────────────────────────────────┐  ← Higher Address
│  Return Address ← OVERWRITTEN  │
│  Saved RBP      ← OVERWRITTEN  │
│  Buffer[16]                     │
└─────────────────────────────────┘  ← Lower Address
```

---

# Why Overwritten Return Address is Dangerous

- Return address **decides** where program execution continues
- If an attacker overwrites it → **program jumps to attacker-controlled location**

---

# GDB (GNU Debugger)

A tool used to **inspect and control a running program**.

**Used for:**

- Debugging crashes
- Analyzing memory
- Reverse engineering
- Vulnerability research

## **Important GDB Commands:**

| Command | Action |
| --- | --- |
| `gdb ./program` | Start debugger |
| `break func2` | Set breakpoint |
| `run` | Run program |
| `bt` | View call stack (backtrace) |
| `info registers` | Show RSP, RBP, RIP |
| `x/20x $rsp` | Inspect 20 hex values from stack pointer |

## **`x/20x $rsp` meaning:**

- `x` → examine memory
- `20` → number of values
- `x` → hexadecimal format
- `$rsp` → start from stack pointer