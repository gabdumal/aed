## Library
add_library(testBinaryTree)

## Sources
target_sources(testBinaryTree
    PUBLIC
        testBinaryTree.hpp
    PRIVATE
        testBinaryTree.cpp
)

## Define module
target_include_directories(testBinaryTree
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

## Link libraries
target_link_libraries(testBinaryTree
    PUBLIC
        binaryTree
)
