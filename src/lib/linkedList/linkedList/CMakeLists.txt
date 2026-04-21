## Library
add_library(linkedList)

## Sources
target_sources(linkedList
    PUBLIC
        linkedList.hpp
    PRIVATE
        linkedList.cpp
)

## Define module
target_include_directories(linkedList
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

## Link libraries
target_link_libraries(linkedList
    PUBLIC
        linkedListNode
)
