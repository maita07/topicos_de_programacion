#include <stdio.h>

// Desarrollar una función que inserte un elemento en un arreglo de enteros, ordenado en forma
// ascendente, de forma de no alterar el orden.

int insertarOrdenado(int *array, int element, int cant_elements, int cant_max_elements);
int* positionOrder(int *array, int element, int* final_array);

int main()
{
    int array[10] = {1,2,3,5,6,7};
    int cant_elements = 6;
    int element = 9;
    int error;

    if((error = insertarOrdenado(array, element, cant_elements, 10)) != 0)
    {
        printf("error: %d", error);
        return error;
    }

    return 0;
}

int* positionOrder(int *array, int element, int* final_array)
{
    while(*array < element && array < final_array)
        array++;
    
    return array;
}

int insertarOrdenado(int *array, int element, int cant_elements, int cant_max_elements)
{
    if(cant_elements >= cant_max_elements)
        return -1;

    int *final_array = array + cant_elements; /*Busco la posicion del final del array*/
    array = positionOrder(array, element, final_array); /*Busco la posicion de insercion para que se mantenga ordenado*/

    while((final_array--) >= array)
        *(final_array+1) = *final_array;

    *array = element;

    return 0;
}