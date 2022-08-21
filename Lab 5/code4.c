#include <stdio.h>
#include <pthread.h>

int count = 0;
// THIS IS TO BE KEPT GLOBAL SO THREAD CONTROL CAN BE DONE ELSE NEW INSTANCE FOR EACH THREAD WILL BE CREATED
// IF DELARED IN THE FUNCTION
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

void *func1()
{
    // This is to be pointer
    pthread_mutex_lock(&mutex1);
    count++;
    printf("The value of count is : %d\n", count);
    pthread_mutex_unlock(&mutex1);
}

int main()
{
    int i;
    pthread_t threads[5];
    for (i = 0; i < 5; i++)
    {
        pthread_create(&threads[i], NULL, func1, NULL);
    }

    for (i = 0; i < 5; i++)
    {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
