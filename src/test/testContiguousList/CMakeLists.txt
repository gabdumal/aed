## Library
add_library(testContiguousList)

## Sources
target_sources(testContiguousList
    PUBLIC
        testContiguousList.hpp
    PRIVATE
        testContiguousList.cpp
)

## Define module
target_include_directories(testContiguousList
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

## Link libraries
target_link_libraries(testContiguousList
    PUBLIC
        contiguousList
)
