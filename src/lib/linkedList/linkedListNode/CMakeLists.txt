## Library
add_library(linkedListNode)

## Sources
target_sources(linkedListNode
    PUBLIC
        linkedListNode.hpp
    PRIVATE
        linkedListNode.cpp
)

## Define module
target_include_directories(linkedListNode
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)
