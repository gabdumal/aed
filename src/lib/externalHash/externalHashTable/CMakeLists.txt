## Library
add_library(externalHashTable)

## Sources
target_sources(externalHashTable
    PUBLIC
        externalHashTable.hpp
    PRIVATE
        externalHashTable.cpp
)

## Define module
target_include_directories(externalHashTable
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

## Link libraries
target_link_libraries(externalHashTable
    PUBLIC
        externalHashNode
)
