## Library
add_library(testAvlTreeBal)

## Sources
target_sources(testAvlTreeBal
    PUBLIC
        testAvlTreeBal.hpp
    PRIVATE
        testAvlTreeBal.cpp
)

## Define module
target_include_directories(testAvlTreeBal
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

## Link libraries
target_link_libraries(testAvlTreeBal
    PUBLIC
        avlTreeBal
)
