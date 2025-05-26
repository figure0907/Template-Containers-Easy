#pragma once

#include <iostream>
#include <type_traits>

// Returns reference to the element at given index. Throws if out of bounds.
template<typename T>
const T& DynamicArray<T>::operator[](std::size_t idx) const {
    if (idx >= size) { throw std::out_of_range("Index out of range"); }

    return data[idx];
}

// Returns mutable element at given index. Throws if out of bounds.
template<typename T>
T& DynamicArray<T>::operator[](std::size_t idx) {
    if (idx >= size) { throw std::out_of_range("Index out of range"); }

    return data[idx];
}

// Appends an element to the end. Grows storage if needed.
template<typename T>
void DynamicArray<T>::push(const T& value) {
    if (size == limit) grow();
    data[size++] = value;
    if constexpr (std::is_arithmetic_v<T>) { sum += value; }
}

// Removes and returns the last element. Shrinks storage if needed.
template<typename T>
T DynamicArray<T>::pop() {
    if (!size) { throw std::out_of_range("Can't pop from empty DynamicArray"); }
    T value = data[--size];
    if constexpr (std::is_arithmetic_v<T>) { sum -= value; }
    if (size <= limit / 4) { shrink(); }

    return value;
}

// Doubles the capacity if full (or sets to 2 if empty).
template<typename T>
void DynamicArray<T>::grow() {
    std::size_t new_limit = (limit == 0) ? 2 : limit * 2;
    // std::cout << "Growing from " << limit << " to " << new_limit << std::endl;
    resize(new_limit);
}

// Halves the capacity if usage drops to one-quarter of current capacity.
template<typename T>
void DynamicArray<T>::shrink() {
    std::size_t new_limit = (limit <= 2) ? 0 : limit / 2;
    // std::cout << "Shrinking from " << limit << " to " << new_limit << std::endl;
    resize(new_limit);
}

// Resizes internal storage to given new_limit.
template<typename T>
void DynamicArray<T>::resize(std::size_t new_limit) {
    T* new_data = new T[new_limit];
    for (std::size_t i = 0; i < size; ++i) { new_data[i] = data[i]; }

    delete[] data;
    data = new_data;
    limit = new_limit;
}

// Returns average of all elements. Throws if array is empty. Requires arithmetic_v type.
template<typename T>
inline double DynamicArray<T>::get_average() const requires std::is_arithmetic_v<T>
{
    if (size == 0) { throw std::runtime_error("Can't get average of empty DynamicArray"); }

    return static_cast<double>(sum) / size;
}
