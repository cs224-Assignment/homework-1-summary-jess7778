#include "evaluator.hpp"
#include <fstream>
#include <sstream> // https://www.geeksforgeeks.org/stringstream-c-applications/
#include <chrono> // https://en.cppreference.com/w/cpp/chrono
#include <iomanip>
#include "doubly_linked_list.hpp"
#include "vector_sorter.hpp"

void Evaluator::Ingest() {
    // std::cout << "Attempting to open evaluation_cases.txt" << std::endl;
    std::ifstream file("evaluation_cases.txt");
    if (!file.is_open()) {
        std::cerr << "Failed to open evaluation_cases.txt!" << std::endl;
        throw std::runtime_error("Could not open evaluation_cases.txt");
    }
    std::cout << "Successfully opened evaluation_cases.txt" << std::endl << std::endl;

    std::string line;
    int line_count = 0;
    
    // Small dataset (read 4 lines)
    for (int i = 0; i < 4; ++i) {
        if (!std::getline(file, line)) {
            std::cerr << "Failed to read line " << line_count << std::endl;
            break;
        }
        line_count++;
        
        // std::cout << "Read line " << line_count << ": " << line << std::endl;
        
        std::istringstream iss(line);
        int num;
        
        // depending on the line, add numbers to correct data set
        switch (i) {
            case 0:
                while (iss >> num) {
                    data1_vec_1.push_back(num);
                    data1_dll_1.push_back(num);
                }
                // std::cout << "Small Dataset Vec 1 size: " << data1_vec_1.size() << std::endl;
                break;
            case 1:
                while (iss >> num) {
                    data1_vec_2.push_back(num);
                    data1_dll_2.push_back(num);
                }
                // std::cout << "Small Dataset Vec 2 size: " << data1_vec_1.size() << std::endl;
                break;
            case 2:
                while (iss >> num) {
                    data1_vec_3.push_back(num);
                    data1_dll_3.push_back(num);
                }
                // std::cout << "Small Dataset Vec 3 size: " << data1_vec_1.size() << std::endl;
                break;
            case 3:
                while (iss >> num) {
                    data1_vec_4.push_back(num);
                    data1_dll_4.push_back(num);
                }
                // std::cout << "Small Dataset Vec 4 size: " << data1_vec_1.size() << std::endl;
                break;
        }
    }

    // Skip the empty line between datasets
    std::getline(file, line);

    // Medium dataset (still 4 lines)
    for (int i = 0; i < 4; ++i) {
        std::getline(file, line);
        std::istringstream iss(line);
        int num;
        
        // depending on the line, add numbers to correct data set
        switch (i) {
            case 0:
                while (iss >> num) {
                    data2_vec_1.push_back(num);
                    data2_dll_1.push_back(num);
                }
                break;
            case 1:
                while (iss >> num) {
                    data2_vec_2.push_back(num);
                    data2_dll_2.push_back(num);
                }
                break;
            case 2:
                while (iss >> num) {
                    data2_vec_3.push_back(num);
                    data2_dll_3.push_back(num);
                }
                break;
            case 3:
                while (iss >> num) {
                    data2_vec_4.push_back(num);
                    data2_dll_4.push_back(num);
                }
                break;
        }
    }

    // Skip the empty line between datasets
    std::getline(file, line);

    // Large dataset (also 4 lines)
    for (int i = 0; i < 4; ++i) {
        std::getline(file, line);
        std::istringstream iss(line);
        int num;
        
        // depending on the line, add numbers to correct data set
        switch (i) {
            case 0:
                while (iss >> num) {
                    data3_vec_1.push_back(num);
                    data3_dll_1.push_back(num);
                }
                break;
            case 1:
                while (iss >> num) {
                    data3_vec_2.push_back(num);
                    data3_dll_2.push_back(num);
                }
                break;
            case 2:
                while (iss >> num) {
                    data3_vec_3.push_back(num);
                    data3_dll_3.push_back(num);
                }
                break;
            case 3:
                while (iss >> num) {
                    data3_vec_4.push_back(num);
                    data3_dll_4.push_back(num);
                }
                break;
        }
    }
}

// takes four vecs and four dlls with numbers loaded from ingest function, runs one specificied sort in 'sort_type', then finds the average time of sorted all four vecs and all four dlls
void Evaluator::CompareSort(
    std::vector<int>& vec_1, 
    std::vector<int>& vec_2, 
    std::vector<int>& vec_3, 
    std::vector<int>& vec_4,
    DoublyLinkedList& dll_1, 
    DoublyLinkedList& dll_2, 
    DoublyLinkedList& dll_3, 
    DoublyLinkedList& dll_4,
    float& dll_avg_time, 
    float& vec_avg_time,
    const std::string& sort_type
) {
    // we will add the time that each dataset takes to sort to this total, then later divide by 4 to get average
    float total_time_dll = 0.0;
    float total_time_vec = 0.0;
    
    // each of our 4 datasets, with 1 dll and 1 vec per, get loaded into these vectors to store them
    // this allows us to easily access each one iteratively
    // we store addresses as to not completely copy over the entire vecs or dlls
    std::vector<std::vector<int>*> vec_datasets = {&vec_1, &vec_2, &vec_3, &vec_4};
    std::vector<DoublyLinkedList*> dll_datasets = {&dll_1, &dll_2, &dll_3, &dll_4};
    
    for (size_t i = 0; i < 4; ++i) {
        try {
            // DLL Sort
            std::cout << i+1 << ": " << "Sorting DLL, ";

            // creating copy as to not sort actual data (if this is insertion sort, for example, we still want to be able to call merge sort on the data later)
            DoublyLinkedList dll_copy = *dll_datasets[i];
            
            // starting clock
            auto start_time = std::chrono::high_resolution_clock::now();

            // checking which type of sort is to be called, then calling that sort on the dll
            if (sort_type == "insertion") {
                dll_copy.insertion_sort();
            } else if (sort_type == "merge") {
                dll_copy.merge_sort();
            } else if (sort_type == "quick") {
                dll_copy.quick_sort();
            } else {
                throw std::invalid_argument("Invalid sort type: " + sort_type);
            }
            
            // ending clock
            auto end_time = std::chrono::high_resolution_clock::now();
            // finding total change in time
            std::chrono::duration<float, std::milli> duration = end_time - start_time;
            // adding time to total
            total_time_dll += duration.count();

            // Vector Sort
            std::cout << "Sorting Vec " << std::endl;

            // creating copy as to not sort actual data (if this is insertion sort, for example, we still want to be able to call merge sort on the data later)
            std::vector<int> vec_copy = *vec_datasets[i];

            // starting clock
            start_time = std::chrono::high_resolution_clock::now();
            
            // checking which type of sort is to be called, then calling that sort on the vec
            if (sort_type == "insertion") {
                VectorSorter::insertion_sort(vec_copy);
            } else if (sort_type == "merge") {
                VectorSorter::merge_sort(vec_copy);
            } else if (sort_type == "quick") {
                VectorSorter::quick_sort(vec_copy);
            } else {
                throw std::invalid_argument("Invalid sort type: " + sort_type);
            }
            
            //ending clock
            end_time = std::chrono::high_resolution_clock::now();
            // finding diff
            duration = end_time - start_time;
            // adding to total time
            total_time_vec += duration.count();
        }
        catch (const std::exception& e) {
            std::cerr << "Error sorting dataset " << i+1 << " with " << sort_type << " sort: " << e.what() << std::endl;
            throw;
        }
    }
    
    // Calculate averages
    dll_avg_time = total_time_dll / 4;
    vec_avg_time = total_time_vec / 4;

    std::cout << "-Avg Times-" << std::endl; 
    std::cout << "DLL: " << std::fixed << std::setprecision(2) << dll_avg_time << ", Vec: " << std::fixed << std::setprecision(2) << vec_avg_time << std::endl;
}

void Evaluator::InsertionComparison() {
    // Small Dataset
    std::cout << "- Small Dataset -" << std::endl;
    CompareSort(data1_vec_1, data1_vec_2, data1_vec_3, data1_vec_4,
                data1_dll_1, data1_dll_2, data1_dll_3, data1_dll_4,
                dll_insert.avgTime1, vec_insert.avgTime1, 
                "insertion");

    // std::cout << "Medium dataset sizes: " 
    // << data2_vec_1.size() << ", " 
    // << data2_vec_2.size() << ", "
    // << data2_vec_3.size() << ", "
    // << data2_vec_4.size() << std::endl;

    // Medium Dataset
    std::cout << "- Medium Dataset -" << std::endl;
    CompareSort(data2_vec_1, data2_vec_2, data2_vec_3, data2_vec_4,
                data2_dll_1, data2_dll_2, data2_dll_3, data2_dll_4,
                dll_insert.avgTime2, vec_insert.avgTime2, 
                "insertion");

    // Large Dataset
    std::cout << "- Large Dataset -" << std::endl;
    CompareSort(data3_vec_1, data3_vec_2, data3_vec_3, data3_vec_4,
                data3_dll_1, data3_dll_2, data3_dll_3, data3_dll_4,
                dll_insert.avgTime3, vec_insert.avgTime3, 
                "insertion");
}

void Evaluator::MergeComparison() {

    std::cout << "- Small Dataset -" << std::endl;
    CompareSort(data1_vec_1, data1_vec_2, data1_vec_3, data1_vec_4,
                data1_dll_1, data1_dll_2, data1_dll_3, data1_dll_4,
                dll_merge.avgTime1, vec_merge.avgTime1, 
                "merge");

    // Medium Dataset
    std::cout << "- Medium Dataset -" << std::endl;
    CompareSort(data2_vec_1, data2_vec_2, data2_vec_3, data2_vec_4,
                data2_dll_1, data2_dll_2, data2_dll_3, data2_dll_4,
                dll_merge.avgTime2, vec_merge.avgTime2, 
                "merge");

    // Large Dataset
    std::cout << "- Large Dataset -" << std::endl;
    CompareSort(data3_vec_1, data3_vec_2, data3_vec_3, data3_vec_4,
                data3_dll_1, data3_dll_2, data3_dll_3, data3_dll_4,
                dll_merge.avgTime3, vec_merge.avgTime3, 
                "merge");
}

void Evaluator::QuickComparison() {
    // Small Dataset
    std::cout << "- Small Dataset -" << std::endl;
    CompareSort(data1_vec_1, data1_vec_2, data1_vec_3, data1_vec_4,
                data1_dll_1, data1_dll_2, data1_dll_3, data1_dll_4,
                dll_quick.avgTime1, vec_quick.avgTime1, 
                "quick");

    // Medium Dataset
    std::cout << "- Medium Dataset -" << std::endl;
    CompareSort(data2_vec_1, data2_vec_2, data2_vec_3, data2_vec_4,
                data2_dll_1, data2_dll_2, data2_dll_3, data2_dll_4,
                dll_quick.avgTime2, vec_quick.avgTime2, 
                "quick");

    // Large Dataset
    std::cout << "- Large Dataset -" << std::endl;
    CompareSort(data3_vec_1, data3_vec_2, data3_vec_3, data3_vec_4,
                data3_dll_1, data3_dll_2, data3_dll_3, data3_dll_4,
                dll_quick.avgTime3, vec_quick.avgTime3, 
                "quick");
}

void Evaluator::PrintTable() {

    // Print header
    std::cout << "====================================================" << std::endl;
    std::cout << "         SORTING PERFORMANCE COMPARISON" << std::endl;
    std::cout << "====================================================" << std::endl;
    std::cout << std::left 
              << std::setw(15) << "Sort Type" 
              << std::setw(20) << "DLL Time (ms)" 
              << std::setw(20) << "Vector Time (ms)" 
              << std::endl;
    std::cout << "----------------------------------------------------" << std::endl;

    // Insertion Sort Results
    std::cout << std::left 
              << std::setw(15) << "Insertion (S)" 
              << std::setw(20) << std::fixed << std::setprecision(2) << dll_insert.avgTime1 
              << std::setw(20) << vec_insert.avgTime1 
              << std::endl;
    std::cout << std::setw(15) << "Insertion (M)" 
              << std::setw(20) << std::fixed << std::setprecision(2) << dll_insert.avgTime2 
              << std::setw(20) << vec_insert.avgTime2 
              << std::endl;
    std::cout << std::setw(15) << "Insertion (L)" 
              << std::setw(20) << std::fixed << std::setprecision(2) << dll_insert.avgTime3 
              << std::setw(20) << vec_insert.avgTime3 
              << std::endl;

    // Merge Sort Results
    std::cout << "----------------------------------------------------" << std::endl;
    std::cout << std::setw(15) << "Merge (S)" 
              << std::setw(20) << std::fixed << std::setprecision(2) << dll_merge.avgTime1 
              << std::setw(20) << vec_merge.avgTime1 
              << std::endl;
    std::cout << std::setw(15) << "Merge (M)" 
              << std::setw(20) << std::fixed << std::setprecision(2) << dll_merge.avgTime2 
              << std::setw(20) << vec_merge.avgTime2 
              << std::endl;
    std::cout << std::setw(15) << "Merge (L)" 
              << std::setw(20) << std::fixed << std::setprecision(2) << dll_merge.avgTime3 
              << std::setw(20) << vec_merge.avgTime3 
              << std::endl;

    // Quick Sort Results
    std::cout << "----------------------------------------------------" << std::endl;
    std::cout << std::setw(15) << "Quick (S)" 
              << std::setw(20) << std::fixed << std::setprecision(2) << dll_quick.avgTime1 
              << std::setw(20) << vec_quick.avgTime1 
              << std::endl;
    std::cout << std::setw(15) << "Quick (M)" 
              << std::setw(20) << std::fixed << std::setprecision(2) << dll_quick.avgTime2 
              << std::setw(20) << vec_quick.avgTime2 
              << std::endl;
    std::cout << std::setw(15) << "Quick (L)" 
              << std::setw(20) << std::fixed << std::setprecision(2) << dll_quick.avgTime3 
              << std::setw(20) << vec_quick.avgTime3 
              << std::endl;

    std::cout << "====================================================" << std::endl;
    std::cout << "Note: (S) Small, (M) Medium, (L) Large datasets" << std::endl;
}

void Evaluator::Evaluate() {
    try {
        std::cout << "=== INSERTION COMPARISON ===" << std::endl;
        try {
            InsertionComparison();
            std::cout << "=== Insertion Comparison completed successfully ===" << std::endl << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << "Exception in InsertionComparison(): " << e.what() << std::endl;
            throw;
        }

        std::cout << "=== MERGE COMPARISON ===" << std::endl;
       
        try {
            MergeComparison();
            std::cout << "=== Merge Comparison completed successfully ===" << std::endl << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << "Exception in MergeComparison(): " << e.what() << std::endl;
            throw;
        }
        std::cout << "=== QUICK COMPARISON ===" << std::endl;
        try {
            QuickComparison();
            std::cout << "=== Quick Comparison completed successfully ===" << std::endl << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << "Exception in QuickComparison(): " << e.what() << std::endl;
            throw;
        }
        PrintTable();
    }
    catch (const std::exception& e) {
        std::cerr << "Fatal error in Evaluate(): " << e.what() << std::endl;
        throw;
    }
}