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
//Quick sort implementation
void DoublyLinkedList::quick_sort(DLLNode* start, DLLNode* end){
    if(start == nullptr || end == nullptr || start == tail || start == end->next){
        return;
    }
    //if(start->value <= end->value){
    //    return;
    //}
    //Node* tail = get_tail();
    DLLNode* pivot = partition(start, end);
    //std::cout << "P val: " << pivot->value << std::endl;
    quick_sort(start, pivot->prev);
    quick_sort(pivot->next, end);

}

DLLNode* DoublyLinkedList::partition(DLLNode* start, DLLNode* end){

   DLLNode* pivot = start; //Pivot iwill be the starting value
   //std::cout << "Pivot Value: " << pivot->value << std::endl;
   DLLNode* mid = end->next; // Will find the mid
   // At the end of this loop, the midpoint will be where the pivot should go,
    for(DLLNode* i = end; i != start; i = i->prev){
        if(i->value >= pivot->value){
            if(mid == nullptr){
                //std::cout << "Null" << std::endl;
                mid = end;
            }else{
                mid = mid->prev;
            }
            //mid = mid->previous;
            int temp = i->value;
            i->value = mid->value;
            mid->value = temp;
        }
    }
    if(mid == nullptr){
        //std::cout << "Null" << std::endl;
        mid = end;
        int temp = start->value;
        start->value = mid->value;
        mid->value = temp;
        return mid;
    }else{
        mid = mid->prev;
    }
   //mid = mid->previous;
   int temp = pivot->value;
   pivot->value = mid->value;
   mid->value = temp;
   
    //std::cout << "New Pivot Value: " << mid->value << std::endl;
    return mid; //Location of pivot
    
}
void DoublyLinkedList::quick_sort(){
    DLLNode* start = get_head();
    DLLNode* end = get_tail();
    quick_sort(start, end);
}
//END quick sort implementations

//Merge sort implementation
DLLNode* DoublyLinkedList::split(DLLNode * start){
    DLLNode * trail = start;
    DLLNode * ahead = start;
    while(ahead->next != nullptr && ahead->next->next != nullptr){
        ahead = ahead->next->next;
        trail = trail->next;
    }
    // Loop above will go through until ahead ptr is at end, tail is in middle
    //head is start of forst half, trial is start of second half
    DLLNode* mid = trail->next;
    // Need nto break this connection
    trail->next = nullptr;
    if(mid != nullptr){
        mid->prev = nullptr;
    }
    
    //return the pointer for the second half of the split list
    return mid;

}
DLLNode* DoublyLinkedList::merge_sort(DLLNode* head){
//Base case (list has 0 or one value(s) so is already sorted)
   if(head == nullptr || head->next == nullptr){
        return head;
   }
   //Find mid and create two halves
   //Node* mid = get_mid(head);
   DLLNode* right = split(head);
   
   DLLNode* left = head;
   
   
   //Detatch two halves
   //mid->next = nullptr;
   //right->previous = nullptr;
   //Call merge sort on the left half, left becomes a new head
   left = merge_sort(left);
   right = merge_sort(right);

   
    return merge(left, right);
}
void DoublyLinkedList::merge_sort(){
    head = merge_sort(head);
}
//Merging two already sorted lists
DLLNode* DoublyLinkedList::merge(DLLNode* first, DLLNode* second){
    //Base case, the first node is null, so nothing for second node to compre to
    if(first == nullptr){
        return second;
    }
    // Base case, the second node is null, so nothing for the first nose to compare to
    if(second == nullptr){
        return first;
    }
    if(first->value < second->value){
        first->next = merge(first->next, second);
        
        if(first->next != nullptr){
            first->next->prev = first;
        }
        first->prev = nullptr;
        return first;
    }else{
        second->next = merge(first, second->next);
        
        if(second->next != nullptr){
            second->next->prev = second;
        }
        second->prev = nullptr;
        return second;
    }
}
//End merge sort implementation
