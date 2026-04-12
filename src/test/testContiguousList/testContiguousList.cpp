#include "testContiguousList.hpp"

#include <print>
#include <stdexcept>

#include "contiguousList.hpp"

void TestContiguousList::test() {
    constexpr unsigned int maximum_size = 1 << 2;

    auto contiguous_list = ContiguousList(maximum_size);
    std::print("Items: ");
    contiguous_list.print();

    try {
        contiguous_list.insert(-1, 4);
    } catch (std::out_of_range exception) {
        std::println("Exception: {}", exception.what());
    }
    std::print("Items: ");
    contiguous_list.print();

    contiguous_list.insert(0, 4);
    std::print("Items: ");
    contiguous_list.print();

    contiguous_list.insert(0, 1);
    std::print("Items: ");
    contiguous_list.print();

    contiguous_list.insert(1, 2);
    std::print("Items: ");
    contiguous_list.print();

    contiguous_list.insert(2, 3);
    std::print("Items: ");
    contiguous_list.print();

    contiguous_list.insert(3, 4);
    std::print("Items: ");
    contiguous_list.print();

    try {
        contiguous_list.insert(4, 5);
    } catch (std::length_error exception) {
        std::println("Exception: {}", exception.what());
    }
    std::print("Items: ");
    contiguous_list.print();
}
