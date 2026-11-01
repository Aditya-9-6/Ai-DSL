# AI-DSL: Data Structures Lab Practical Solutions

This repository contains the complete C program solutions for the Data Structures Laboratory practicals, extracted and organized into individual standalone files.

---

## 📚 List of Practicals

| Practical | Program File | Description / Topic | Data Structure / Algorithm |
| :--- | :--- | :--- | :--- |
| **Practical 1** | [`practical_01_searching.c`](./practical_01_searching.c) | Search student roll numbers who attended training (Random & Sorted) | Linear Search & Binary Search |
| **Practical 2** | [`practical_02_sorting.c`](./practical_02_sorting.c) | Sort first-year percentages and display top 5 scores | Selection Sort & Bubble Sort |
| **Practical 3** | [`practical_03_hashing.c`](./practical_03_hashing.c) | Telephone book database with client lookups and collision handling | Hash Table (Linear Probing, Quadratic Probing, Double Hashing) |
| **Practical 4** | [`practical_04_sets_linkedlist.c`](./practical_04_sets_linkedlist.c) | Student sets for Ice-cream preferences (Vanilla & Butterscotch) | Singly Linked List (Intersection, Symmetric Difference, Complement) |
| **Practical 5** | [`practical_05_cinemax_theater.c`](./practical_05_cinemax_theater.c) | Cinemax theater ticket booking system (10 rows × 7 seats) | Doubly Linked List (Head Pointers per Row) |
| **Practical 6** | [`practical_06_stack_parentheses.c`](./practical_06_stack_parentheses.c) | Check whether a delimiter expression `()`, `{}`, `[]` is well-parenthesized | Stack (Array implementation) |
| **Practical 7** | [`practical_07_job_queue.c`](./practical_07_job_queue.c) | Operating system non-priority job queue simulation | Linear Queue (FIFO) |
| **Practical 8** | [`practical_08_bst_dictionary.c`](./practical_08_bst_dictionary.c) | Dictionary with keyword insert, delete, search, update & display | Binary Search Tree (BST) |
| **Practical 9** | [`practical_09_flight_graph.c`](./practical_09_flight_graph.c) | City flight paths and network connectivity analysis | Graph (Adjacency Matrix & DFS Traversal) |

---

## 🛠️ How to Compile & Run

### Using GCC (Linux / macOS / Windows MinGW)

1. **Compile any practical:**
   ```bash
   gcc practical_01_searching.c -o practical_01
   ```

2. **Execute:**
   ```bash
   # Linux / macOS:
   ./practical_01

   # Windows:
   practical_01.exe
   ```

---

## 📋 Detailed Practical Aims

### Practical 1: Searching Techniques
- **AIM**: Menu-based program:
  - a) Store roll numbers of students in an array who attended a training program in random order. Function to search using **Linear Search**.
  - b) Store roll numbers of students in sorted order. Function to search using **Binary Search**.

### Practical 2: Sorting Techniques
- **AIM**: Store the first-year percentage of students in an array. Sort floating-point numbers in ascending order using **Selection Sort** and **Bubble Sort**, and display the top 5 scores in descending order.

### Practical 3: Hashing & Collision Resolution
- **AIM**: Telephone book database of $N$ clients. Hash table implementation to quickly look up phone numbers using:
  - Linear Probing
  - Quadratic Probing
  - Double Hashing

### Practical 4: Set Operations using Linked List
- **AIM**: For a class where Set A likes Vanilla ice-cream and Set B likes Butterscotch ice-cream, use linked lists to compute and display:
  - a) Students who like both vanilla and butterscotch (Intersection)
  - b) Students who like either vanilla or butterscotch but not both (Symmetric Difference)
  - c) Number of students who like neither flavor

### Practical 5: Doubly Linked List (Cinemax Booking System)
- **AIM**: Implement Cinemax theater ticket booking with 10 rows and 7 seats each. Maintain doubly linked lists of free seats per row with initial random bookings:
  - a) Display available seats
  - b) Book seats
  - c) Cancel bookings

### Practical 6: Stack (Well-Parenthesized Expression)
- **AIM**: Use a stack to check whether a given mathematical/programming expression with delimiters `()`, `{}`, `[]` is well-parenthesized.

### Practical 7: Queue Simulation (Job Queue)
- **AIM**: Simulate an operating system FIFO job queue:
  - Add job
  - Delete/process job
  - Display waiting queue

### Practical 8: Binary Search Tree (Dictionary)
- **AIM**: Dictionary storing keywords and meanings using BST:
  - Add new keyword
  - Delete keyword
  - Update meaning
  - Search keyword (with comparison count)
  - Display in ascending/descending order
  - Find maximum comparisons required for successful and unsuccessful search

### Practical 9: Graph Representation & Connectivity
- **AIM**: Represent flight paths between cities with edge costs (time/fuel). Represent graph using an Adjacency Matrix and check whether the flight network is connected using Depth First Search (DFS).
