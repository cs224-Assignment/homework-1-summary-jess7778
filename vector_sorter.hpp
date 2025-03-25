#ifndef VECTOR_SORTER_HPP
#define VECTOR_SORTER_HPP

#include <vector>
#include <iostream>

class VectorSorter {
public:
    // Public static sorting functions
    static void merge_sort(std::vector<int>& vec);
    static void quick_sort(std::vector<int>& vec);
    static void insertion_sort(std::vector<int>& vec);

private:
    // Private helper functions for Merge Sort
    static void merge_sort(std::vector<int>& vec, int left, int right);
    static void merge(std::vector<int>& vec, int left, int mid, int right);



    // Private helper functions for Quick Sort
    static void quick_sort(std::vector<int>& vec, int left, int right);
    static int partition(std::vector<int>& vec, int left, int right);
};

#endif // VECTOR_SORTER_HPP
