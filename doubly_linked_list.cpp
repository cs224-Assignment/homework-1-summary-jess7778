#include <stdexcept>
#include <iostream>
#include "doubly_linked_list.hpp"

//Settings about the DoublyLinkedList Node
//Default Constructor
DLLNode::DLLNode() {
    value = 0;
    next = nullptr;
    prev=nullptr;
}

//Parameterized Constructor
DLLNode::DLLNode(int v) {
    value = v;
    next = nullptr;
    prev=nullptr;
}

//Parameterized Constructor
DLLNode::DLLNode(int v, DLLNode* n,DLLNode* p) {
    value=v;
    next=n;
    prev=p;
}

//Destructor
DLLNode::~DLLNode() {

}

//Default Constructor
DoublyLinkedList::DoublyLinkedList() {
    head= nullptr;
    tail= nullptr;
}
//Destructor
DoublyLinkedList::~DoublyLinkedList() {
    DLLNode* iter = head;
    while (iter) {
        DLLNode* next = iter->next;
        delete iter;
        iter = next;
    }
}

//Empty
bool DoublyLinkedList::is_empty() {
    return head == nullptr;
}

bool DoublyLinkedList::push_back(int v) {
    DLLNode* newDoublyNode = new DLLNode(v);
    if (is_empty()) {
        head = tail = newDoublyNode;
    } else {
        tail->next = newDoublyNode;
        newDoublyNode->prev = tail;
        tail = newDoublyNode;
    }
    return true;
}

bool DoublyLinkedList::push_front(int v) {
    DLLNode* newDoublyNode = new DLLNode(v);
    if (is_empty()) {
        head = tail = newDoublyNode;
    } else {
        newDoublyNode->next = head;
        head->prev = newDoublyNode;
        head = newDoublyNode;
    }
    return true;
}


bool DoublyLinkedList::insert(int v, int i) {
    if (i < 0 || i > size()) {
        return false;
    }
    if (i == 0) {
        return push_front(v);
    }
    if (i == size()) {
        return push_back(v);
    }

    DLLNode* iter = head;
    for (int count = 0; count < i - 1; count++) {
        iter = iter->next;
    }

    DLLNode* newDoublyNode = new DLLNode(v);
    newDoublyNode->next = iter->next;
    newDoublyNode->prev = iter;

    if (iter->next) {
        iter->next->prev = newDoublyNode;
    }
    iter->next = newDoublyNode;

    return true;
}

//find the node with the index i
int DoublyLinkedList::at(int i) {
    if (i < 0 || i >= size()) {
        throw std::out_of_range("Invalid Index for List");
    }
    DLLNode* iter = head;
    for (int count = 0; count < i; count++) {
        iter = iter->next;
    }
    return iter->value;
}

//find the node with the value v
int DoublyLinkedList::search(int v) {
    DLLNode* iter = head;
    int index = 0;
    while (iter) {
        if (iter->value == v) {
            return index;
        }
        iter = iter->next;
        index++;
    }
    return -1;
}

//find the size
int DoublyLinkedList::size() {
    int count = 0;
    DLLNode* iter = head;
    while (iter) {
        count++;
        iter = iter->next;
    }
    return count;
}

//remove the node with the index i
bool DoublyLinkedList::remove(int i) {
    if (is_empty() || i < 0 || i >= size()) {
        return false; 
    }

    DLLNode* target = head;


    for (int count = 0; count < i; count++) {
        target = target->next;
    }

    if (target->prev) {
        target->prev->next = target->next;
    } else {
        head = target->next; 
    }

    if (target->next) {
        target->next->prev = target->prev;
    } else {
        tail = target->prev;
    }

    delete target;
    return true;
}

//remove the node with value"v"
bool DoublyLinkedList::remove_value(int v) {
    DLLNode* iter = head;

    while (iter) {
        if (iter->value == v) {
            
            if (iter->prev) {
                iter->prev->next = iter->next;
            } else {
                //update the head if it is the "head"
                head = iter->next; 
            }
            if (iter->next) {
                iter->next->prev = iter->prev;
            } else {
                //update the tail if it is the "tail"
                tail = iter->prev;
            }

            delete iter;
            return true; 
        }
        iter = iter->next;
    }

    return false; 
}


void DoublyLinkedList::print() {
    DLLNode* iter = head;
    while (iter) {
        std::cout << iter->value << " ";
        iter = iter->next;
    }
    std::cout << std::endl;
}

void DoublyLinkedList::print_reverse() {
    DLLNode* iter = tail;
    while (iter) {
        std::cout << iter->value << " ";
        iter = iter->prev;
    }
    std::cout << std::endl;
}
