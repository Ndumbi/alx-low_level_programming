#include "main.h"
#include <stdlib.h>
#include <stdio.h>   // For perror
#include <fcntl.h>   // For open
#include <unistd.h>  // For read, write, close

/**
 * read_textfile - Read text file and print to STDOUT.
 * @filename: Text file being read.
 * @letters: Number of letters to be read.
 * Return: Number of bytes read and printed, or -1 on failure.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
    int fd;
    ssize_t r, w;
    char *buf;

    if (filename == NULL)
    {
        perror("read_textfile: NULL filename");
        return -1;
    }

    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        perror("read_textfile: open");
        return -1;
    }

    buf = malloc(sizeof(char) * letters);
    if (buf == NULL)
    {
        perror("read_textfile: malloc");
        close(fd);
        return -1;
    }

    r = read(fd, buf, letters);
    if (r == -1)
    {
        perror("read_textfile: read");
        free(buf);
        close(fd);
        return -1;
    }

    w = write(STDOUT_FILENO, buf, r);
    if (w == -1)
    {
        perror("read_textfile: write");
        free(buf);
        close(fd);
        return -1;
    }

    free(buf);
    close(fd);
    return w;
}
