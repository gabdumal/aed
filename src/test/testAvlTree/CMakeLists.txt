## Library
add_library(testAvlTree)

## Sources
target_sources(testAvlTree
    PUBLIC
        testAvlTree.hpp
    PRIVATE
        testAvlTree.cpp
)

## Define module
target_include_directories(testAvlTree
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

## Link libraries
target_link_libraries(testAvlTree
    PUBLIC
        avlTree
)
