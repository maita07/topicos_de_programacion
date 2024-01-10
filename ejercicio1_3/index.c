#include <stdio.h>

// Desarrollar una función que elimine el elemento que ocupa una determinada posición de un arreglo
// de enteros.

int deleteElement(int *array, int position, int *cant_elements);


int main()
{
    int array[10] = {1,2,3,4,5,6,7};
    int cant_elements = 7;
    int position = 5;

    int error;
    if((error = deleteElement(array, position, &cant_elements)) != 0){
        printf("%d", error);
        return error;
    }

    return error;
}

int deleteElement(int *array, int position, int *cant_elements)
{
    if(position < 0 || position > *cant_elements - 1)
        return -1;
    
    if(*cant_elements <= 0)
        return -2;
    
    int* final_array = array + *cant_elements - 1;
    array += position-1;

    while(array++ < final_array)
        *array = *(array+1);

    *(cant_elements)--;

    return 0;
}