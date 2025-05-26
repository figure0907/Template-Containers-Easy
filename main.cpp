#include <string>

#include "containers/DynamicArray.h"
#include "containers/LinkedList.h"
#include "Scanner.h"
#include "wrappers/Wrappers.h"

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
    auto wrapped_ints_arr = make_iterable_wrapper(ints_arr);
    auto wrapped_ints_list = make_iterable_wrapper(ints_list);

    Print<int> int_printer{std::cout};
    scan_and_apply(wrapped_ints_arr, int_printer);
    std::cout << std::endl;
    scan_and_apply(wrapped_ints_list, int_printer);
    std::cout << std::endl;

    // Scan and print string container contents.
    auto wrapped_str_arr = make_iterable_wrapper(strings_arr);
    auto wrapped_str_list = make_iterable_wrapper(strings_list);

    Print<std::string> str_printer{std::cout};
    scan_and_apply(wrapped_str_arr, str_printer);
    std::cout << std::endl;
    scan_and_apply(wrapped_str_list, str_printer);
    std::cout << std::endl;

    // Compute and print aggregates using scan_and_apply
    Sum<int> int_total;
    Max<int> int_maximum;
    Min<int> int_minimum;

    scan_and_apply(wrapped_ints_arr, int_total);
    scan_and_apply(wrapped_ints_arr, int_maximum);
    scan_and_apply(wrapped_ints_arr, int_minimum);

    std::cout << "Sum of ints: " << int_total.total << "\n";
    std::cout << "Max of ints: " << int_maximum.value << "\n";
    std::cout << "Min of ints: " << int_minimum.value << "\n";

    Sum<std::string> str_total;
    Max<std::string> str_max;
    Min<std::string> str_min;

    scan_and_apply(wrapped_str_list, str_total); // This will work fine using concatenation.
    scan_and_apply(wrapped_str_list, str_max);
    scan_and_apply(wrapped_str_list, str_min);

    std::cout << "Sum of strings: " << str_total.total << "\n";
    std::cout << "Max of strings: " << str_max.value << "\n";
    std::cout << "Min of strings: " << str_min.value << "\n";

    Average<int> int_avg;
    scan_and_apply(wrapped_ints_arr, int_avg);
    std::cout << "Int avg: " << int_avg.result() << "\n";

    // Average<std::string> str_avg;
    // Average<std::string> str_avg;
    // scan_and_apply(wrapped_str_list, str_avg);
    // std::cout << "Str Avg: " << str_avg.result() << "\n"; // This line won't compile!

    LinkedList<float> floats_list;
    for (int i = 1; i <= 10; ++i) {
        floats_list.push(static_cast<float>(i * i / (i + 7.0)));
    }

    auto wrapped_float_arr = make_iterable_wrapper(floats_list);
    
    Print<float> float_printer{std::cout};
    scan_and_apply(wrapped_float_arr, float_printer);
    std::cout << std::endl;

    Sum<float> float_total;
    Max<float> float_maximum;
    Min<float> float_minimum;

    scan_and_apply(wrapped_float_arr, float_total);
    scan_and_apply(wrapped_float_arr, float_maximum);
    scan_and_apply(wrapped_float_arr, float_minimum);

    std::cout << "Sum of floats: " << float_total.total << "\n";
    std::cout << "Max of floats: " << float_maximum.value << "\n";
    std::cout << "Min of floats: " << float_minimum.value << "\n";

    Average<float> float_avg;
    scan_and_apply(wrapped_float_arr, float_avg);
    std::cout << "Float avg: " << float_avg.result() << "\n";


    return 0;
}
