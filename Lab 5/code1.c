#include <stdio.h>
#include <pthread.h>

void *func1()
{
    printf("Hello from thread 1\n");
}

void *func2()
{
    printf("Hello from thread 2\n");
}

int main()
{
    // By threads it will be printing...
    // link with gcc firstthread.c -pthread
    pthread_t t1;
    pthread_t t2;
    pthread_create(&t1, NULL, func1, NULL);
    pthread_join(t1, NULL);
    pthread_create(&t2, NULL, func2, NULL);
    pthread_join(t2, NULL);
    return 0;
}
