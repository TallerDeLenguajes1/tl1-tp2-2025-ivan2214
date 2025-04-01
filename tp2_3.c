#include <stdio.h>
#include <stdlib.h>
#define N 5
#define M 7

int main(int argc, char const *argv[])
{
    int i, j;
    int mt[N][M];
    int *apuntador = &mt[0][0]; // Puntero al primer elemento de la matriz

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            *(apuntador + (i * M + j)) = 1 + rand() % 100; // Aritmetica de punteros
            // mt[i][j] = 1 + rand() % 100; // Notacion indexada
            printf("%d ", mt[i][j]);
        }
        printf("\n");
    }

    return 0;
}