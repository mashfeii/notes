## Priority Queue 
In many applications, you have to process requests/jobs in some order. To process "most important" request first, we can sort them by priority. 
However, in a dynamic situation, where requests come in overtime, we will have to maintain an ordered (sorted) sequence when new requests come in. 

A _Max-Priority Queue_ must support the following operations:
- `add (item, priority)`
- `maximum()`
- `extractMax()`
- `increaseKey(item, newPriority)`

ADT | `insert` in O(...) | `extractMax` in O (...)
--- | --- | ---
Unsorted List | $O(1)$ | $O(n)$ 
Sorted List | $O(n)$ | $O(1)$
Binary Search Tree | $O(\log n)$ | $O(\log n)$
$k$ Queues | $O(1)$ | $O(k)$
Binary Heap | $$ | $$
Binomial Heap | $$ | $$
Fibonacci Heap | $$ | $$

### Complete Binary Trees 
A complete binary tree is a binary tree where 
1. Each level, except the last one, has maximum possible number of nodes 
2. In the last level, all leaf node are aligned to the left 

## Binary Heap 
A Binary Max-Heap is complete binary tree that maintains the max-heap property: 
- `parent.key` $\geq$ `child.key` for any parent and child nodes 


