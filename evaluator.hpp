#ifndef EVALUATOR_H
#define EVALUATOR_H

#include <vector>
#include <string>
#include "doubly_linked_list.hpp"

struct sortTimes {
    // each will be average of four sorts
    float avgTime1; // smallest dataset: four digit numbers, 100 nums each
    float avgTime2; // medium dataset: five digit numbers, 1000 nums each
    float avgTime3; // largest dataset: six digit numbers
};

class Evaluator {
public:
    void Ingest();
    void InsertionComparison();
    void MergeComparison();
    void QuickComparison();
    void PrintTable();
    void Evaluate();

    // some basic methods (basically getters), for testing
    bool data_loaded() const { return !data1_vec_1.empty(); }
    bool insertion_tested() const { return dll_insert.avgTime1 != 0; }
    bool merge_tested() const { return dll_merge.avgTime1 != 0; }
    bool quick_tested() const { return dll_quick.avgTime1 != 0; }

private:
    // all parameters just provide info to do one variation of the sort for a specific dataset
    void CompareSort(std::vector<int>& vec_1, 
        std::vector<int>& vec_2, 
        std::vector<int>& vec_3, 
        std::vector<int>& vec_4,
        DoublyLinkedList& dll_1, 
        DoublyLinkedList& dll_2, 
        DoublyLinkedList& dll_3, 
        DoublyLinkedList& dll_4,
        float& dll_avg_time, 
        float& vec_avg_time,
        const std::string& sort_type);

    // DATASETS - vec and dll will each have 12 data sets, 4 per size (small, med, large)
    // Small datasets (4-digit numbers)
    std::vector<int> data1_vec_1, data1_vec_2, data1_vec_3, data1_vec_4;
    DoublyLinkedList data1_dll_1, data1_dll_2, data1_dll_3, data1_dll_4;

    // Medium datasets (5-digit numbers)
    std::vector<int> data2_vec_1, data2_vec_2, data2_vec_3, data2_vec_4;
    DoublyLinkedList data2_dll_1, data2_dll_2, data2_dll_3, data2_dll_4;

    // Large datasets (6-digit numbers)
    std::vector<int> data3_vec_1, data3_vec_2, data3_vec_3, data3_vec_4;
    DoublyLinkedList data3_dll_1, data3_dll_2, data3_dll_3, data3_dll_4;

    // Existing sort time tracking remains the same
    sortTimes dll_insert, vec_insert;
    sortTimes dll_merge, vec_merge;
    sortTimes dll_quick, vec_quick;
};

#endif