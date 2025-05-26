#pragma once

// A dynamically resizing array-based container, similar to std::vector.
// Supports push, pop, and indexed access. Tracks sum for arithmetic types.
// Returns average.
template<typename T>
class DynamicArray {
    public:
        using value_type = T;

        // Constructor and destructor
        inline DynamicArray() : data(nullptr), sum(), size(0), limit(0) {};
        inline ~DynamicArray() { delete[] data; };

        // Elemnt access methods
        const T& operator[](std::size_t idx) const;
        T& operator[](std::size_t idx);

        // Accessor methods
        inline const T* raw_data() const { return data; }
        inline T* raw_data() { return data; }

        // Modifier methods
        void push(const T& value);
        T pop();

        // Query methods
        inline std::size_t get_size() const { return size; }
        inline T get_sum() const requires std::is_arithmetic_v<T> { return sum; };
        inline double get_average() const requires std::is_arithmetic_v<T>;

    private:
        T* data;                        // Pointer to allocated storage
        T sum{};                        // Running sum for arithmetic types
        std::size_t size;               // Number of elements
        std::size_t limit;              // Allocated capacity

        // Resizing utilities
        void grow();
        void shrink();
        void resize(std::size_t new_limit);
};

#include "DynamicArray.tpp"
