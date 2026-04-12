#include "contiguousList.hpp"

constexpr unsigned int maximum_size = 1 << 6;

int main() {
    auto contiguous_list = ContiguousList(maximum_size);
    contiguous_list.insert(0, 1);

    return 0;
}
