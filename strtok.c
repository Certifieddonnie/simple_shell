#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char *_strtok(char *string, const char *delim)
{
    static char *arr = NULL;
    int i = 0, token = 0, len;

    if (delim == NULL)
        return (NULL);
    if ((string == NULL) && (arr == NULL))
        return (NULL);
    if (string == NULL)
        string = arr;
    len = strlen(string) + 1;

    for (i = 0; i < len; i++)
    {
        if (string[i] == delim[0])
        {
            token = 1;
            break;
        }
    }
    if (token != 1)
    {
        arr = NULL;
        return (string);
    }
    string[i] = '\0';
    if ((string + i + 1) != NULL)
        arr = string + i + 1;
    else
        arr = NULL;
    return (string);
}

int main()
{
    char string[50] = "Hello_bae ! We-are learning about strtok";
    // Extract the first token
    char *token = _strtok(string, " ");
    // loop through the string to extract all other tokens
    while (token != NULL)
    {
        printf(" %s\n", token); // printing each token
        token = _strtok(NULL, " ");
    }
    return 0;
}

// revamp this function _strtok() to work like strtok()