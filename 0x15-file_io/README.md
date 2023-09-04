0x15. C - File I/O
This project  explains how to read and write files in C.

What is File I/O?
File I/O is the process of reading and writing data to files. Files are used to store data permanently on a disk or other storage device.

How to Read a File
To read a file, you use the fopen() function. The fopen() function takes two arguments: the name of the file and the mode of the file.

The mode of the file can be one of the following:

r: Open the file for reading only.
w: Open the file for writing only.
a: Open the file for appending to the end of the file.
r+: Open the file for reading and writing.
The fopen() function returns a pointer to the file if the file is opened successfully. If the file cannot be opened, the fopen() function returns NULL.

Once you have opened the file, you can read data from the file using the fread() function. The fread() function takes three arguments: the pointer to the buffer where the data will be stored, the number of bytes to be read, and the file pointer.

The fread() function returns the number of bytes that were actually read. If the end of the file is reached, the fread() function returns 0.

How to Write to a File
To write to a file, you use the fwrite() function. The fwrite() function takes three arguments: the pointer to the data to be written, the number of bytes to be written, and the file pointer.

The fwrite() function returns the number of bytes that were actually written.

How to Close a File
When you are finished reading or writing to a file, you should close the file using the fclose() function. The fclose() function takes one argument: the file pointer.

Example
The following code reads a file and prints the contents of the file to the screen:

c
#include <stdio.h>

int main() {
FILE *fp;
char buffer[100];

// Open the file for reading.
fp = fopen("myfile.txt", "r");
if (fp == NULL) {
printf("Error opening file.\n");
return 1;
}

// Read the contents of the file.
while (fgets(buffer, sizeof(buffer), fp) != NULL) {
printf("%s", buffer);
}

// Close the file.
fclose(fp);

return 0;
}

This code first opens the file myfile.txt for reading. If the file cannot be opened, the program will print an error message and exit.

The code then reads the contents of the file one line at a time using the fgets() function. The fgets() function reads a line from the file and stores it in the buffer.

The code then prints the contents of the buffer to the screen.

Finally, the code closes the file using the fclose() function.
