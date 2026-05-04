## Library
add_library(linkedStack)

## Sources
target_sources(linkedStack
    PUBLIC
        linkedStack.hpp
    PRIVATE
        linkedStack.cpp
)

## Define module
target_include_directories(linkedStack
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

## Link libraries
target_link_libraries(linkedStack
    PUBLIC
        linkedStackNode
)
