#include <stdio.h>
#include <pthread.h>

struct Operands
{
    /* data */
    int a;
    int b;
};

void *addition(void *struct_rec)
{
    struct Operands *Operands1Pntr = struct_rec;
    printf("The sum is : %d\n", Operands1Pntr->a + Operands1Pntr->b);
}

void *substraction(void *struct_rec)
{
    struct Operands *Operands1Pntr = struct_rec;
    printf("The diffrience is : %d\n", Operands1Pntr->a - Operands1Pntr->b);
}
void *multiplication(void *struct_rec)
{
    struct Operands *Operands1Pntr = struct_rec;
    printf("The sum is : %d\n", Operands1Pntr->a * Operands1Pntr->b);
}
void *division(void *struct_rec)
{
    struct Operands *Operands1Pntr = struct_rec;
    printf("The sum is : %d\n", Operands1Pntr->a / Operands1Pntr->b);
}
int main()
{
    struct Operands Operands1;
    printf("Enter first operand : ");
    scanf("%d", &Operands1.a);
    printf("Enter secound operand : ");
    scanf("%d", &Operands1.b);
    struct Operands *Operands1Ptr = &Operands1;

    // Threads Declared

    pthread_t addThread;
    pthread_t subThread;
    pthread_t mulThread;
    pthread_t divThread;

    // Creation of threads...

    pthread_create(&addThread, NULL, addition, (void *)Operands1Ptr);
    pthread_create(&subThread, NULL, substraction, (void *)Operands1Ptr);
    pthread_create(&mulThread, NULL, multiplication, (void *)Operands1Ptr);
    pthread_create(&divThread, NULL, division, (void *)Operands1Ptr);

    // Joining of threads

    pthread_join(addThread, NULL);
    pthread_join(subThread, NULL);
    pthread_join(mulThread, NULL);
    pthread_join(divThread, NULL);
    return 0;
}
