#include <iostream>
#include <fstream>
#include <vector>
#include "doubly_linked_list.hpp"
#include "vector_sorter.hpp"

// Function to print a vector
void print_vector(const std::vector<int>& vec) {
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

// Function to print a doubly linked list
void print_list(DoublyLinkedList& list) {
    list.print();
    std::cout << std::endl;
}

// Function to load numbers from a file into a vector
bool load_numbers(const std::string& filename, std::vector<int>& numbers) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Could not open " << filename << std::endl;
        return false;
    }

    int num;
    while (file >> num) {
        numbers.push_back(num);
    }
    file.close();
    return true;
}

int main() {
    std::vector<int> numbers;

    // Load numbers from evaluation_cases.txt
    if (!load_numbers("evaluation_cases.txt", numbers)) {
        return 1; // Exit if file loading fails
    }

    std::cout << "Loaded " << numbers.size() << " numbers from evaluation_cases.txt\n";

    // =====================
    // Testing Vector Sorting
    // =====================
    std::vector<int> vecA = numbers;

    std::cout << "\nBefore Merge Sort (Vector): ";
    print_vector(vecA);

    // Call merge_sort from VectorSorter
    VectorSorter::merge_sort(vecA);

    std::cout << "After Merge Sort (Vector): ";
    print_vector(vecA);


    // =====================
    // Testing DoublyLinkedList Sorting
    // =====================
    DoublyLinkedList list;

    // Insert numbers into the doubly linked list
    for (int num : numbers) {
        list.push_back(num);
    }

    std::cout << "\nBefore Merge Sort (DoublyLinkedList): ";
    print_list(list);

    // Merge Sort on DoublyLinkedList
    DoublyLinkedList mergeList = list;
    mergeList.merge_sort();
    std::cout << "After Merge Sort (DoublyLinkedList): ";
    print_list(mergeList);

    return 0;
}
