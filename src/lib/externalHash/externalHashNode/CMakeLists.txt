## Library
add_library(externalHashNode)

## Sources
target_sources(externalHashNode
    PUBLIC
        externalHashNode.hpp
    PRIVATE
        externalHashNode.cpp
)

## Define module
target_include_directories(externalHashNode
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)
