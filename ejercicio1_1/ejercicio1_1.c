#include <stdio.h>

#define CANT_MAX 10

// Desarrollar una función que inserte un elemento en un arreglo de enteros, dada la posición de
// inserción.

int insertarElemento(int* array, int elemento, int cant_element, int cant_max, int posicion);


int main()
{
    int array[CANT_MAX] = {1,2,3,4,5,6,7,8,9};
    int cant_element = 9;
    int posicion = 9;
    int error;

    if((error = insertarElemento(array, 6, cant_element, CANT_MAX, posicion)) < 0)
    {
        printf("error: %d\n", error);
        return error;
    }

    return 0;
}

int insertarElemento(int* array, int elemento, int cant_element, int cant_max, int posicion)
{
    if(cant_element >= cant_max)
        return -1;

    if(posicion < 0 || posicion > cant_element)
        return -2;
    
    int *array_final = array + cant_element; /* busco el final del array */
    array += posicion; /* coloco el array en la posicion de inserción */
    

    while((array_final--) >= array)
    {
        *(array_final+1) = *array_final;
    }

    *array = elemento;

    return 0;
}