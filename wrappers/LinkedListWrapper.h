#pragma once

#include "../containers/LinkedList.h"
#include "IterableWrapper.h"

template<typename T>
auto make_linked_list_wrapper(const LinkedList<T>& list) {
    using Node = typename LinkedList<T>::Node;

    struct Iterator {
        const Node* current;

        Iterator(const Node* node) : current(node) {}
        const T& operator*() const { return current->value; }
        Iterator& operator++() { current = current->next; return *this; }
        bool operator!=(const Iterator& other) const { return current != other.current; }
    };

    auto begin_fn = [](const LinkedList<T>& l) -> Iterator { return Iterator(static_cast<const Node*>(l.get_internal_head())); };

    auto end_fn = [](const LinkedList<T>&) -> Iterator { return Iterator(nullptr); };

    return make_iterable_wrapper(list, begin_fn, end_fn);
}
