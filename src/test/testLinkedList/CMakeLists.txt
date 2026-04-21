## Library
add_library(testLinkedList)

## Sources
target_sources(testLinkedList
    PUBLIC
        testLinkedList.hpp
    PRIVATE
        testLinkedList.cpp
)

## Define module
target_include_directories(testLinkedList
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

## Link libraries
target_link_libraries(testLinkedList
    PUBLIC
        linkedList
)
