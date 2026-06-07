## Library
add_library(binomialHeap)

## Sources
target_sources(binomialHeap
    PUBLIC
        binomialHeapNode.hpp
    PRIVATE
        binomialHeapNode.cpp
)

## Define module
target_include_directories(binomialHeap
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)
