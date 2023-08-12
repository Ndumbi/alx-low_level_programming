0x0B. C - malloc, free
malloc and free are two functions in C that are used to allocate and deallocate memory dynamically.

malloc allocates a block of memory of the specified size. The memory allocated by malloc is not initialized, so it is important to initialize it before using it.
free deallocates a block of memory that was previously allocated by malloc. It is important to call free on any memory that was allocated by malloc before the program exits, to prevent memory leaks.

The malloc function returns a pointer to the allocated memory. This pointer can be used to access the allocated memory. The free function takes a pointer to the memory that is being deallocated as its argument.

It is important to note that malloc and free are not thread-safe. This means that they should not be used in multithreaded programs without additional synchronization mechanisms.
