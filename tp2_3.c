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
            // Aritmetica de punteros
            *(apuntador + (i * M + j)) = 1 + rand() % 100;

            // Equivale a mt[i][j] = 1 + rand() % 100;
        }
    }

    // mostrar la matriz con aritmetica de punteros
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            printf("%d ", *(apuntador + (i * M + j)));
        }
        printf("\n");
    }

    // porque (i * M + j) ? porque en memoria la matriz see guarda como un vector largo. Cada fila tiene m elementos entonces avanzar i filas => i * M y despues las j columnas >+j
    // la diferencia entre artimetica de punteros y notacion indexada es :
    // . notacion indexada es mas intuitiva mt[i][j]
    // . aritmetica de punteros es mas bajo nivel, se hace la cuenta manualmente
    // *(apuntador + (i * M + j)). Los dos hacen lo mismo pero la seungda obliga a entender como esta guardada la matriz en memoria

    return 0;
}