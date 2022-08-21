#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main()
{
    pid_t childProc;
    childProc = fork();
    if (childProc < 0)
    {
        printf("Error");
    }
    else if (0 == childProc)
    {
        printf("Hello !!! from child process\n");
        printf("Child process ID : %d", getpid());
    }
    else
    {
        wait(NULL);
        printf("Hello !!! from parent process\n");
        printf("Parent process ID : %d", getpid());
    }
}