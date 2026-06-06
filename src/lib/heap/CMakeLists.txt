## Library
add_library(heap)

## Sources
target_sources(heap
    PUBLIC
        heapNode.hpp
    PRIVATE
        heapNode.cpp
)

## Define module
target_include_directories(heap
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)
