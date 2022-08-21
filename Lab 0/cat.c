#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// Use of simple cat command

int main()
{
    // fd returns value of open sys call...
    int fd = open("hello.txt", 0);
    if(fd == -1){
        write(1, "File does not exist", 20);
    }
    else{
        // This serves as a buffer for the read file...
        char str[1000];
        int count = read(fd, str, sizeof(str));
        write(1, str, count);
    }

    /*
    1 -> write on console.
    str -> it is the buffer.
    sizeof(str) -> write till str ends.
    */

    return 0;
}