#pragma once

#include <cstddef>

// A singly linked list. Supports push, pop, and iteration.
// Tracks sum for arithmetic types. Returns average.
template<typename T>
class LinkedList {
    public:
        using value_type = T;

        // Internal node struct holding a value and pointer to the next element
        struct Node {
            T value;                    // Stored element
            Node* next;                 // Pointer to next node in the list

            // Node constructor
            Node(const T& val, Node* nxt = nullptr) : value(val), next(nxt) {}
        };

        // Constructor and destructor
        inline LinkedList() : sum(), head(nullptr), tail(nullptr), size(0) {};
        ~LinkedList();
        
        // Shallow copying disallowed
        LinkedList(const LinkedList&) = delete;
        LinkedList& operator=(const LinkedList&) = delete;
        
        // Modifier methods
        void push(const T& value);
        T pop();

        // Accesssor methods
        inline const Node* get_internal_head() const { return head; }
        
        // Query methods
        inline std::size_t get_size() const { return size; };
        inline T get_sum() const requires std::is_arithmetic_v<T> { return sum; };
        inline double get_average() const requires std::is_arithmetic_v<T>;

    private:
        T sum{};                        // Running sum for arithmetic types
        Node* head;                     // Pointer to first node
        Node* tail;                     // Pointer to last node
        std::size_t size;               // Number of elements
};

#include "LinkedList.tpp"
