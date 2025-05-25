#pragma once

#include <iostream>

// Scans and prints indexable containers. Requires get_size().
template<typename Container>
void Scanner<Container>::scan(const Container& container, std::ostream& out) requires Indexable<Container>
{
    for (std::size_t i = 0; i < container.get_size(); ++i) { out << container[i] << " "; }
    out << std::endl;
}

// Scans and prints iterable containers. Requires begin() and end().
template<typename Container>
void Scanner<Container>::scan(const Container& container, std::ostream& out) requires Iterable<Container>
{
    for (const auto& item : container) { out << item << " "; }
    out << std::endl;
}
