#pragma once

#include "IterableWrapper.h"
#include "../containers/DynamicArray.h"
#include "../containers/LinkedList.h"

// Overload for DynamicArray
template<typename T>
auto make_iterable_wrapper(const DynamicArray<T>& arr) {
    return make_iterable_wrapper(
        arr,
        [](const auto& a) { return a.raw_data(); },
        [](const auto& a) { return a.raw_data() + a.get_size(); }
    );
}

// Overload for LinkedList
template<typename T>
auto make_iterable_wrapper(const LinkedList<T>& list) {
    struct Iterator {
        const typename LinkedList<T>::Node* current;
        Iterator(const typename LinkedList<T>::Node* node) : current(node) {}
        const T& operator*() const { return current->value; }
        Iterator& operator++() { current = current->next; return *this; }
        bool operator!=(const Iterator& other) const { return current != other.current; }
    };

    return make_iterable_wrapper(
        list,
        [](const auto& l) { return Iterator(l.get_internal_head()); },
        [](const auto&) { return Iterator(nullptr); }
    );
}
