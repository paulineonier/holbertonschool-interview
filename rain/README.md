# Rain

## Description

The goal of this project is to calculate how much rainwater can be retained between walls after it rains.

We are given a list of non-negative integers representing the heights of walls. Each wall has a unit width of 1.

The objective is to determine the total amount of water that can be trapped between these walls.

The function must return an integer representing the total volume of retained rainwater.

## Requirements

-   **Prototype:** `def rain(walls)`
    
-   `walls` is a list of non-negative integers.
    
-   Each wall has a width of 1.
    
-   The function returns an integer representing the total amount of retained water.
    
-   The ends of the list are not considered walls, so they cannot retain water.
    
-   If the list is empty, the function must return `0`.
    

## Algorithm Explanation

The amount of water trapped at a given position depends on the height of the tallest wall on its left and the tallest wall on its right.

For each position in the list, we calculate:

1.  The maximum wall height to the left of the current position.
    
2.  The maximum wall height to the right of the current position.
    
3.  The minimum between these two maximum heights.
    
4.  The difference between that minimum height and the current wall height.
    

The amount of water trapped at each position is calculated using the following formula:

```
water = min(max_left, max_right) - walls[i]
```

If the result is positive, it represents the amount of water retained at that position. Otherwise, no water is retained.

The total amount of trapped water is the sum of the water retained at every position.

## Example

Consider the following list:

```
walls = [0, 1, 0, 2, 0, 3, 0, 4]
```

The water retained at each position is:

```
Position:     0  1  2  3  4  5  6  7
Wall height:  0  1  0  2  0  3  0  4
Water:        0  0  1  0  2  0  3  0
```

The total amount of retained water is:

```
1 + 2 + 3 = 6
```

Expected output:

```
6
```

Another example:

```
walls = [2, 0, 0, 4, 0, 0, 1, 0]
```

The total amount of retained water is:

```
6
```

## Edge Cases

The function must correctly handle:

-   An empty list: `[]` returns `0`.
    
-   A list containing only one wall: no water can be retained.
    
-   A list containing only two walls: no water can be retained.
    
-   Walls with the same height.
    
-   Walls arranged in increasing or decreasing order.
    
-   Lists where no water can be trapped.
    
-   Lists containing zero-height walls.
    

## Complexity

Using an approach that calculates the maximum heights to the left and right of each position:

-   **Time Complexity:** `O(n)` if the maximum heights are precomputed in linear passes.
    
-   **Space Complexity:** `O(n)` if additional arrays are used to store these maximum heights.
    

Where `n` represents the number of walls in the input list.

## Testing

The function can be tested using the following cases:

| Input | Expected output |
| --- | --- |
| [] | 0 |
| [0] | 0 |
| [1, 2] | 0 |
| [0, 1, 0, 2, 0, 3, 0, 4] | 6 |
| [2, 0, 0, 4, 0, 0, 1, 0] | 6 |
| [3, 3, 3, 3] | 0 |
| [1, 2, 3, 4] | 0 |
| [4, 3, 2, 1] | 0 |
| [5, 0, 5] | 5 |

## Usage

Example of execution:

```
$ ./0-main.py
6
6
```