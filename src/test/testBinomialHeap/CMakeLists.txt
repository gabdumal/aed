## Library
add_library(testBinomialHeap)

## Sources
target_sources(testBinomialHeap
    PUBLIC
        testBinomialHeap.hpp
    PRIVATE
        testBinomialHeap.cpp
)

## Define module
target_include_directories(testBinomialHeap
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

## Link libraries
target_link_libraries(testBinomialHeap
    PUBLIC
        binomialHeap
)
