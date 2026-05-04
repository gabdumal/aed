## Library
add_library(linkedStackNode)

## Sources
target_sources(linkedStackNode
    PUBLIC
        linkedStackNode.hpp
    PRIVATE
        linkedStackNode.cpp
)

## Define module
target_include_directories(linkedStackNode
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)
