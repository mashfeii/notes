# 2024-05-19 23:46

## Minimum Spanning Tree
### Prim-Jarnik Algorithm $O(|E| + |V|\log{|V|}) \rightarrow O(|E|\log{|V|})$

- A **greedy** algorithm for Minimum-Spanning Tree
- Adds **one vertex** to the tree at each iteration
- Maintains a priority queue of **vertices**
- Works in $O(|V|\log{|V|} + |E|)$ for Fibonacci heap and $(|V| + |E|)\log{|V|} = |E|\log{|V|}$ for binary heap.

### Kruskal's algorithm $O(|E|\log{|V|})$

First, we sort all the edges. Then we divide all vertices on the singleton trees. On each iteration we take the shortest edge and `union` it with corresponding tree

## Shortest Paths (from single source)
### Dijkstra's Algorithm $(|E| + |V|\log{|V|}) \rightarrow O(|E|\log{|V|})$

- A **greedy** algorithm for _Single-Source Shortest Paths_
- Adds **one vertex** to the _Shortest Paths Tree_ at each iteration
- Connects the new vertex using an _edge that makes the shortest path_
- Maintains a _priority queue of_ **vertices**

Applications:

- Network packet routing
- Flight reservations
- Driving directions
- Planning

Variations:

- Find the shortest path from vertex _u_ to vertex _v_
- **Single-source the shortest paths**
  Find the shortest paths from vertex _u_ to all other vertices
- **Single-destination the shortest paths**
  Find the shortest paths from all vertices to vertex _u_
- **All-pair the shortest paths**
  Find the shortest path for any pair of vertices _u_ and _v_

> [!NOTE]- Relaxation
> Relaxation is the process of vertex's weight updating

### Belman-Ford Algorithm

Algorithm finds the shortest paths with at most $|V| - 1$ edges, then iterates
through edges one more time, if there are shorter paths, then it means there are
negative-weighted cycles!


## Shortest paths for any pair of vertices
### Floyd-Warshall algorithm $O(V^3)$

Algorithm accept adjacency matrix and process the tripple cycle for finding the
shortest paths for any pair of vertices
For each vertex we create a table of distances to each vertices. Initialize each path from node to itself as 0. Loop for the edges and insert their weights into the table. Then move to the nested triple loop and look for the condition `distance[i][j] > distance[i][k] + distance[k][j]`, if it contradicts, we change the distance in table.