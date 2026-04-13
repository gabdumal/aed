## Library
add_library(testLinkedQueue)

## Sources
target_sources(testLinkedQueue
    PUBLIC
        testLinkedQueue.hpp
    PRIVATE
        testLinkedQueue.cpp
)

## Define module
target_include_directories(testLinkedQueue
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

## Link libraries
target_link_libraries(testLinkedQueue
    PUBLIC
        linkedQueue
)
