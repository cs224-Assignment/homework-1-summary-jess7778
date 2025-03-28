#include "evaluator.hpp"
#include <iostream>

void run_test(const char* name, bool (*test_func)(), int& success_count) {
    std::cout << "[TEST] " << name << "..." << std::endl;
    if (test_func()) {
        std::cout << "---PASS---\n" << std::endl;
        success_count++;
    } else {
        std::cout << "---FAIL---\n" << std::endl;
    }
    std::cout << std::endl;
}


bool test_ingest() {
    Evaluator eval;
    eval.Ingest();
    return true;  // Assume success if no exception
}

bool test_sorts() {
    Evaluator eval;
    eval.Ingest();
    
    // Test each comparison doesn't crash
    eval.InsertionComparison();
    eval.MergeComparison();
    eval.QuickComparison();
    
    return true;
}

bool test_full_evaluation() {
    Evaluator eval;
    eval.Ingest();
    eval.Evaluate();
    std::cout << std::endl;
    return true;
}

int main() {
    int success_count = 0;
    int test_count = 0;
    std::cout << "\n=== EVALUATOR TESTS ===\n";
    
    run_test("Data Loading", test_ingest, success_count);
    test_count++;
    run_test("Sorts", test_sorts, success_count);
    test_count++;
    run_test("Complete Evaluation", test_full_evaluation, success_count);
    test_count++;

    std::cout << success_count << "/" << test_count << " Tests Passed." << std::endl;

    std::cout << "==========================\n";
    return 0;
}