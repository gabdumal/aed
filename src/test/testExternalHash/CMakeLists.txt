## Library
add_library(testExternalHash)

## Sources
target_sources(testExternalHash
    PUBLIC
        testExternalHash.hpp
    PRIVATE
        testExternalHash.cpp
)

## Define module
target_include_directories(testExternalHash
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

## Link libraries
target_link_libraries(testExternalHash
    PUBLIC
        externalHashTable
)
