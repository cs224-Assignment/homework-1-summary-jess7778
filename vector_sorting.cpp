#include<iostream>
#include<vector>
#include <algorithm>
#include "vector_sorter.hpp"

// Merge sort on vector of integers

// Originally left is start of vector, right is end of vector (indices)
void VectorSorter::merge_sort(std::vector<int>& vecA, int left, int right){
    // if right is greater then nothing has to be sorted
    if(left < right){
        int mid = left + (right - left) / 2;
        
        //merge sort on left sublist
        merge_sort(vecA, left, mid);
        //merge sort on right sublist
        merge_sort(vecA, mid + 1, right);

        merge(vecA, left, mid, right);
    }
}

// Merge function for merge sort

void VectorSorter::merge(std::vector<int>& vecA, int left, int mid, int right){
    // Need to get the size of both sub arrays to copy data
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    // create a sorted vector that will be copied to vecA later
    std::vector<int> leftSortedVec(leftSize);
    std::vector<int> rightSortedVec(rightSize);
    
    // Copy the data into each sorted sub array

    // Left
    for(int i = 0; i < leftSize; ++i){
        leftSortedVec[i] = vecA[left + i];
        // leftSortedVec.push_back(vecA[left + i]);
    }

    // Right
    for(int i = 0; i < rightSize; ++i){
        rightSortedVec[i] = vecA[mid + i + 1];
        // rightSortedVec.push_back(vecA[mid + i + 1]);
    } 
    // Now have two sorted subarrays

    // Compare and merge
    int i = 0; // i tracks position in the left sorted subarray
    int j = 0; // j tracks position in the right sorted subarray
    int k = left; // k tracks position in original vector (where the new sorted values need to be put)
    while(i < leftSize && j < rightSize){
        if(leftSortedVec[i] <= rightSortedVec[j]){
            vecA[k] = leftSortedVec[i];
            ++i;
        }else{
            vecA[k] = rightSortedVec[j];
            ++j;
        }
        ++k;
    }

    // Now need to copy extra elements that were not compared (now in order)
    while(i < leftSize){
        vecA[k] = leftSortedVec[i];
        ++i;
        ++k;
    }
    while(j < rightSize){
        vecA[k] = rightSortedVec[j];
        ++j;
        ++k;
    }
}

// Wrapper merge_sort function (entry point for users)
void VectorSorter::merge_sort(std::vector<int>& vec) {
    if (!vec.empty()) {
        merge_sort(vec, 0, vec.size() - 1);
    }
}

void VectorSorter::quick_sort(std::vector<int>& vec) {
    if (!vec.empty()) {
        quick_sort(vec, 0, vec.size() - 1);
    }
}

void VectorSorter::quick_sort(std::vector<int>& vec, int left, int right) {
    if (left < right) {
        int pivotIndex = partition(vec, left, right);
        quick_sort(vec, left, pivotIndex - 1);
        quick_sort(vec, pivotIndex + 1, right);
    }
}

int VectorSorter::partition(std::vector<int>& vec, int left, int right) {
    int pivot = vec[left];
    int low = left + 1;
    int high = right;

    while (low <= high) {
        while (low <= high && vec[low] <= pivot) {
            low++;
        }
        while (low <= high && vec[high] > pivot) {
            high--;
        }
        if (low < high) {
            std::swap(vec[low], vec[high]);
        }
    }
    std::swap(vec[left], vec[high]);
    return high;
}

void VectorSorter::insertion_sort(std::vector<int>& vec) {
    for (size_t i = 1; i < vec.size(); i++) {
        int key = vec[i];
        int j = i - 1;
        while (j >= 0 && vec[j] > key) {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = key;
    }
}

void print_vector(std::vector<int>& vecA){
    for(int i = 0; i < vecA.size(); ++i){
        std::cout << vecA[i] << " ";
    }
    std::cout << std::endl;
}

int main(){
    std::vector<int> vecA;
    vecA.push_back(5);
    vecA.push_back(4);
    vecA.push_back(3);
    vecA.push_back(2);
    vecA.push_back(1);

    std::vector<int> vecB;
    vecB.push_back(7);
    vecB.push_back(2);
    vecB.push_back(9);
    vecB.push_back(1);
    vecB.push_back(6);
    
    std::cout << "Before merge sort: ";
    print_vector(vecA);
    VectorSorter::merge_sort(vecA);
    std::cout << "After merge sort: ";
    print_vector(vecA);


    std::cout << "\nBefore quick sort: ";
    print_vector(vecB);

    VectorSorter::quick_sort(vecB);

    std::cout << "After quick sort: ";
    print_vector(vecB);
}
