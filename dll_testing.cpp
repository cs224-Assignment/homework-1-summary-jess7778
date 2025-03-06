#include <cassert>
#include <iostream>
#include<stdexcept>
#include<string>
#include "doubly_linked_list.hpp"

//Test for push_front
bool DLL_test_push_front() {
    // Test 2 cases: empty and not
    // one list

    //set up
    DoublyLinkedList dll;

    //execution
    bool result1 = dll.push_front(10);
    bool result2 = dll.push_front(20);
    bool result3 = dll.push_front(30);

    //validation
    assert(result1);
    assert(result2);
    assert(result3);
    assert(dll.size() == 3);
    assert(dll.at(0) == 30);
    assert(dll.at(1) == 20);
    assert(dll.at(2) == 10);
    DLLNode *dll_head=dll.get_head();
    DLLNode *dll_tail=dll.get_tail();
    assert(dll_head->value==30);
    assert(dll_tail->prev->value==dll_head->next->value);
    assert(dll_tail->value==10);
    return true;
}

//Test for push_back
bool DLL_test_push_back() {
    // Test 3 cases: empty, length 1, and length >1
    // -only need one list, push_back three times with three assertions
    
    //set up
    DoublyLinkedList dll;

    //execution
    bool result1 = dll.push_back(10);
    bool result2 = dll.push_back(20);
    bool result3 = dll.push_back(30);

    //validation
    assert(result1);
    assert(result2);
    assert(result3);
    DLLNode *dll_head= dll.get_head();
    DLLNode *dll_tail= dll.get_tail();
    assert(dll_head->value == 10);
    assert(dll_tail->prev->value== dll_head->next->value);
    assert(dll_tail->value == 30);

    //clean up
    return true;
}

//Test for is_empty
bool DLL_test_is_empty() {
    //Test cases: empty and not
    //Two lists

    //set up
    DoublyLinkedList dll_1,dll_2;
    dll_2.push_back(10);

    //execution
    int return_test_1=dll_1.is_empty();
    int return_test_2=dll_2.is_empty();

    //validation
    assert(return_test_1);
    assert(!return_test_2);

    //clean up
    return true;
}

//Test for size
bool DLL_test_size() {
    //Test Cases: 0, 1, and more than 1
    //Three Lists

    //set up
    DoublyLinkedList dll_1,dll_2,dll_3;
    //there's 0 element in dll_1
    //there's 1 element in dll_2
    //there're 2 elements in dll_3 
    dll_2.push_back(10);
    dll_3.push_back(20);
    dll_3.push_back(30);

    //execution
    int return_test_1=dll_1.size();
    int return_test_2=dll_2.size();
    int return_test_3=dll_3.size();
    

    //validation
    assert(return_test_1 == 0);
    assert(return_test_2 == 1);
    assert(return_test_3 == 2);

    //clean up
    return true;
}

bool DLL_test_insert() {
    //Test for insert
    //Test cases: empty, size 1 front, size 1 back, size 2 middle, negative, too big
    
    //set up
    //dll_1 is empty, dll_2 has an element
    DoublyLinkedList dll_1,dll_2;
    dll_2.push_back(10);

    //execution
    //std::cout<<"The negative result is :"<<std::endl;
    bool result_negative = dll_2.insert(1, -1);
    //std::cout<<"The overload(too big) result is :"<<std::endl;
    bool return_overload = dll_2.insert(45, 45); 
    bool return_test_1 = dll_1.insert(5, 0);  
    bool return_test_2 = dll_1.insert(10, 0); 
    bool return_test_3 = dll_2.insert(0, 1);  
    bool return_test_4 = dll_1.insert(100, 1); 

    //validation
    assert(!result_negative);
    assert(!return_overload);
    assert(return_test_1);
    assert(return_test_2);
    assert(return_test_3);
    assert(return_test_4);

    //clean up
    return true;
}

//Test for at
bool DLL_test_at() {
    //test cases: negative, too big, front, back, and middle
    //one list

    //set up
    DoublyLinkedList dll;
    dll.push_back(10);
    dll.push_back(20);
    dll.push_back(30);
    int return_test_1, return_test_2, return_test_3;
    int return_test_4, return_test_5;

    //execution
    try {
        return_test_1 = dll.at(-1);
    } catch (const std::out_of_range&) {
        return_test_1 = 0;
    } catch (...) {
        std::cout << "Wrong error type" << std::endl;
        return_test_1 = -1;
    }

    try {
        return_test_2 = dll.at(500);
    } catch (const std::out_of_range&) {
        return_test_2 = 0;
    } catch (...) {
        std::cout << "Wrong error type" << std::endl;
        return_test_2 = -1;
    }

    try {
        return_test_3 = dll.at(0);
    } catch (...) {
        std::cout << "Unexpected Error" << std::endl;
        return_test_3 = -1;
    }

    try {
        return_test_4 = dll.at(1);
    } catch (...) {
        std::cout << "Unexpected Error" << std::endl;
        return_test_4 = -1;
    }

    try {
        return_test_5 = dll.at(2);
    } catch (...) {
        std::cout << "Unexpected Error" << std::endl;
        return_test_5 = -1;
    }

    //validation
    assert(!return_test_1); // Negative index should throw an error
    assert(!return_test_2); // Out-of-bounds index should throw an error
    assert(return_test_3 == 10); // Front element should be 10
    assert(return_test_4 == 20); // Middle element should be 20
    assert(return_test_5 == 30); // Back element should be 30

    //clean up
    return true;
}


//Test for search
bool DLL_test_search() {
    //Test cases: first value, middle value, last value, not found 
    //one list

    //set up    
    DoublyLinkedList dll;
    dll.push_back(10);
    dll.push_back(20);
    dll.push_back(30);

    //execution
    int return_test_1 =dll.search(10);
    int return_test_2 =dll.search(20);
    int return_test_3 =dll.search(30);
    int return_test_4 =dll.search(40);

    //validation
    assert(return_test_1 == 0);
    assert(return_test_2 == 1);
    assert(return_test_3 == 2);
    assert(return_test_4 == -1);

    //clean up
    return true;
}

//Test for remove
bool DLL_test_remove() {
    //Test cases:negative, too big, last, middle, first, only, empty
    //Single list

    //set up
    DoublyLinkedList dll;
    dll.push_back(10);
    dll.push_back(20);
    dll.push_back(30);
    dll.push_back(40);

    //execution
    //std::cout << "Remove index -1: Negative" << std::endl;
    bool negative_result = dll.remove(-1);

    //std::cout << "Remove index 5 : Too big" << std::endl;
    bool too_big_test = dll.remove(5);

    //std::cout << "Remove index 3 : Last" << std::endl;
    bool result1 = dll.remove(3);

    //std::cout << "Remove index 1 : Middle" << std::endl;
    bool result2 = dll.remove(1);

    //std::cout << "Remove index 0 : First" << std::endl;
    bool result3 = dll.remove(0);

    //std::cout << "Remove index 0 : Only " << std::endl;
    //there is only 1 element
    bool only_result = dll.remove(0); 
    
    //std::cout << "Remove index 0 : Empty" << std::endl;
    bool empty_result = dll.remove(0);


    //validation
    assert(!negative_result);
    assert(!too_big_test);
    assert(result1);
    assert(result2);
    assert(result3);
    assert(only_result); 
    assert(!empty_result);

    //clean up
    return true;   
}

//Test for remove_value
bool DLL_test_remove_value() {
    DoublyLinkedList dll;
    //Test cases: not found, last, middle, first, only, empty
    //single list

    //set up
    dll.push_front(40);
    dll.push_front(30);
    dll.push_front(20);
    dll.push_front(10);

    //execution
    //std::cout << "Beginning Remove Value" << std::endl;
    bool return_test_1 = dll.remove_value(50);
    //std::cout << "Removed nothing" << std::endl;
    bool return_test_2 = dll.remove_value(40);
    //std::cout << "Removed Last" << std::endl;
    bool return_test_3 = dll.remove_value(20);
    //std::cout << "Removed Middle" << std::endl;
    bool return_test_4 = dll.remove_value(10);
    //std::cout << "Removed First" << std::endl;
    bool return_test_5 = dll.remove_value(30);
    //std::cout << "Removed Only" << std::endl;
    bool return_test_6 = dll.remove_value(60);
    //std::cout << "Ending Remove Value" << std::endl;

    //validation 
    assert(!return_test_1);
    assert(return_test_2);
    assert(return_test_3);
    assert(return_test_4);
    assert(return_test_5);
    assert(!return_test_6);

    //clean up
    return true;

}


//Test for print and print_reverse
bool DLL_test_print() {
    //set up
    DoublyLinkedList dll;

    //execution
    dll.push_back(10);
    dll.push_back(20);
    dll.push_back(30);

    //validation
    std::cout <<"Print the list:" <<std::endl;
    std::cout << "Expected: 10 20 30" << std::endl;
    dll.print();

    //clean up
    return true;
}

bool DLL_print_reverse(){
    //set up
    DoublyLinkedList dll;

    //execution
    dll.push_back(10);
    dll.push_back(20);
    dll.push_back(30);

    //validation
    std::cout <<"Print the list from back to front:" <<std::endl;
    std::cout << "Expected: 30 20 10" << std::endl;
    dll.print_reverse();

    //clean up
    return true;
}

//main function to run all tests
int main() {
    assert(DLL_test_print());
    assert(DLL_print_reverse());
    
    std::cout<<std::endl;
    std::cout << "Starting Tests" << std::endl;
    std::string result_1 = DLL_test_push_front() ? "Passed" : "Failed";
    std::cout << "Push Front: " << result_1 << std::endl;

    std::string result_2 = DLL_test_push_back() ? "Passed" : "Failed";
    std::cout << "Push Back: " << result_2 << std::endl;

    std::string result_3 = DLL_test_is_empty() ? "Passed" : "Failed";
    std::cout << "Is Empty: " << result_3 << std::endl;

    std::string result_4 = DLL_test_size() ? "Passed" : "Failed";
    std::cout << "Size: " << result_4 << std::endl;

    std::string result_5 = DLL_test_insert() ? "Passed" : "Failed";
    std::cout << "Insert: " << result_5 << std::endl;

    std::string result_6 = DLL_test_at() ? "Passed" : "Failed";
    std::cout << "At: " << result_6 << std::endl;

    std::string result_7 = DLL_test_search() ? "Passed" : "Failed";
    std::cout << "Search: " << result_7 << std::endl;

    std::string result_8 = DLL_test_remove() ? "Passed" : "Failed";
    std::cout << "Remove: " << result_8 << std::endl;

    std::string result_9 = DLL_test_remove_value() ? "Passed" : "Failed";
    std::cout << "Remove_value: " << result_9 << std::endl;
    return 0;
    

}