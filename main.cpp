#include <string>

#include "DynamicArray.h"
#include "LinkedList.h"
#include "Scanner.h"

int main() {
    // Fill and trim DynamicArray and LinkedList of ints.
    DynamicArray<int> ints_arr;
    for (int i = 1; i <= 150; ++i) {
        ints_arr.push((i * i - 1) % 100);
    }
    for (int i = 1; i <= 135; ++i) {
        ints_arr.pop();
    }

    LinkedList<int> ints_list;
    for (int i = 1; i <= 150; ++i) {
        ints_list.push((i * i - 1) % 100);
    }
    for (int i = 1; i <= 135; ++i) {
        ints_list.pop();
    }

    // Fill and trim DynamicArray and LinkedList of strings.
    DynamicArray<std::string> strings_arr;
    for (int i = 1; i <= 75; ++i) {
        strings_arr.push(std::string(1, 'a' + (i * i - 1) % 100));
    }
    for (int i = 1; i <= 50; ++i) {
        strings_arr.pop();
    }

    LinkedList<std::string> strings_list;
    for (int i = 1; i <= 75; ++i) {
        strings_list.push(std::string(1, 'a' + (i * i - 1) % 100));
    }
    for (int i = 1; i <= 50; ++i) {
        strings_list.pop();
    }
    
    // Scan and print integer container contents.
    Scanner<DynamicArray<int>>::scan(ints_arr, std::cout);
    Scanner<LinkedList<int>>::scan(ints_list, std::cout);

    // Scan and print string container contents.
    Scanner<DynamicArray<std::string>>::scan(strings_arr, std::cout);
    Scanner<LinkedList<std::string>>::scan(strings_list, std::cout);

    // Print averages for integer containers.
    std::cout << ints_arr.get_average() << std::endl;
    std::cout << ints_list.get_average() << std::endl;

    // Attempting to get string averages is a compilation error.
    // std::cout << strings_arr.get_average() << std::endl;
    // std::cout << strings_list.get_average() << std::endl;

    return 0;
}
