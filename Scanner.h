#pragma once

#include <cstddef>
#include <stdexcept>

// Applies a given action to each element in the container.
// The container must support iteration via begin() and end(),
// either directly or through a wrapper created by make_iterable_wrapper().
template<typename Container, typename Action>
void scan_and_apply(const Container& container, Action&& action) {
    using T = typename Container::value_type;
    static_assert(
        std::is_same_v<T, typename std::remove_reference_t<Action>::element_type>,
        "Mismatch: Action does not match container element type"
    );

    using std::begin;
    using std::end;
    for (auto it = begin(container); it != end(container); ++it) {
        action(*it);
    }
}

// Action structs define what to do with each element during a scan.
// Each action must support operator()(const T&) to handle one element.

// Print action
template<typename T>
struct Print {
    using element_type = T;
    
    std::ostream& out;
    void operator()(const T& value) { out << value << " "; }
};

// Sum action
template<typename T>
struct Sum {
    using element_type = T;

    T total{};
    void operator()(const T& value) { total += value; }
};

// Average action
template<typename T>
struct Average {
    using element_type = T;

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
    using element_type = T;

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
    using element_type = T;

    T value;
    bool initialized = false;

    void operator()(const T& item) {
        if (!initialized || item < value) {
            value = item;
            initialized = true;
        }
    }
};
