#pragma once

#include <cstddef>
#include <stdexcept>

// Generic scan function
template<typename Container, typename Action>
void scan_and_apply(const Container& container, Action& action) {
    for (const auto& item : container) {
        action(item);
    }
}

template<typename T>
struct Print {
    std::ostream& out;
    void operator()(const T& value) { out << value << " "; }
};

// Sum action
template<typename T>
struct Sum {
    T total{};
    void operator()(const T& value) {
        total += value;
    }
};

// Average action
template<typename T>
struct Average {
    T total{};
    std::size_t count = 0;
    void operator()(const T& value) {
        total += value;
        ++count;
    }
    double result() const {
        if (count == 0) throw std::runtime_error("Empty input");
        return static_cast<double>(total) / count;
    }
};

template<typename T>
struct Max {
    T value;
    bool initialized = false;

    void operator()(const T& item) {
        if (!initialized || item > value) {
            value = item;
            initialized = true;
        }
    }
};

template<typename T>
struct Min {
    T value;
    bool initialized = false;

    void operator()(const T& item) {
        if (!initialized || item < value) {
            value = item;
            initialized = true;
        }
    }
};
