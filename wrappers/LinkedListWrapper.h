#pragma once

#include "../containers/LinkedList.h"
#include "IterableWrapper.h"

template<typename T>
struct LinkedListNodeProxy {
    T value;
    const LinkedListNodeProxy* next;
};

template<typename T>
class LinkedListIterator {
    public:
        using Proxy = LinkedListNodeProxy<T>;

        const Proxy* current;

        LinkedListIterator(const void* raw_node_ptr)
            : current(reinterpret_cast<const Proxy*>(raw_node_ptr)) {}

        const T& operator*() const { return current->value; }

        LinkedListIterator& operator++() {
            current = current->next;
            return *this;
        }

        bool operator!=(const LinkedListIterator& other) const { return current != other.current; }
};

template<typename T>
auto make_iterable_wrapper(const LinkedList<T>& list) {
    return make_iterable_wrapper(
        list,
        [](const auto& l) { return LinkedListIterator<T>(l.get_internal_head()); },
        [](const auto&) { return LinkedListIterator<T>(nullptr); }
    );
}