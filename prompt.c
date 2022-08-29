#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main(void)
{
	size_t n;
	char *user_input = NULL;
	ssize_t num_chars;

	printf("$ ");
	/*to read from standdard input we pass stdin as FILE stream argument*/
	num_chars = getline(&user_input, &n, stdin);
	/*num_chars would be -1 if getline fails*/
	if (num_chars != -1)
	{
		printf("%s\n", user_input);
		/*printf("Number of bytes: %d\n", num_chars);*/
	}
	return (0);
}
