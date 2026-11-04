````
# Linear Skip - Skip List Search Algorithm

## Description
This project implements a search algorithm in C designed to optimize lookup times in a sorted singly linked list by utilizing an **express lane** (Skip List).

In a standard singly linked list, searching for a value requires linear scanning with a time complexity of $O(n)$. By adding an express lane where nodes are placed at intervals equal to the square root of the list's size ($\sqrt{n}$), the search process can skip large sections of the list, reducing the average search time complexity to $O(\sqrt{n})$.

---

## Data Structure

The `skiplist_t` structure represents a node in a singly linked list with an express lane. It is defined in `search.h`:

```c
/**
 * struct skiplist_s - Singly linked list with an express lane
 *
 * @n: Integer
 * @index: Index of the node in the list
 * @next: Pointer to the next node
 * @express: Pointer to the next node in the express lane
 *
 * Description: Singly linked list node structure with an express lane
 */
typedef struct skiplist_s
{
    int n;
    size_t index;
    struct skiplist_s *next;
    struct skiplist_s *express;
} skiplist_t;
````

## Task Overview

### 0\. Linear Skip

-   **File:** `0-linear_skip.c`
    
-   **Prototype:** `skiplist_t *linear_skip(skiplist_t *list, int value);`
    

#### Requirements:

-   `list` is a pointer to the head of the skip list to search in.
    
-   `value` is the value to search for.
    
-   Nodes in the express lane are placed at every index that is a multiple of the square root of the list size.
    
-   The list is assumed to be sorted in ascending order.
    
-   The function must return a pointer to the first node where `value` is located.
    
-   If `value` is not present or if `list` is `NULL`, the function returns `NULL`.
    
-   Every time a node value is checked (both in the express lane and linear traversal), a message must be printed.
    

## Algorithm Steps

1.  **Express Lane Traversal**:
    
    -   Traverse the list through the `express` pointers.
        
    -   For each express node, print the value checked.
        
    -   Stop when the express node's value is greater than or equal to `value`, or when the end of the express lane is reached (`NULL`).
        
2.  **Interval Boundary Resolution**:
    
    -   Identify the index interval `[prev->index, express->index]` where `value` might reside.
        
    -   If `express` reached `NULL`, traverse via `next` pointers to locate the true end of the list.
        
    -   Print the interval range: `Value found between indexes [start] and [end]`.
        
3.  **Linear Sub-Search**:
    
    -   Traverse linearly using `next` pointers from `prev` up to `express`.
        
    -   Print each inspected node value.
        
    -   Return the node matching `value`, or `NULL` if not found.
        

## Example Usage

### Test Code (`0-main.c`)

C

```
#include <stdio.h>
#include <stdlib.h>
#include "search.h"

int main(void)
{
    skiplist_t *list, *res;
    int array[] = {
        0, 1, 2, 3, 4, 7, 12, 15, 18, 19, 23, 53, 61, 62, 76, 99
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    list = create_skiplist(array, size);
    print_skiplist(list);

    res = linear_skip(list, 53);
    printf("Found %d at index: %lu\n\n", 53, res->index);
    res = linear_skip(list, 2);
    printf("Found %d at index: %lu\n\n", 2, res->index);
    res = linear_skip(list, 999);
    printf("Found %d at index: %p\n", 999, (void *) res);

    free_skiplist(list);
    return (EXIT_SUCCESS);
}
```

### Compilation

Bash

```
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-linear_skip.c skiplist/*.c -lm -o 0-linear_skip
```

### Output

Plaintext

```
List :
Index[0] = [0]
Index[1] = [1]
Index[2] = [2]
Index[3] = [3]
Index[4] = [4]
Index[5] = [7]
Index[6] = [12]
Index[7] = [15]
Index[8] = [18]
Index[9] = [19]
Index[10] = [23]
Index[11] = [53]
Index[12] = [61]
Index[13] = [62]
Index[14] = [76]
Index[15] = [99]

Express lane :
Index[0] = [0]
Index[4] = [4]
Index[8] = [18]
Index[12] = [61]

Value checked at index [4] = [4]
Value checked at index [8] = [18]
Value checked at index [12] = [61]
Value found between indexes [8] and [12]
Value checked at index [8] = [18]
Value checked at index [9] = [19]
Value checked at index [10] = [23]
Value checked at index [11] = [53]
Found 53 at index: 11

Value checked at index [4] = [4]
Value found between indexes [0] and [4]
Value checked at index [0] = [0]
Value checked at index [1] = [1]
Value checked at index [2] = [2]
Found 2 at index: 2

Value checked at index [4] = [4]
Value checked at index [8] = [18]
Value checked at index [12] = [61]
Value found between indexes [12] and [15]
Value checked at index [12] = [61]
Value checked at index [13] = [62]
Value checked at index [14] = [76]
Value checked at index [15] = [99]
Found 999 at index: (nil)
```

## Files Structure

Plaintext

```
.
├── 0-linear_skip.c     # Implementation of the linear skip search algorithm
├── search.h            # Header file with struct definitions & prototypes
└── README.md           # Project documentation
```