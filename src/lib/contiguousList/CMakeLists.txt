## Library
add_library(contiguousList)

## Sources
target_sources(contiguousList
    PUBLIC
        contiguousList.hpp
    PRIVATE
        contiguousList.cpp
)

## Define module
target_include_directories(contiguousList
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)
