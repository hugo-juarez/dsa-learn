# DSA Learn

A comprehensive collection of Data Structures and Algorithms implementations in C++ for learning and reference purposes.

## Overview

This repository contains practical implementations of fundamental data structures and algorithms, organized into separate Xcode projects. Each module demonstrates core concepts with working examples and various operations.

## Data Structures Implemented

### Linear Data Structures
- **[array-adt](array-adt/)** - Array Abstract Data Type with operations like insert, delete, search, merge, union, and duplicate finding
- **[linked-list](linked-list/)** - Singly linked list with insertion, deletion, reversal (array-based, sliding pointer, recursive), duplicate removal, and concatenation
- **[stack](stack/)** - Stack implementation with push, pop, and peek operations
- **[queue](queue/)** - Queue implementation with enqueue and dequeue operations

### Matrix Structures
- **[matrices](matrices/)** - Various matrix representations:
  - Diagonal matrices
  - Lower triangular matrices
  - Upper triangular matrices
  - Tridiagonal matrices
- **[sparse-matrix](sparse-matrix/)** - Efficient sparse matrix implementation
- **[polynomial](polynomial/)** - Polynomial representation and operations

### Tree Structures
- **[binary-tree](binary-tree/)** - Basic binary tree implementation
- **[binary-search-tree](binary-search-tree/)** - Binary Search Tree with insertion, deletion, and search operations
- **[avl-tree](avl-tree/)** - Self-balancing AVL tree implementation
- **[heap](heap/)** - Heap data structure (min-heap/max-heap)

### Algorithms
- **[sorting](sorting/)** - Common sorting algorithms implementations
- **[graph-search](graph-search/)** - Graph traversal algorithms:
  - Breadth-First Search (BFS)
  - Depth-First Search (DFS)
- **[hashing](hashing/)** - Hash table implementations with collision resolution:
  - Chaining
  - Linear probing
  - Quadratic probing

## Project Structure

Each data structure is contained in its own directory with:
- Xcode project files (`.xcodeproj`)
- Source files (`.cpp`, `.h`)
- Main file with example usage

## Building and Running

This project uses Xcode as the development environment. To run any module:

1. Navigate to the desired data structure directory
2. Open the `.xcodeproj` file in Xcode
3. Build and run the project (Cmd+R)

Example:
```bash
cd array-adt
open array-adt.xcodeproj
```

## Requirements

- macOS with Xcode installed
- C++ compiler with C++11 support or higher

## Learning Path

Recommended order for learning:

1. Start with **array-adt** to understand basic array operations
2. Move to **linked-list** to learn dynamic memory allocation
3. Study **stack** and **queue** for understanding LIFO and FIFO concepts
4. Explore **tree structures** (binary-tree → binary-search-tree → avl-tree)
5. Learn **sorting** algorithms
6. Study **hashing** techniques
7. Practice **graph-search** algorithms

## Recent Updates

- DFS search method added
- BFS search method added
- Quadratic probing hashing implemented
- Linear probing hashing implemented

## Contributing

This is a personal learning repository. Feel free to fork and use for your own learning purposes.

## License

This project is for educational purposes.
