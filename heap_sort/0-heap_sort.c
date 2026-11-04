#include "sort.h"

/**
 * sift_down - Restores the Max Heap property
 * @array: Array of integers
 * @heap_size: Current size of the heap
 * @root: Index of the current parent
 * @array_size: Original size of the array
 */
static void sift_down(int *array, size_t heap_size,
                      size_t root, size_t array_size)
{
    size_t largest;
    size_t left;
    size_t right;
    int temp;

    while (1)
    {
        largest = root;
        left = 2 * root + 1;
        right = 2 * root + 2;

        if (left < heap_size && array[left] > array[largest])
            largest = left;

        if (right < heap_size && array[right] > array[largest])
            largest = right;

        if (largest == root)
            break;

        temp = array[root];
        array[root] = array[largest];
        array[largest] = temp;

        print_array(array, array_size);

        root = largest;
    }
}

/**
 * heap_sort - Sorts an array of integers in ascending order
 * using the Heap sort algorithm
 * @array: Array of integers
 * @size: Number of elements in the array
 */
void heap_sort(int *array, size_t size)
{
    size_t start;
    size_t end;
    int temp;

    if (array == NULL || size < 2)
        return;

    start = size / 2;

    while (start > 0)
    {
        start--;
        sift_down(array, size, start, size);
    }

    end = size;

    while (end > 1)
    {
        end--;

        temp = array[0];
        array[0] = array[end];
        array[end] = temp;

        print_array(array, size);

        sift_down(array, end, 0, size);
    }
}
