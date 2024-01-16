#include <stdio.h>
#include <stdlib.h>

// Ejercicio 2.4
// Implemente utilizando memoria dinámica las siguientes funciones:
// ○Una función que retorna una copia de la cadena pasada como parámetro con exactamente la
// misma cantidad de caracteres de la cadena origen. Ej:
// ○Una función que genere una copia de un elemento pasado como parámetro, este puede ser
// un tipo primitivo (int,float,char) una estructura o incluso un vector. Ej:
// Estas funciones tienen un objetivo estrictamente didáctico, y como puede observar persiguen
// objetivos similares a las funciones de biblioteca de C pero su implementación es totalmente
// diferente. ¿Por qué no se recomienda este tipo de implementación en sistemas productivos?

char* copiaCadena(const char* origen);
void* copiaCosas(void* elemento, unsigned tam);

int main()
{
    float vec[3] = {1,2,3};
    int tam = sizeof(vec);
    float* vector_copia = (float*)copiaCosas(vec, tam);
    for(int i = 0; i < 3; i++)
    {
        printf("%.2f\n", *vector_copia);
        vector_copia++;
    }
}

char* copiaCadena(const char* origen)
{
    int contador = 1;

    char* cursor = (char*)origen;
    while(*cursor)
    {
        contador++;
        cursor++;
    }

    char* copia = malloc(contador);
    if(!copia)
        return NULL;

    cursor = copia;
    while(*origen)
    {
        *cursor = *origen;
        origen++;
        *cursor++;
    }

    return copia;
}

void* copiaCosas(void* elemento, unsigned tam)
{
    char* copia = (char*)malloc(tam);
    char* cursor = (char*)copia;
    while(tam > 0)
    {
        *cursor = *((char*)elemento);
        cursor++;
        elemento++;
        tam--;
    }
    return copia;
}










