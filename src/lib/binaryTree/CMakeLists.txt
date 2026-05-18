## Library
add_library(binaryTree)

## Sources
target_sources(binaryTree
    PUBLIC
        binaryTreeNode.hpp
    PRIVATE
        binaryTreeNode.cpp
)

## Define module
target_include_directories(binaryTree
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)
