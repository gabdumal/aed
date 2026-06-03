## Library
add_library(avlTreeBal)

## Sources
target_sources(avlTreeBal
    PUBLIC
        avlTreeBalNode.hpp
    PRIVATE
        avlTreeBalNode.cpp
)

## Define module
target_include_directories(avlTreeBal
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)
