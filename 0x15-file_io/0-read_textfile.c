#include "main.h"
#include <stdlib.h>
/**
 * read_textfile-Read text file print to stdout.
 * @letters:number of letters to be read
 * @filename:text file being read
 * return:w-actual number of bytes read and printed
 * 0 when function fails or filename is NULL.
 * /
 ssize_t read_textfile(const char *sie_t letters, filename
{
     char *buf;
     ssize_t fd;
     ssize_t w;
     ssize_t t;

     fd=open(filename,0_RDONLY);
     if (fd==-1)
           return(0);
     buf=malloc(sizeof(char)*letters);
     t=read(fd,buf,letters);
     w=write(STDOUT_FILENO, buf,t);

     free(buf);
     close(fd);
     return(w);
     }
