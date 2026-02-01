# Cpp-Data-Structures-Library
# C++ Data Structures & Algorithms (Academic Implementation)

## 🎓 About This Repository
This repository contains my **academic implementations** of core data structures and algorithms, developed during my undergraduate studies.

The primary goal of these projects was not to create a replacement for the C++ Standard Template Library (STL), but to **reverse-engineer and understand the internal mechanics** of data storage, manual memory management, and pointer arithmetic.

> **Note:** These implementations are strictly for educational purposes and demonstrate "from-scratch" logic without relying on high-level abstractions.

## 📂 What I Implemented

### 1. Dynamic Array List (Vector Logic)
Recreating the logic behind `std::vector` to understand dynamic memory allocation.
* **File:** `DynamicArrayList.cpp` (originally `PreciseSizedArrayList`)
* **Core Concepts:**
    * Manual heap allocation with `new` and `delete`.
    * Dynamic resizing strategies (capacity management).
    * Preventing memory leaks in destructors.

### 2. Binary Tree (Recursive Structures)
A node-based tree structure implementation.
* **File:** `BinaryTree.cpp`
* **Core Concepts:**
    * Deep recursion for traversals (In-order, Pre-order).
    * Pointer manipulation for node insertion/deletion.
    * Memory cleanup using recursive destructors.


### 3. Hash Table (Collision Handling)
An implementation of a Hash Map supporting multiple collision resolution strategies.
* **File:** `HashTable.cpp`
* **Core Concepts:**
    * **Separate Chaining:** Using linked lists (buckets) to handle collisions.
    * **Open Addressing:** Implementing Linear and Quadratic Probing.
    * Prime number based resizing for load factor optimization.


### 4. Numerical Analysis: Lagrange Interpolation
* **File:** `LagrangeInterpolation.cpp`
* **Core Concepts:** Implementing polynomial interpolation algorithms for numerical data analysis.

## 🛠️ Technical Focus
These projects were built to master the following C++ fundamentals:
* **Memory Safety:** Writing custom destructors (`~ClassName`) to ensure no memory leaks occur.
* **Pointers & References:** Direct manipulation of memory addresses.
* **Algorithmic Complexity:** Analyzing Big-O performance of insertion and search operations.

## 🚀 How to Compile & Run
Since these are standalone implementations with test runners, you can compile them using `g++`:

```bash
# Compile the Dynamic Array implementation
g++ DynamicArrayList.cpp test_runner.cpp -o array_test

# Run the executable
./array_test
