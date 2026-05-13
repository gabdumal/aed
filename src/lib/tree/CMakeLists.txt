## Library
add_library(tree)

## Sources
target_sources(tree
    PUBLIC
        tree.hpp
    PRIVATE
        tree.cpp
)

## Define module
target_include_directories(tree
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)
