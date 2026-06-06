## Library
add_library(testHeap)

## Sources
target_sources(testHeap
    PUBLIC
        testHeap.hpp
    PRIVATE
        testHeap.cpp
)

## Define module
target_include_directories(testHeap
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

## Link libraries
target_link_libraries(testHeap
    PUBLIC
        heap
)
