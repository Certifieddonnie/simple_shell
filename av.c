#include <stdio.h>
#include <unistd.h>

int main(int ac, char **av)
{
	int i;
	pid_t my_pid;

	i = 1;
	while (av[i] != '\0')
	{
		printf("av[%d] : %s\n", i, av[i]);
		i++;
	}
	return (0);
}
