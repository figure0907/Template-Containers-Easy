#pragma once

#include <ostream>

#include "ScannerConcepts.h"

// A generic scanner class that prints container contents to an output stream.
// Supports indexable and iterable containers using concepts.
template<typename Container>
class Scanner {
    public:
        // Prints all elements by iteration over indices. Requires operator[] and get_size().
        static void scan(const Container& container, std::ostream& out) requires Indexable<Container>;

        // Prints all elements by iteration over elements. Requires begin() and end().
        static void scan(const Container& container, std::ostream& out) requires Iterable<Container>;
};

#include "Scanner.tpp"
