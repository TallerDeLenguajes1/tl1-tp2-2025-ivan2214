#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20

int main()
{
    srand(time(NULL));
    double vt[N];
    double *ptr = vt; // Puntero que apunta al inicio del arreglo

    for (int i = 0; i < N; i++)
    {
        ptr[i] = 1 + rand() % 100; // Notación indexada
    }

    for (int i = 0; i < N; i++)
    {
        printf("%f \n", ptr[i]); // Notación indexada
    }

    return 0;
}
