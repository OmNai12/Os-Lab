#include <unistd.h>
#include <stdio.h>
#include <string.h>
int main()
{
    char buf[1000];
    printf("%s\n", getcwd(buf, sizeof(buf)));
    return 0;
}
