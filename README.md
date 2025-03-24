## Sorting Complexity Analysis Project

## Overview
This project implements three sorting algorithms—Merge Sort, Quick Sort, and Insertion Sort—on both vectors and doubly linked lists. The performance of each sorting method is evaluated based on execution time.

## Project Structure
The project consists of the following files:

- doubly_linked_list.cpp
- doubly_linked_list.hpp
- vector_sorter.cpp
- vector_sorter.hpp
- test_sorting.cpp
- test_evaluator.cpp
- evaluator.cpp
- evaluator.hpp
- main.cpp
- evaluation_cases.txt 
- README.md

## Compilation Instructions

# 1. Compile the Project
To compile all source files:

g++ -o sorting_project main.cpp doubly_linked_list.cpp vector_sorter.cpp evaluator.cpp -std=c++11

# 2. Running Sorting Tests
To test sorting algorithms:

g++ -o test_sorting test_sorting.cpp vector_sorter.cpp doubly_linked_list.cpp -std=c++11
./test_sorting

# 3. Running Evaluator Tests
To test the evaluator:

g++ -o test_evaluator test_evaluator.cpp evaluator.cpp -std=c++11
./test_evaluator

# 4. Running Full Evaluation
To evaluate sorting performance:

./sorting_project evaluation_cases.txt

## Sorting Implementations

# VectorSorter
- Merge Sort (merge_sort): Uses a divide-and-conquer approach.
- Quick Sort (quick_sort): Uses the first element as the pivot.
- Insertion Sort (insertion_sort): Simple but inefficient for large inputs.

# DoublyLinkedList
- Merge Sort (merge_sort): Recursive merge implementation.
- Quick Sort (quick_sort): Similar to vector but adapted for linked list.
- Insertion Sort (insertion_sort): Iterative sorting of nodes.

# Evaluator
Loads sorting cases from evaluation_cases.txt
Runs each sorting method and records execution times
Outputs results in a formatted table

## Author & Credits
This project was implemented as part of a sorting complexity analysis
assignment.

- Carson Frost
- Charles Serafin
- Jessica Sun
- Joseph Mock
