0x0A. C - argc, argv

argc and argv are two special variables that are passed to the main() function when a C program is started.

argc is an integer variable that specifies the number of arguments that were passed to the program on the command line.
argv is an array of pointers to strings, where each string is one of the arguments that was passed to the program on the command line.
The first element of argv is a pointer to the string that contains the name of the program itself. The remaining elements of argv are pointers to the strings of the arguments that were passed to the program on the command line.
You can use argc and argv to access the arguments that were passed to your program on the command line
You can also use argc and argv to process the arguments that were passed to your program in more complex ways. For example, you could use them to read a file, sort the arguments, or perform other tasks.

In simple words, argc is the number of arguments passed to the program, and argv is an array of pointers to the strings of the arguments that were passed to the program.
