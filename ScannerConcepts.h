#pragma once

#include <cstddef>

// A concept for containers that support operator[] and get_size().
template<typename T>
concept Indexable = requires(const T& t, std::size_t i) {
    { t[i] };
    { t.get_size() };
};

// A concept for containers that support iteration using begin() and end().
template<typename T>
concept Iterable = requires(const T& t) {
    { t.begin() };
    { t.end() };
};
