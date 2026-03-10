# DAY-4 : Pointers in C

# What is a Pointer?

A pointer is a variable that stores the **memory address** of another variable.

> Instead of storing the value directly, a pointer stores **where that value is located in memory**.
> 

**Example:**

`int x = 10;
int *p = &x;`

- `x` → stores value `10`
- `&x` → gives memory address of `x`
- `p` → stores the address of `x`

**Memory Representation:**

| Variable | Address | Value |
| --- | --- | --- |
| `x` | 1000 | 10 |
| `p` | 2000 | 1000 |

---

# Pointer Syntax:

`datatype *pointer_name;`

**Example:**

`int *p;    // p stores address of an integer
           // * → indicates this variable is a pointer
           // p → pointer name`

---

# Address Operator (`&`):

Used to get the **memory address** of a variable.

`int x = 5;
printf("%p", &x);
// Output: 0x7ffd1234`

- `&x` → returns the location of `x` in memory
- `%p` → used to print memory addresses

---

# Dereferencing Operator ():

Used to **access the value** stored at a memory address.

`int x = 5;
int *p = &x;
printf("%d", *p);  // Output: 5`

- `p` → address of `x`
- `p` → value stored at that address (`5`)

You can also **modify** the original variable using a pointer:

- `p = 20; // now x = 20`

---

# Pointer Arithmetic

Pointers can move across memory using arithmetic operations.

`int arr[3] = {10, 20, 30};
int *p = arr;`

## **Memory layout:**

| Address | Value |
| --- | --- |
| 1000 | 10 |
| 1004 | 20 |
| 1008 | 30 |

## **Pointer movement:**

`p   → 1000
p+1 → 1004
p+2 → 1008`

## **Accessing elements:**

`printf("%d", *p);      // 10
printf("%d", *(p+1));  // 20
printf("%d", *(p+2));  // 30`

> ⭐ **Important Rule:** Pointer arithmetic moves by the **size of the data type**.
For `int` (4 bytes): `p+1` moves **4 bytes**.
> 

---

# Pointer vs Array:

| Array | Pointer |
| --- | --- |
| Fixed memory size | Can change address |
| `arr++` not allowed | `p++` allowed |
| Represents entire array | Points to a memory allocation |

**Array name acts like a pointer to first element:**

`arr == &arr[0]`

## **Accessing elements:**

`arr[0] == *(arr+0)
arr[1] == *(arr+1)
arr[2] == *(arr+2)`

---

## Manual `strlen()` Using Pointers

```python
#include <stdio.h>

int my_strlen(char *str) {
    int count = 0;
    while (*str != '\0') {
        count++;
        str++;
    }
    return count;
}

int main() {
    char text[] = "cyber";
    printf("Length: %d", my_strlen(text));
}
```

## **How it works:**

- `str` → points to first character
- `str` → reads the character
- `str++` → moves to next character
- Loop stops at `'\0'` (null character)

**Pointer movement through `"cyber"`:**

`str → c → y → b → e → r → \0 (stop)`

**Result:** `length = 5`

---

# Reverse Array Using Pointers:

```python
int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int *start = arr;
    int *end = arr + 4;

    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
    // Output: 5 4 3 2 1
}
```

> Two pointers move **toward each other** while swapping elements.
>