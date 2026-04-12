#include "testContiguousList.hpp"

#include <print>
#include <stdexcept>

#include "contiguousList.hpp"

void TestContiguousList::test() {
    constexpr unsigned int maximum_size = 1 << 6;

    auto contiguous_list = ContiguousList(maximum_size);

    try {
        contiguous_list.insert(-1, 4);
    } catch (std::out_of_range exception) {
        std::println("{}", exception.what());
    }

    contiguous_list.insert(0, 4);
}
