#include <stdio.h>
#include <pthread.h>

void *func1(void *str_rec)
{
    printf("%s", (char *)str_rec);
}

int main()
{
    char *str = "Hello\n";
    pthread_t t1;
    pthread_create(&t1, NULL, func1, (void *)str);
    pthread_join(t1, NULL);
    // 4th argument is the type of function we passed
    return 0;
}
