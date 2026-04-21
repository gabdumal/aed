## Executable
add_executable(aed
        main.cpp
)

## Directories
add_subdirectory(lib)
add_subdirectory(test)

## Link libraries
target_link_libraries(aed
    PUBLIC
        testContiguousList
        testLinkedList
        testLinkedQueue
)
