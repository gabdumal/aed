## Library
add_library(discoverAddends)

## Sources
target_sources(discoverAddends
    PUBLIC
        discoverAddends.hpp
    PRIVATE
        discoverAddends.cpp
)

## Define module
target_include_directories(discoverAddends
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)
