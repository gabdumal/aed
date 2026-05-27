## Library
add_library(binaryTreeAsArrays)

## Sources
target_sources(binaryTreeAsArrays
    PUBLIC
        binaryTreeAsArrays.hpp
    PRIVATE
        binaryTreeAsArrays.cpp
)

## Define module
target_include_directories(binaryTreeAsArrays
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)
