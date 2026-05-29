## Library
add_library(avlTree)

## Sources
target_sources(avlTree
    PUBLIC
        avlTreeNode.hpp
    PRIVATE
        avlTreeNode.cpp
)

## Define module
target_include_directories(avlTree
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)
