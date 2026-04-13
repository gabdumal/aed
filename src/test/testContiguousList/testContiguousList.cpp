#include "testContiguousList.hpp"

#include <print>

#include "contiguousList.hpp"

void printItems(ContiguousList &contiguous_list) {
    std::print("Items: ");
    contiguous_list.print();
}

void printError(const std::string &error) {
    std::println("Error: {}", error);
}

void listWithMaximumSizeOfZero() {
    std::println("TEST: maximum size of 0.");
    std::println();

    constexpr unsigned int maximum_size = 0;

    auto contiguous_list = ContiguousList(maximum_size);
    printItems(contiguous_list);

    if (auto result = contiguous_list.insert(0, 4); !result) {
        printError(result.error());
    }

    printItems(contiguous_list);

    std::println();
}

void listWithMaximumSizeOfFour() {
    std::println("TEST: maximum size of 4.");
    std::println();

    constexpr unsigned int maximum_size = 4;

    auto contiguous_list = ContiguousList(maximum_size);
    printItems(contiguous_list);

    if (auto result = contiguous_list.remove(0); !result) {
        printError(result.error());
    }
    printItems(contiguous_list);

    if (auto result = contiguous_list.insert((unsigned int) -1, 4); !result) {
        printError(result.error());
    }
    printItems(contiguous_list);

    contiguous_list.insert(0, 4);
    printItems(contiguous_list);

    contiguous_list.insert(0, 1);
    printItems(contiguous_list);

    contiguous_list.insert(1, 2);
    printItems(contiguous_list);

    contiguous_list.insert(2, 3);
    printItems(contiguous_list);

    if (auto result = contiguous_list.insert(3, 4); !result) {
        printError(result.error());
    }
    printItems(contiguous_list);

    contiguous_list.remove(3);
    printItems(contiguous_list);

    contiguous_list.insert(3, 4);
    printItems(contiguous_list);

    contiguous_list.remove(0);
    printItems(contiguous_list);

    contiguous_list.insert(2, -3);
    printItems(contiguous_list);

    std::println();
}

void TestContiguousList::test() {
    std::println("TESTS: CONTIGUOUS LIST");
    std::println();

    listWithMaximumSizeOfZero();
    listWithMaximumSizeOfFour();

    std::println();
}
