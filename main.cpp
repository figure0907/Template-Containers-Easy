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
    Print<int> int_printer{std::cout};
    scan_and_apply(ints_arr, int_printer);
    std::cout << std::endl;
    scan_and_apply(ints_list, int_printer);
    std::cout << std::endl;

    // Scan and print string container contents.
    Print<std::string> str_printer{std::cout};
    scan_and_apply(strings_arr, str_printer);
    std::cout << std::endl;
    scan_and_apply(strings_list, str_printer);
    std::cout << std::endl;

    // Print averages for integer containers.
    // std::cout << ints_arr.get_average() << std::endl;
    // std::cout << ints_list.get_average() << std::endl;

    // Attempting to get string averages is a compilation error.
    // std::cout << strings_arr.get_average() << std::endl;
    // std::cout << strings_list.get_average() << std::endl;

    // Compute and print aggregates using scan_and_apply
    Sum<int> int_total;
    Max<int> int_maximum;
    Min<int> int_minimum;

    scan_and_apply(ints_list, int_total);
    scan_and_apply(ints_list, int_maximum);
    scan_and_apply(ints_list, int_minimum);

    std::cout << "Sum of ints: " << int_total.total << "\n";
    std::cout << "Max of ints: " << int_maximum.value << "\n";
    std::cout << "Min of ints: " << int_minimum.value << "\n";

    Sum<std::string> str_total;
    Max<std::string> str_max;
    Min<std::string> str_min;
    scan_and_apply(strings_list, str_total); // This will work fine using concatenation.
    scan_and_apply(strings_list, str_max);
    scan_and_apply(strings_list, str_min);

    std::cout << "Sum of strings: " << str_total.total << "\n";
    std::cout << "Max of strings: " << str_max.value << "\n";
    std::cout << "Min of strings: " << str_min.value << "\n";

    Average<int> int_avg;
    scan_and_apply(ints_list, int_avg);
    std::cout << "Int avg: " << int_avg.result() << "\n";

    // Average<std::string> str_avg;
    // scan_and_apply(strings_list, str_avg);
    // std::cout << "Str Avg: " << str_avg.result() << "\n"; // This line won't compile!

    return 0;
}
