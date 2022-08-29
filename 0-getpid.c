#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(void)
{
    pid_t my_pid ,my_ppid;

    my_pid = getpid();
    my_ppid = getppid();
    printf("Process ID: %u\n", my_pid);
    printf("Parent PID: %u\n", my_ppid);
    return (0);
}

