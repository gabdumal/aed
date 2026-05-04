## Library
add_library(testLinkedStack)

## Sources
target_sources(testLinkedStack
    PUBLIC
        testLinkedStack.hpp
    PRIVATE
        testLinkedStack.cpp
)

## Define module
target_include_directories(testLinkedStack
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

## Link libraries
target_link_libraries(testLinkedStack
    PUBLIC
        linkedStack
)
