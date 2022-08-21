#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    // cp source destination
    // By defult implementation so it clears the content of the destination file
    if (argc == 3)
    {
        int fd_READ_IN_FILE = open(argv[1], O_RDONLY);
        if (fd_READ_IN_FILE == -1)
        {
            char errorNoSourceFile[] = "Source file not exist";
            write(1, errorNoSourceFile, sizeof(errorNoSourceFile));
        }
        else
        {
            char buf[2048];
            int bytes_read = read(fd_READ_IN_FILE, buf, sizeof(buf));
            int fd_WRITE_IN_FILE = open(argv[2], O_WRONLY);
            if (fd_WRITE_IN_FILE == -1)
            {
                fd_WRITE_IN_FILE = open(argv[2], O_CREAT | O_WRONLY, 0642);
                if (fd_WRITE_IN_FILE == -1)
                {
                    char errorInCreatingFile[] = "Error in creating a file";
                    write(1, errorInCreatingFile, sizeof(errorInCreatingFile));
                }
                else
                {
                    write(fd_WRITE_IN_FILE, buf, bytes_read);
                }
            }
            else
            {
                write(fd_WRITE_IN_FILE, buf, bytes_read);
            }
            close(fd_READ_IN_FILE);
            close(fd_WRITE_IN_FILE);
        }
    }
    else
    {
        char error[] = "Not sufficient arguments provided";
        write(1, error, sizeof(error));
    }
    return 0;
}