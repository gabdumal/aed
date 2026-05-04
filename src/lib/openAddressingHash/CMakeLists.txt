## Library
add_library(openAddressingHash)

## Sources
target_sources(openAddressingHash
    PUBLIC
        openAddressingHash.hpp
    PRIVATE
        openAddressingHash.cpp
)

## Define module
target_include_directories(openAddressingHash
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)
