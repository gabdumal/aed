## Library
add_library(linkedQueue)

## Sources
target_sources(linkedQueue
    PUBLIC
        linkedQueue.hpp
    PRIVATE
        linkedQueue.cpp
)

## Define module
target_include_directories(linkedQueue
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

## Link libraries
target_link_libraries(linkedQueue
    PUBLIC
        linkedQueueNode
)
