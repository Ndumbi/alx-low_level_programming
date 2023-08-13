0x0C. C - More malloc, free

In C programming, malloc and free are used to manage memory in a dynamic way. This means you can request and release memory as your program runs, which can be really useful when you don't know exactly how much memory you'll need beforehand.

malloc:

Imagine your program is like a backpack, and you need space to put things (data) in it.
malloc is like asking for a specific amount of space in your backpack. You tell it how much space you need (in bytes), and it gives you back a pointer (address) to that space.
Example: If you need room for five books, you'd use malloc to request space for those books.

free:

Just like you wouldn't want to carry unnecessary stuff in your backpack, you don't want to waste memory in your program.
free is like telling the backpack that you're done using some space (memory) and it's now empty.
Example: When you're done with those five books, you'd use free to let go of the space they were taking up.

Remember:

Use malloc to request memory space.
Always check if the return value of malloc is not NULL to make sure the allocation was successful.
Use free when you're done with the allocated memory to prevent memory leaks.
