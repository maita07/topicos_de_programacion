#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef void(*Imprimir)(void**, int, int);

void printearEntero(void** matriz, int fila, int columna);
void** crearMatriz(int filas, int columnas, size_t tam_element, void**matriz);
void mostrarMatriz(int filas, int columnas, void**matriz, Imprimir imprimir);


int main()
{
    void**matriz = crearMatriz(5, 5, sizeof(int), matriz);
    int**matriz_de_enteros = (int**)matriz;

    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            matriz_de_enteros[i][j] = j + i;
    
    mostrarMatriz(5, 5, matriz, printearEntero);

}

void** crearMatriz(int filas, int columnas, size_t tam_element, void**matriz)
{
    int i, j;
    matriz = (void**)malloc(filas * sizeof(void*));
    if(!matriz)
        return NULL;

    for(i = 0; i < filas; i++)
    {
        matriz[i] = (void*)malloc(columnas * tam_element);
        if(!matriz[i])
        {
            for(j = 0; j < i; j++)
            {
                free(matriz[j]);
            }
            free(matriz);
            return NULL;
        }
    }
    return matriz;
}

void mostrarMatriz(int filas, int columnas, void**matriz, Imprimir imprimir)
{
    int i, j;
    for(i = 0; i < filas; i++)
    {
        for(j = 0; j < columnas; j++)
            imprimir(matriz, i, j);
        
        printf("\n");
    }
        
}

void printearEntero(void** matriz, int fila, int columna)
{
    printf("%d ", ((int **)matriz)[fila][columna]);
}