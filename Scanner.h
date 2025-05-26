#pragma once

#include <cstddef>
#include <stdexcept>

// Default scan function for iterable containers.
// Uses standard begin()/end() to delegate to the generic implementation.
template<typename Container, typename Action>
void scan_and_apply(const Container& container, Action&& action) {
    scan_and_apply_custom(container, std::forward<Action>(action),
                          [](const auto& c) { return c.begin(); },
                          [](const auto& c) { return c.end(); });
}

// Iteration is controlled by user-provided begin()/end() functions.
template<typename Container, typename Action, typename BeginFn, typename EndFn>
void scan_and_apply_custom(const Container& container, Action&& action, BeginFn begin_fn, EndFn end_fn) {
    for (auto it = begin_fn(container); it != end_fn(container); ++it) {
        action(*it);
    }
}

// Action structs define what to do with each element during a scan.
// Each action must support operator()(const T&) to handle one element.

// Print action
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

// Max action
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

// Min action
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
