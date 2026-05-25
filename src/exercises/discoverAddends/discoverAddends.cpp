#include "discoverAddends.hpp"

#include <print>

DiscoverAddends::Addends
    DiscoverAddends::discoverAddendsWithSortedOptions(
        std::vector<int> options, int sum) {
    return {0, 0};
}

void DiscoverAddends::run(
    std::vector<int> options, int sum, bool is_sorted) {
    std::println("Options: {}", options);
    std::println("Sum: {}", sum);

    auto addends =
        is_sorted
            ? DiscoverAddends::discoverAddendsWithSortedOptions(options, sum)
            : DiscoverAddends::discoverAddendsWithSortedOptions(options, sum);

    std::println("Addends: ({}, {})", addends.first, addends.second);
}

void DiscoverAddends::main() {
    std::vector options = {3, 7, 5, 4};
    int sum = 8;

    DiscoverAddends::run(options, sum, true);
}
