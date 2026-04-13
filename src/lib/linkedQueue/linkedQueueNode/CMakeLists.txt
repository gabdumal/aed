## Library
add_library(linkedQueueNode)

## Sources
target_sources(linkedQueueNode
    PUBLIC
        linkedQueueNode.hpp
    PRIVATE
        linkedQueueNode.cpp
)

## Define module
target_include_directories(linkedQueueNode
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)
