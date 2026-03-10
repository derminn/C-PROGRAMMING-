# DAY-5 :  Double Pointers, Swap, Void Pointers & Two-Pointer Technique

# Pointer to Pointer (Double Pointer) :

A double pointer stores the **address of another pointer**.

```python
int x = 10;
int *p = &x;
int **pp = &p;
```

Memory Structure :

```python
x  = 10
p  = address of x
pp = address of p
```

Accessing Values :

| Expression | Gives |
| --- | --- |
| `p` | address of `x` |
| `*p` | value of `x` |
| `pp` | address of `p` |
| `*pp` | address of `x` |
| `**pp` | value of `x` |

Example program: 

```python
#include <stdio.h>
int main() {
    int x = 10;
    int *p = &x;
    int **pp = &p;

    printf("Value of x = %d\n", x);
    printf("Using pointer = %d\n", *p);
    printf("Using double pointer = %d\n", **pp);
    return 0;
}
```

Output:

```python
Value of x = 10
Using pointer = 10
Using double pointer = 10
```

# Swap Variables Using Pointers (Call by Reference) :

Normally, variables passed to a function are passed **by value** — the original is not changed.

Using pointers → **original variables can be modified**. This is called **Call by Reference**.

```python
#include <stdio.h>

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 5;
    int y = 10;
    swap(&x, &y);
    printf("x = %d  y = %d", x, y);
    return 0;
}
```

**Output:** `x = 20, y = 5`

### **How it works:**

- `swap(&x, &y)` → `a` = address of `x`, `b` = address of `y`
- Inside function: `a` = value of `x`, `b` = value of `y`
- The function modifies the **actual variables**

# Void Pointer:

A void pointer is a **generic pointer** that can store the address of any data type.

```python
void *ptr;
```

Example: 

```python
#include <stdio.h>

int main() {
    int x = 5;
    void *ptr = &x;
    printf("%d", *(int*)ptr);  // must typecast first
    return 0;
}
```

**Example use cases:**

- `malloc()` returns a `void*`
- Generic data structures
- Library functions

# Two Pointer Technique :

Uses **two pointers** to traverse an array or string efficiently.

```python
left  → start
right → end
```

Both pointers **move depending on the condition**.

**Common use cases:**

- Reversing arrays
- Palindrome checking
- Searching sorted arrays