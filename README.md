# Algorithms

This repository hosts a diverse collection of implemented algorithms across various domains in computer science. From foundational searching and sorting techniques to advanced graph algorithms and dynamic programming, this repository provides a comprehensive resource for understanding and implementing essential algorithms.

## What's Inside

### [Searching Algorithms](./Searching%20Algorithms)
Fundamental methods for locating elements in collections.
- Linear Search – sequentially checks each element (O(n)).
- Binary Search – efficiently searches sorted data (O(log n)).

### [Sorting Algorithms](./Sorting%20Algorithms)
Classic algorithms for ordering data.
- Selection Sort – repeatedly selects the minimum element (O(n²)).
- Insertion Sort – builds a sorted list one element at a time (O(n²)).
- Count Sort – non-comparison sort using element frequency (O(n + k)).

### [Divide and Conquer](./Divide%20and%20Conquer)
Solves problems by recursively dividing them into subproblems.
- Merge Sort – stable and efficient divide-and-conquer sort (O(n log n)).
- Quick Sort – efficient in practice with average-case O(n log n).

### [Graph](./Graph)
Algorithms for traversing and processing graphs.
- [Graph Breadth First Search](./Graph/Graph%20Breadth%20First%20Search) – explores neighbors level by level.
- [Graph Depth First Search](./Graph/Graph%20Depth%20First%20Search) – explores as deep as possible before backtracking.
- [Shortest Path Algorithms](./Graph/Shortest%20Path%20Algorithms):
  - Floyd–Warshall – all-pairs shortest paths (O(n³)).
  - Bellman–Ford – handles negative weights.
  - Dijkstra – shortest path with non-negative weights (O(m + n log n)).
- [Minimum Spanning Trees](./Graph/Minimum%20Spanning%20Trees):
  - Prim's – grows MST by adding the lowest weight edge.
  - Kruskal's – builds MST by merging disjoint sets.

### [Topological Sorting](./Topological%20Sorting)
- Kahn's Algorithm – orders nodes in a directed acyclic graph (DAG).

### [Dynamic Programming](./Dynamic%20Programming)
Solves problems by combining solutions to subproblems with overlapping states.

### [Backtracking](./Backtracking)
Explores decision trees by trying all possibilities and backtracking when needed.

### [String Matching](./String%20Matching)
Efficient algorithms for searching substrings in text.
- Rabin–Karp – uses a rolling hash for multiple pattern matching.
- Knuth–Morris–Pratt (KMP) – uses prefix function for linear-time pattern search.
