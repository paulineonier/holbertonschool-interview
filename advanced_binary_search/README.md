````
# C - Advanced Binary Search

## Description
This task implements an **Advanced Binary Search Algorithm** in C. Unlike standard binary search, this version uses **recursion** to locate the **first occurrence** of a value in a sorted array of integers containing potential duplicates.

## Prototype
```c
int advanced_binary(int *array, size_t size, int value);
````

-   `array`: Pointer to the first element of the array to search in.
    
-   `size`: The number of elements in `array`.
    
-   `value`: The value to search for.
    
-   **Return Value**: The index of the first occurrence of `value`, or `-1` if `array` is `NULL` or `value` is not present.
    

## Key Rules & Constraints

1.  **Recursion**: The search process must be fully recursive.
    
2.  **Loop Constraint**: Only one loop (`for` or `while`) is permitted per recursive call, exclusively used for printing the current subarray.
    
3.  **Subarray Output**: Before every split, the function prints the current array/subarray being searched.
    

## File Structure

-   `search_algos.h`: Header file containing prototypes.
    
-   `104-advanced_binary.c`: Source code containing `advanced_binary` and helper functions.
    

## Compilation & Execution

Compile using `gcc` with Betty standards:

Bash

```
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 104-main.c 104-advanced_binary.c -o 104-advanced
```

### Usage Example

**104-main.c**:

C

```
#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

int main(void)
{
    int array[] = {
        0, 1, 2, 5, 5, 6, 6, 7, 8, 9
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    printf("Found %d at index: %d\n\n", 8, advanced_binary(array, size, 8));
    printf("Found %d at index: %d\n\n", 5, advanced_binary(array, size, 5));
    printf("Found %d at index: %d\n", 999, advanced_binary(array, size, 999));
    return (EXIT_SUCCESS);
}
```

**Output**:

Bash

```
$ ./104-advanced
Searching in array: 0, 1, 2, 5, 5, 6, 6, 7, 8, 9
Searching in array: 6, 6, 7, 8, 9
Searching in array: 8, 9
Found 8 at index: 8

Searching in array: 0, 1, 2, 5, 5, 6, 6, 7, 8, 9
Searching in array: 0, 1, 2, 5, 5
Searching in array: 5, 5
Found 5 at index: 3

Searching in array: 0, 1, 2, 5, 5, 6, 6, 7, 8, 9
Searching in array: 6, 6, 7, 8, 9
Searching in array: 8, 9
Searching in array: 9
Found 999 at index: -1
```

## Complexity

-   **Time Complexity**: O(log⁡n)O(logn)
    
-   **Space Complexity**: O(log⁡n)O(logn) (due to call stack frame overhead from recursion)
