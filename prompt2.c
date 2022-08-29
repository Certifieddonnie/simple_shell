#include <stdio.h>
#include <stdlib.h>

int main()

{
	size_t bytes_read;
	size_t size = 0;
	char *string;

	printf("$ ");
	/* These 2 lines are very important. */
	string = (char *)malloc(size);
	bytes_read = getdelim(&string, &size, '\n', stdin);

	if (bytes_read == -1)
	{
		puts("Keyboard Interrupt!");
	}
	else
	{
		puts(string);
	}

	return (bytes_read);
}
