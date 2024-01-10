#include <stdio.h>

// Desarrollar una función que elimine la primera aparición de un elemento determinado de un arreglo
// de enteros.

int deleteFirtsElementFind(int *array, int element, int cant_elements);
int *findElement(int *array, int *final_array, int element);

int main()
{
    int array[10] = {1,2,1,1,1,1,2,1,1};
    int cant_elements = 9;
    int element = 2;

    int error;
    if((error = deleteFirtsElementFind(array, element, cant_elements)) != 0)
        printf("%d", error);

    return 0;

}

int deleteFirtsElementFind(int *array, int element, int cant_elements)
{
    int *final_array = array + (cant_elements-1);

    if(!(array = findElement(array, final_array, element)))
        return -1;

    while(array <= final_array)
    {
        *array = *(array+1);
        array++;
    }

    return 0;
}

int *findElement(int *array, int *final_array, int element)
{
    while(array <= final_array)
    {
        if(*array == element)
            return array;

        array++;
    }

    return NULL;
}