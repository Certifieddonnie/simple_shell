#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

int main(void)
{
	size_t n;
	char *user_input = NULL; /*char pointer holding user input*/
	char *usr_in = NULL;	 /*copy of user input*/
	ssize_t num_chars;		 /*return val for getline-func*/
	char *token;			 /*return val for strtok-func*/
	int num_token = 1;		 /*number of tokens set as 1 for NULL byte*/
	int i = 0;
	char *delim = " \n"; /*space or a new-line as delimiter*/
	char **av;

	printf("$ ");
	/*to read from standdard input we pass stdin as FILE stream argument*/
	num_chars = getline(&user_input, &n, stdin);
	/*copy the string passed in by user for safe keeping*/
	// strcpy(usr_in, user_input);
	/*num_chars would be -1 if getline fails*/
	if (num_chars != -1)
	{
		// printf("%s\n", user_input);
		token = strtok(user_input, delim);
	}
	while (token != NULL)
	{
		printf("%s\n", token);
		num_token++;
		token = strtok(NULL, delim);
	}
	printf("Number of arguments: %d\n", num_token);
	/*allocating memory space for the argument array ptrs*/
	av = malloc(num_token * sizeof(char *));
	/*add each argument parsed into the array av*/
	token = strtok(usr_in, delim);
	while (token != NULL)
	{
		/*allocating memory space for the each argument*/
		av[i] = malloc(sizeof(char) * strlen(token));
		strcpy(av[i], token);
		i++;
		token = strtok(NULL, delim);
		printf("args[%d];%s\n", i, *av);
	}

	av[i] = NULL;
	return (0);
}
