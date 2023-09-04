#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // Include for the close constant
#include <fcntl.h>  // Include for the open function

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: A pointer to the name of the file.
 * @text_content: The string to add to the end of the file.
 *
 * Return: If the function fails or filename is NULL - -1.
 *         If the file does not exist or the user lacks write permissions - -1.
 *         Otherwise - 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
    int fd, len = 0;

    if (filename == NULL)
        return (-1);

    if (text_content != NULL)
    {
        for (len = 0; text_content[len]; len++)
            continue;
    }

    fd = open(filename, O_WRONLY | O_APPEND);
    if (fd == -1)
    {
        perror("Error opening file");
        return (-1);
    }

    if (len > 0)
    {
        ssize_t bytes_written = write(fd, text_content, len);
        if (bytes_written == -1)
        {
            perror("Error writing to file");
            close(fd);
            return (-1);
        }
    }

    close(fd);
    return (1);
}
