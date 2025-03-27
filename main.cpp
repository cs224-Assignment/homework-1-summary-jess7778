#include "evaluator.hpp"
#include <iostream>

int main() {
    try {
        Evaluator evaluator;
        
        // Ingest data from file into all the data vecs and dlls
        evaluator.Ingest();
        
        // Run evaluation and print results
        evaluator.Evaluate();
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
