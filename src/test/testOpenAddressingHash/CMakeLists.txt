## Library
add_library(testOpenAddressingHash)

## Sources
target_sources(testOpenAddressingHash
    PUBLIC
        testOpenAddressingHash.hpp
    PRIVATE
        testOpenAddressingHash.cpp
)

## Define module
target_include_directories(testOpenAddressingHash
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

## Link libraries
target_link_libraries(testOpenAddressingHash
    PUBLIC
        openAddressingHash
)
