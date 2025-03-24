#include <iostream>
#include <vector>
#include "vector_sorter.hpp"

void print_vector(const std::vector<int>& vec) {
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Example test case from your provided code
    std::vector<int> vecA = {5, 4, 3, 2, 1};

    std::cout << "Before merge sort: ";
    print_vector(vecA);

    // Call merge_sort from VectorSorter
    VectorSorter::merge_sort(vecA);

    std::cout << "After merge sort: ";
    print_vector(vecA);

    return 0;
}
