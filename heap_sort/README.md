# Heap Sort

## Description

The goal of this project is to implement the Heap Sort algorithm to sort an array of integers in ascending order.

Heap Sort is a comparison-based sorting algorithm that uses a binary heap data structure.

In this implementation, we use the **sift-down** algorithm to build and maintain a Max Heap.

A Max Heap is a binary tree in which the value of each parent node is greater than or equal to the values of its children.

The algorithm repeatedly extracts the maximum value from the heap and places it at the end of the array until the entire array is sorted.

## Requirements

-   **Prototype:** `void heap_sort(int *array, size_t size);`
    
-   Sort an array of integers in ascending order.
    
-   Implement the Heap Sort algorithm using the sift-down approach.
    
-   Use a Max Heap.
    
-   Print the array after every swap of two elements.
    
-   Use the provided `print_array` function to display the array.
    
-   The function must not return a value.
    
-   The sorting must be performed directly on the original array (in-place).
    

## What is Heap Sort?

Heap Sort is a sorting algorithm based on a binary heap.

A binary heap is a complete binary tree, meaning that:

-   Every level is completely filled except possibly the last one.
    
-   The last level is filled from left to right.
    

In a Max Heap, the largest element is always located at the root of the tree.

For an array representation of a binary heap, the relationships between nodes are calculated using their indexes:

-   **Parent:** `(i - 1) / 2`
    
-   **Left child:** `2 * i + 1`
    
-   **Right child:** `2 * i + 2`
    

Where `i` represents the index of the current element.

## Algorithm Explanation

Heap Sort works in two main phases.

### 1\. Build the Max Heap

The first step is to transform the input array into a Max Heap.

To do this, we start from the last non-leaf node and apply the sift-down operation to each node, moving backwards towards the root.

The last non-leaf node is located at:

```
(size / 2) - 1
```

The sift-down operation ensures that the parent node is greater than or equal to its children.

If a child is greater than its parent, the two elements are swapped.

The process continues until the heap property is restored.

At the end of this phase, the largest element is located at index `0`.

### 2\. Extract elements and sort the array

Once the Max Heap has been built, the sorting phase begins.

The algorithm repeatedly performs the following operations:

1.  Swap the root element (the maximum value) with the last element of the unsorted portion of the array.
    
2.  Print the array after the swap.
    
3.  Reduce the size of the heap by one, excluding the element that has been placed in its final sorted position.
    
4.  Apply sift-down to restore the Max Heap property.
    

This process continues until only one element remains in the heap.

The resulting array is sorted in ascending order.

## What is Sift-Down?

Sift-down is the operation used to restore the Max Heap property.

It starts at a given node and compares its value with its children.

The operation follows these steps:

1.  Calculate the indexes of the left and right children.
    
2.  Find the largest value among the parent and its children.
    
3.  If one of the children is larger than the parent, swap them.
    
4.  Print the array after the swap.
    
5.  Continue the operation from the new position of the parent.
    
6.  Stop when the parent is larger than or equal to both children, or when it has no children.
    

The sift-down operation is essential because swapping elements during Heap Sort can break the Max Heap property.

## Example

Consider the following input array:

```
int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
```

### Initial array

```
19, 48, 99, 71, 13, 52, 96, 73, 86, 7
```

### After building the Max Heap

The largest element is moved to the root:

```
99, 86, 96, 73, 13, 52, 19, 48, 71, 7
```

### Sorting phase

The maximum element is moved to the end of the array.

After each swap, the array is printed.

The process continues until all elements are sorted.

### Final result

```
7, 13, 19, 48, 52, 71, 73, 86, 96, 99
```

## Time Complexity

Heap Sort has the following time complexities:

| Case | Big O Notation | Explanation |
| --- | --- | --- |
| Best case | O(n log(n)) | Building the heap and extracting elements require logarithmic adjustments across the sorting process. |
| Average case | O(n log(n)) | Each extraction requires at most logarithmic time. |
| Worst case | O(n log(n)) | The heap must be restored after each extraction, requiring up to logarithmic operations. |

The heap construction takes `O(n)` time, while the extraction phase takes `O(n log(n))` time.

Therefore, the overall time complexity is `O(n log(n))`.

### Space Complexity

Heap Sort sorts the array in-place.

It does not require additional arrays or data structures proportional to the input size.

-   **Auxiliary Space Complexity:** `O(1)` for an iterative sift-down implementation.
    

## Stability

Heap Sort is not a stable sorting algorithm.

A stable sorting algorithm preserves the relative order of elements with equal values.

Heap Sort does not guarantee this behavior because elements can be exchanged during heap construction and extraction.

## Advantages and Disadvantages

### Advantages

-   Efficient for large arrays.
    
-   Guaranteed `O(n log(n))` time complexity.
    
-   Sorts the array in-place.
    
-   Requires very little additional memory.
    

### Disadvantages

-   Not a stable sorting algorithm.
    
-   Often slower in practice than Quick Sort for typical inputs due to less favorable memory access patterns.
    
-   Requires understanding of binary heaps and tree structures.
    

## Compilation and Execution

Compile the project using:

```
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-heap_sort.c print_array.c -o 0-heap
```

Execute the program:

```
./0-heap
```

The program prints the initial array, followed by the array after each swap, and finally the sorted array.

## Files

```
.
├── 0-heap_sort.c
├── 0-main.c
├── 0-O
├── print_array.c
├── sort.h
└── README.md
```

-   `0-heap_sort.c`: Contains the Heap Sort implementation.
    
-   `0-main.c`: Contains the main function used to test the algorithm.
    
-   `0-O`: Contains the time complexity notations.
    
-   `print_array.c`: Contains the function used to print the array.
    
-   `sort.h`: Contains the function prototypes and required headers.
    
-   `README.md`: Documents the project and its implementation.
    

## Big O File

The file `0-O` must contain exactly one Big O notation per line, in the following order:

```
O(n log(n))
O(n log(n))
O(n log(n))
```

The lines correspond to:

1.  Best case.
    
2.  Average case.
    
3.  Worst case.
    

## Conclusion

Heap Sort is an efficient comparison-based sorting algorithm that uses a Max Heap to organize and sort elements.

By implementing the sift-down operation, the algorithm maintains the heap property after every swap and progressively moves the largest elements to their final positions.

Its guaranteed `O(n log(n))` time complexity and `O(1)` auxiliary space complexity make it an efficient in-place sorting algorithm.
