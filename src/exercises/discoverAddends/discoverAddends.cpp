#include "discoverAddends.hpp"

#include <expected>
#include <print>

std::expected<DiscoverAddends::Addends, std::string>
    DiscoverAddends::discoverAddendsWithSortedOptions(
        std::vector<int> options, int sum) {
    unsigned int index_of_first_addend = 0;
    unsigned int index_of_second_addend = ((unsigned int) options.size()) - 1;

    while (index_of_first_addend < index_of_second_addend) {
        auto result =
            options[index_of_first_addend] +
            options[index_of_second_addend];

        if (result == sum) {
            return {{options[index_of_first_addend],
                     options[index_of_second_addend]}};
        }

        if (result < sum) {
            index_of_first_addend++;
        } else {
            index_of_second_addend--;
        }
    }

    return std::unexpected(message_for_not_found_addends);
}

void DiscoverAddends::run(
    std::vector<int> options, int sum, bool is_sorted) {
    std::println("Options: {}", options);
    std::println("Sum: {}", sum);

    auto result =
        is_sorted
            ? DiscoverAddends::discoverAddendsWithSortedOptions(options, sum)
            : DiscoverAddends::discoverAddendsWithSortedOptions(options, sum);

    if (!result) {
        std::println("Error: {}", result.error());
    }

    auto addends = result.value();
    std::println("Addends: ({}, {})", addends.first, addends.second);
    std::println();
}

void DiscoverAddends::main() {
    DiscoverAddends::run(
        {3, 4, 5, 7},
        8,
        true);

    DiscoverAddends::run(
        {3, 4, 4, 7},
        8,
        true);
}
