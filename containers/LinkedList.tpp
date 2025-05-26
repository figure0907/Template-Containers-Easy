#pragma once

#include <iostream>

// Destructor: frees all nodes.
template<typename T>
LinkedList<T>::~LinkedList() {
    Node* current = head;

    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

// Appends an element to the end.
template<typename T>
void LinkedList<T>::push(const T& value) {
    Node* new_node = new Node{value, nullptr};

    if (tail) { tail->next = new_node; }
    else { head = new_node; }

    tail = new_node;
    size++;

    if constexpr (std::is_arithmetic_v<T>) { sum += value; }
}

// Removes and returns the last element.
template<typename T>
T LinkedList<T>::pop() {
    if (!size) { throw std::out_of_range("Can't pop from empty LinkedList"); }

    Node* node = tail;
    T value = node->value;

    if (head == tail) {
        delete node;
        head = tail = nullptr;
    } else {
        Node* prev = head;
        while (prev->next != tail) {
            prev = prev->next;
        }

        prev->next = nullptr;
        tail = prev;
        delete node;
    }

    --size;

    if constexpr (std::is_arithmetic_v<T>) { sum -= value; }

    return value;
}

// Returns average of all elements. Throws if array is empty. Requires arithmetic_v type.
template<typename T>
inline double LinkedList<T>::get_average() const requires std::is_arithmetic_v<T>
{
    if (size == 0) { throw std::runtime_error("Can't get average of empty LinkedList"); }

    return static_cast<double>(sum) / size;
}
