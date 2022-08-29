#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

int main(void)
{
	size_t n;
	char *user_input = NULL; /*char pointer holding user input*/
	ssize_t num_chars;		 /*return val for getline-func*/
	char *token;			 /*return val for strtok-func*/
	int num_token = 0;		 /*number of tokens*/
	char *delim = " \n";	 /*space or a new-line as delimiter*/

	printf("$ ");
	/*to read from standdard input we pass stdin as FILE stream argument*/
	num_chars = getline(&user_input, &n, stdin);
	/*num_chars would be -1 if getline fails*/
	if (num_chars != -1)
	{
		printf("%s\n", user_input);
		token = strtok(user_input, delim);
		while (token != NULL)
		{
			printf("%s\n", token);
			num_token++;
			token = strtok(NULL, delim);
		}
		/*printf("Number of bytes: %d\n", num_chars);*/
	}
	return (0);
}
