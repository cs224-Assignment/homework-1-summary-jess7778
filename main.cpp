#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include "vector_sorter.hpp"

void print_vector(const std::vector<int>& vec) {
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::ifstream file("evaluation_cases.txt");
    if (!file) {
        std::cerr << "Error: Could not open evaluation_cases.txt" << std::endl;
        return 1;
    }

    std::vector<int> data;
    int num;

    // Read numbers from the file into the vector
    while (file >> num) {
        data.push_back(num);
    }
    file.close();

    std::cout << "Original Data:\n";
    print_vector(data);

    // Sorting and Timing
    std::vector<int> mergeVec = data, quickVec = data, insertionVec = data;

    // Merge Sort
    auto start = std::chrono::high_resolution_clock::now();
    VectorSorter::merge_sort(mergeVec);
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "\nMerge Sort:\n";
    print_vector(mergeVec);
    std::cout << "Time: " << std::chrono::duration<double, std::milli>(end - start).count() << " ms\n";

    // Quick Sort
    start = std::chrono::high_resolution_clock::now();
    VectorSorter::quick_sort(quickVec);
    end = std::chrono::high_resolution_clock::now();
    std::cout << "\nQuick Sort:\n";
    print_vector(quickVec);
    std::cout << "Time: " << std::chrono::duration<double, std::milli>(end - start).count() << " ms\n";

    // Insertion Sort
    start = std::chrono::high_resolution_clock::now();
    VectorSorter::insertion_sort(insertionVec);
    end = std::chrono::high_resolution_clock::now();
    std::cout << "\nInsertion Sort:\n";
    print_vector(insertionVec);
    std::cout << "Time: " << std::chrono::duration<double, std::milli>(end - start).count() << " ms\n";

    return 0;
}
