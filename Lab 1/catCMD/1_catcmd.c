#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdio.h>

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        int i = 1;
        while (i != argc)
        {
            int fd = open(argv[i], O_RDONLY);
            if (-1 == fd)
            {
                write(1, "Error", 5);
            }
            else
            {
                char buf[2048];
                int bytes_read = read(fd, buf, sizeof(buf));
                int n = write(1, buf, bytes_read);
                printf("\n\n");
            }
            close(fd);
            i++;
        }
    }
    else
    {
        /*
        If no arguments were passed then work like echo cmd
        */
        char buf[2048];
        int n = read(0, buf, 2048);
        int byte_read = write(1, buf, n);
    }
    return 0;
}