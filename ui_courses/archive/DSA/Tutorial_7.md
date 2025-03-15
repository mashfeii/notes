## Red-Black Trees: insertion
The idea for insertion is simple:
1. Insert a new *red* node using the default BST insertion
2. Fix the tree recursively raising from the new node:
  - If a current node's parent in __black__ - stop
  - If current node's parent and uncle are _red_ - recolor an go up
  - If current node's parent i red an uncle is __black__, then rotate, recolor, and go up 

## Red-Black Trees: Deletion
The idea for deletion is simple:
1. Delete a node using the default BST deletion
2. If deleted leaf node was *red*, nothing has to be adjusted.
3. Otherwise, fix the tree, recursively raising from the deleted node:
  a. If current node is *red* - stop
  b. Examine current node's sibling and nephews to perform rotation and
recoloring correspondingly


