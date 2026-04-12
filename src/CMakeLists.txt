## Executable
add_executable(aed
        main.cpp
)

## Directories
add_subdirectory(contiguousList)

## Link libraries
target_link_libraries(aed
    PUBLIC
        contiguousList
)
