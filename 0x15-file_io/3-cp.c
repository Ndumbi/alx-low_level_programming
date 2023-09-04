#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

void close_file(int fd);

int main(int argc, char *argv[])
{
    int from, to;
    ssize_t r, w;
    char buffer[BUFFER_SIZE];

    if (argc != 3)
    {
        fprintf(stderr, "Usage: cp file_from file_to\n");
        return 97;
    }

    from = open(argv[1], O_RDONLY);
    if (from == -1)
    {
        perror("Error opening source file");
        return 98;
    }

    to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
    if (to == -1)
    {
        perror("Error opening destination file");
        close_file(from);
        return 99;
    }

    while ((r = read(from, buffer, BUFFER_SIZE)) > 0)
    {
        w = write(to, buffer, r);
        if (w == -1)
        {
            perror("Error writing to destination file");
            close_file(from);
            close_file(to);
            return 99;
        }
    }

    if (r == -1)
    {
        perror("Error reading from source file");
        close_file(from);
        close_file(to);
        return 98;
    }

    close_file(from);
    close_file(to);

    return 0;
}

void close_file(int fd)
{
    if (close(fd) == -1)
    {
        perror("Error closing file");
        exit(100);
    }
}
