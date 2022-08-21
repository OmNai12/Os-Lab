#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// cat cmd advanced version where file is given at run time...

int main(int argc, char *argv[])
{
    // fd returns value of open sys call...
    int fd = open(argv[1], 0);
    if (fd == -1)
    {
        write(1, "File does not exist", 20);
    }
    else
    {
        // This serves as a buffer for the read file...
        char str[1000];
        int count = read(fd, str, sizeof(str));
        write(1, str, count);
    }

    return 0;
}