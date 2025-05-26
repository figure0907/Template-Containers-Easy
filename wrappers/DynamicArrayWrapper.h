#pragma once

#include "../containers/DynamicArray.h"
#include "IterableWrapper.h"

template<typename T>
auto make_dynamic_array_wrapper(const DynamicArray<T>& arr) {
    auto begin_fn = [](const DynamicArray<T>& a) { return a.get_size() ? &a[0] : static_cast<const T*>(nullptr); };

    auto end_fn = [](const DynamicArray<T>& a) { return a.get_size() ? &a[0] + a.get_size() : static_cast<const T*>(nullptr); };

    return make_iterable_wrapper(arr, begin_fn, end_fn);
}
