2024-03-04
# Representing a (sorted) collection of keys
Consider representations of a (sorted) collection of keys:
- With arrays, search is fast, but insert and remove are is slow
- With linked lists, search is slow, but insert and remove are fast.
  (as long as we already have a direct pointer/reference)

We will now consider data structures that combine the properties of both,
leading to sufficiently fast **search**, **insert**, and **remove** operations.

## Tree Terminology
- Above the node: *Ancestors*
- Under the node: *Descends*
- *Parent, Node, Path*
- Height = length of the longest path
- Size = number of nodes

## k-art Trees
A *k-ary tree* is an ordered oriented rooted tree where each node has at most
$k$ children 

## Binary Trees
A binary tree of sine **n** either
- is an empty tree if $n = 0$
- or has a root node **u** two binary subtrees **l** and **r** of sizes $n_1$ and $n_2$ such that $n = 1 + n_1 + n_2$ 

## Array Representation of a Binary Tree
Two represent a tree in an array we need

- A way to assign positions in array to nodes in a tree
 -- use *layer numbering*, with p(root) = 0
- A way to compute position of a parent from a position of a children
 -- p(parent) = floor((p(child) - 1) / 2)
- A way to compute positions of children from a position of a parent
 -- p(left) = $ 2 \cdot \text{p(parent)} + 1$
 -- p(right) = $ 2 \cdot \text{p(parent)} + 2$

## Tree Traversal
Traversal of a tree is a way to of accessing (visiting) all nodes of a tree

- **Pre-order** traversal
 -- Visit node, traverse left subtree, travere right subtree
- **In-order** traversal
 -- Traverse left subtree, Visit node, Traverse right subtree
- **Post-order** traversal
 -- Traverse left subtree, Traverse right subtree, Visit node

## Binary Search Trees
A *binary search tree* (BST) is a binary tree that allows efficient search.

The keys in a BST satisfy a *binary search tree property*:
For any node **x** in a BST,
- if **y** is a node in the left subtree of **x**, then **y**.key $\leq$
  **x**.key
- if **y** is a node in the right subtree of **x**, then **y**.key $\geq$
  **x**.key

## Binary Search Trees Operations
- search(key) - choose w.r.t. value left or right subtree 
- add(item) - if we did not found an element -> insert
- remove(item) or remove(key)
- removeMax() and findMax(go to the right until NIL)
- removeMin() and findMin(go to the left until NIL)

### Binary Search Trees - Deletion
To delete from a binary search tree (BST):
- Search for the node to remove.
- If the node is not found - return.
- If the node is a leaf (no children) - simply remove it.
- If the node has one child
 -- remove the node
 -- attach the subtree instead of deleted node to its parent
- If the node has two children:
 -- exchange the node with a successor (or a predecessor) node
 -- recursively remove the node from its new place
