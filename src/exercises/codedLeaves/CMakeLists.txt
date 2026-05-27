## Library
add_library(codedLeaves)

## Sources
target_sources(codedLeaves
    PUBLIC
        codedLeaves.hpp
    PRIVATE
        codedLeaves.cpp
)

## Define module
target_include_directories(codedLeaves
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)
