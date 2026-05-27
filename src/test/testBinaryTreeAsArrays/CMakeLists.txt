## Library
add_library(testBinaryTreeAsArrays)

## Sources
target_sources(testBinaryTreeAsArrays
    PUBLIC
        testBinaryTreeAsArrays.hpp
    PRIVATE
        testBinaryTreeAsArrays.cpp
)

## Define module
target_include_directories(testBinaryTreeAsArrays
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

## Link libraries
target_link_libraries(testBinaryTreeAsArrays
    PUBLIC
        binaryTreeAsArrays
)
