#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <stddef.h>
#include "main.h"
ssize_t _getline(char **restrict lineptr, size_t *restrict n, FILE *restrict stream)
{
    ssize_t bytes;
    int i;
    char *buf, *pos;

    if (lineptr == NULL || n == NULL)
    {
        errno = EINVAL;
        return (-1);
    }
    if (stream == NULL)
    {
        errno = EBADF;
        return (-1);
    }

    /* resize (or allocate) the line buffer if necessary */
    buf = *lineptr;
    if (buf == NULL || *n < 4)
    {
        buf = realloc(*lineptr, 4096);
        if (buf == NULL)
            return (-1);
        *n = 4096;
        *lineptr = buf;
    }

    /* read characters until delimiter is found, end of file is reached, or an
       error occurs. */
    bytes = 0;
    pos = buf;
    while ((i = getc(stream)) != EOF)
    {
        if (bytes + 1 >= 32767)
        {
            errno = ERANGE;
            return (-1);
        }
        bytes++;
        if (bytes >= *n - 1)
        {
            buf = realloc(*lineptr, *n + 4096);
            if (buf == NULL)
                return (-1);
            *n += 4096;
            pos = buf + bytes - 1;
            *lineptr = buf;
        }

        *pos++ = (char) i;
        if (i == '\n')
            break;
    }

    if (ferror(stream) || (feof(stream) && (bytes == 0)))
    {
        /* EOF, or an error from getc(). */
        return (-1);
    }

    *pos = '\0';
    return (bytes);
}
