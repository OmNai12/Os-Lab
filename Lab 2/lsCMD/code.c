#include <dirent.h>
#include <sys/types.h>
#include<stdio.h>
int main()
{
    DIR *d;
    struct dirent *de;
    d = opendir(".");
    while (de = readdir(d))
    {
        printf("%s\t", de->d_name);
    }
    printf("\n");
    return 0;
}
