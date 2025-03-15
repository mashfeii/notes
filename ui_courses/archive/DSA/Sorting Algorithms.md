# 2024-05-20 00:04

## Quadratic Algorithms

- Stable
- In-place
- $O(n^2)$ - worst case

### Bubble Sort $O(n^2) \rightarrow O(n^2) \rightarrow O(n)$

Comparing consecutive items, if they are in the wrong order, then swap them.

### Insertion Sort $O(n)$ - best case

Goes from left to right and validate correct position of each item (should it be
more on the left or should stay still).

### Selection Sort $O(n^2)$ - best case

Takes one element as "current minimum" and goes through other values to find
smaller item, if it exists, swap them.

## Logarithmic Algorithms

### Merge Sort $O(n\log{n}) \rightarrow O(n\log{n})$

- Stable
- Usually recursive algorithm
- Divide-and-Conquer algorithm
- Uses extra space for temporary arrays: $O(n)$

Divides each array twice on each step. Then merge singleton arrays into
temporary sorted arrays. Example in the number of items: 8 → 4 → 2 → 1, on
last step we have 8 singleton arrays, then we merge them into temporary sorted
arrays: 8 → 4 (2 elements in one array) → 2 (4 elements) → 1 (sorted array).

### Quick Sort $O(n^2) \rightarrow O(n\log{n})$

- Stable (but partition can be unstable)
- Recursive algorithm
- Divide-And-Conquer method

Takes some value as pivot, then it splits array on the items that are smaller or
equal and on that are larger. Then each part of the array that is left from
pivot and right are sorted recursively with pivot element again.


### Heap Sort $O(n\log{n}) \rightarrow O(n\log{n})$

Here, we take an unsorted array, then call `make-max-heap`, after on each step we change the root element with the last element in the heap (root element goes to the end of the sorted array), after swap we call `hipify` and repeat such operation till the array is fully sorted.
## Linear Algorithms

### Counting Sort $O(n + k)$

We create a temporary array for $k$ elements, after we count how many times each of these items are represented in initial collection, which takes $O(n)$, also, we handle an accumulator (where each item's counter equals itself + previous counter) for inserting numbers in the final array.

### Radix Sort $\Theta(d(n + k))$

Here, we split each number on the sequence of digits and sort each part using counting sort

### Bucket Sort (expected $\Theta(n)$, but depends on chosen comparison sorting algorithm)

We create a sequence of buckets (closely related elements), after this we sort each bucket using comparison sort and merge them all together.

## Graph Sorting Algorithm

### Topological Sort $O(|V| + |E|)$ - time, $O(|V| + |E|)$ - space

Applications:

- List of dependencies
- Task scheduling and project management
- Course scheduling
- Order of compilations in software build systems

__Graph should be directed and acyclic.__
We start from the vertex that has __no__ outgoing edges (has no dependencies). 