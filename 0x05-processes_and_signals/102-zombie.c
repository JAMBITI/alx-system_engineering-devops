#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * main - creates 5 zombie processes.
 * Return: 0
 */
int main(void)
{
    pid_t pid;
    int i;

    for (i = 0; i < 5; i++)
    {
        pid = fork();
        if (pid == 0)
        {
            printf("Zombie process created, PID: %d\n", getpid());
            exit(0);
        }
    }

    // Parent process
    for (i = 0; i < 5; i++)
    {
        wait(NULL); // Wait for child processes to exit
    }

    return (0);
}
