#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <errno.h>

void _ls_R(DIR *d)
{
    struct dirent *d_reader;
    while (d_reader = readdir(d))
    {
        if (d_reader->d_name[0] == '.')
        {
            continue;
        }
        printf("%s   ", d_reader->d_name);
    }
}

void _ls()
{
    struct dirent *d;
    DIR *dir = opendir(".");
    if (!dir)
    {
        perror("Not able to read directory");
        // exit(0);
    }
    while ((d = readdir(dir)) != NULL)
    {
        if (d->d_name[0] == '.')
        {
            continue;
        }
        printf("%s\n", d->d_name);
        DIR *d_ano = opendir(d->d_name);
        if (d_ano != NULL)
        {
            _ls_R(d_ano);
            closedir(d_ano);
            printf("\n");
        }
    }
}

int main()
{
    _ls();
    return 0;
}
