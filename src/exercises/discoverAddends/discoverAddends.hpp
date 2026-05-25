#ifndef __DISCOVER_ADDENDS_HPP__
#define __DISCOVER_ADDENDS_HPP__

#include <expected>
#include <string>
#include <vector>

class DiscoverAddends {
    public:
        struct Addends {
                int first;
                int second;
        };

    private:
        static constexpr auto message_for_not_found_addends = "Addends could not be found.";

        static std::expected<Addends, std::string> discoverAddendsWithSortedOptions(std::vector<int> options, int sum);

        static void run(
            std::vector<int> options, int sum, bool is_sorted);

    public:
        static void main();
};

#endif  // __DISCOVER_ADDENDS_HPP__
