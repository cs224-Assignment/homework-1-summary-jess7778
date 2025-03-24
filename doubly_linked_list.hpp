#ifndef DOUBLY_LINKED_LIST_HPP
#define DOUBLY_LINKED_LIST_HPP

//DLLNode
class DLLNode {
    public:
        int value;
        DLLNode* next;
        DLLNode* prev;
        DLLNode();
        DLLNode(int v);
        DLLNode(int v, DLLNode* n,DLLNode* p);
        ~DLLNode();

};

//DoublyLinkedList
class DoublyLinkedList {
    private: 
        DLLNode* head;
        DLLNode* tail;

    public:
        DoublyLinkedList();
        ~DoublyLinkedList();
        bool push_back(int v);
        bool push_front(int v);
        bool insert(int v, int i);
        int at(int i);
        int search(int v);
        bool is_empty();
        int size();
        bool remove(int i);
        bool remove_value(int v);
        void print();
        void quick_sort(DLLNode* start, DLLNode* end);
        void quick_sort();
        DLLNode* partition(DLLNode* start, DLLNode* end);
        DLLNode* merge(DLLNode* first, DLLNode* second);
        void merge_sort();
        DLLNode* merge_sort(DLLNode* head);
        DLLNode* split(DLLNode * start);
        DLLNode* get_head() { return head; }
        DLLNode* get_tail(){return tail;}
        void print_reverse();
};

#endif