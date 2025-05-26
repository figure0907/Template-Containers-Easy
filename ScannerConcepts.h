#pragma once

#include <concepts>
#include <cstddef>

// Addition (T + T)
template<typename T>
concept Addable = requires(T a, T b) {
    { a + b } -> std::same_as<T>;
};

// Division by integer (T / std::size_t)
template<typename T>
concept Divisible = requires(T a, std::size_t b) {
    { a / b } -> std::convertible_to<double>;
};

// Comparable (T < T)
template<typename T>
concept LessThanComparable = requires(T a, T b) {
    { a < b } -> std::convertible_to<bool>;
};
