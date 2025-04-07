
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CANTIDAD_PC 5

typedef struct
{
    int velocidad;      // velocidad de procesamiento en Ghz (Valoe entre 1 y 3)
    int anio;           // Anio de fabricacion (valor entre 2015 y 2024)
    int cantidadNucles; // cantidad de nucleos (valor entre 1 y 8)
    char *tipoCpu;      // tipo de procesador (apuntador a cadena de caracteres)
} Compu;

int aleatorio(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

void listarPCs(Compu pcs[], int cantidad)
{
    printf("Listado de PCs:\n");
    for (int i = 0; i < cantidad; i++)
    {
        printf("PC %d:\n", i + 1);
        printf("Velocidad: %d Ghz\n", pcs[i].velocidad);
        printf("Anio: %d\n", pcs[i].anio);
        printf("Cantidad de nucleos: %d\n", pcs[i].cantidadNucles);
        printf("Tipo de CPU: %s\n", pcs[i].tipoCpu);
        printf("\n");
    }
};

void mostrarMasVieja(Compu pcs[], int cantidad)
{

    Compu pcMasVieja = pcs[0];

    for (int i = 0; i < cantidad; i++)
    {
        Compu pcActual = pcs[i];

        if (pcActual.anio < pcMasVieja.anio)
        {
            pcMasVieja = pcActual;
        }
    }

    printf("Info de la PC mas vieja:\n");
    printf("Velocidad: %d Ghz\n", pcMasVieja.velocidad);
    printf("Anio: %d\n", pcMasVieja.anio);
    printf("Cantidad de nucleos: %d\n", pcMasVieja.cantidadNucles);
    printf("Tipo de CPU: %s\n", pcMasVieja.tipoCpu);
    printf("\n");
};

void mostrarMasVeloz(Compu pcs[], int cantidad)
{

    Compu pcMasVeloz = pcs[0];

    for (int i = 0; i < cantidad; i++)
    {
        Compu pcActual = pcs[i];

        if (pcActual.velocidad > pcMasVeloz.velocidad)
        {
            pcMasVeloz = pcActual;
        }
    }

    printf("Info de la PC mas veloz:\n");
    printf("Velocidad: %d Ghz\n", pcMasVeloz.velocidad);
    printf("Anio: %d\n", pcMasVeloz.anio);
    printf("Cantidad de nucleos: %d\n", pcMasVeloz.cantidadNucles);
    printf("Tipo de CPU: %s\n", pcMasVeloz.tipoCpu);
    printf("\n");
};

int main()
{

    Compu pcs[CANTIDAD_PC];
    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
    srand(time(NULL));

    // las caracteristicas de cada PC
    for (int i = 0; i < CANTIDAD_PC; i++)
    {
        pcs[i].velocidad = aleatorio(1, 3);
        pcs[i].anio = aleatorio(2015, 2024);
        pcs[i].cantidadNucles = aleatorio(1, 8);
        pcs[i].tipoCpu = tipos[rand() % 6]; /*el puntro tipoCpu recibe la direccion de memoria de una fila
        que a su vez en ella hay una arreglo, es decir el puntero recibe un arreglo de caracteres*/
    }

    listarPCs(pcs, CANTIDAD_PC);
    mostrarMasVieja(pcs, CANTIDAD_PC);
    mostrarMasVeloz(pcs, CANTIDAD_PC);

    return 0;
}
