#include <iostream>
#include <cstdlib>

#include "testContiguousList.hpp"
#include "testLinkedQueue.hpp"

int main(int argc, char *argv[]) {
    std::string test_to_run;
    
    if (argc >= 2) {
        test_to_run = argv[1];
    } else {
        const char* env_test = std::getenv("TEST_TO_RUN");
        if (env_test) {
            test_to_run = env_test;
        } else {
            std::cerr << "Usage: " << argv[0] << " <TestName>" << std::endl;
            std::cerr << "Or set TEST_TO_RUN environment variable" << std::endl;
            return 1;
        }
    }

    if (test_to_run == "TestContiguousList") {
        TestContiguousList::test();
    } else if (test_to_run == "TestLinkedQueue") {
        TestLinkedQueue::test();
    } else {
        std::cerr << "Unknown test: " << test_to_run << "." << std::endl;
        return 1;
    }

    return 0;
}
