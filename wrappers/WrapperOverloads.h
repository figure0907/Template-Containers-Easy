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
