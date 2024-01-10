#include <stdio.h>

// Desarrollar una función que elimine todas las apariciones de un determinado elemento de un arreglo
// de enteros.

int deleteAllElementsFind(int *array, int element, int cant_element);
int *findElement(int* array, int* final_array, int element);
void deleteElement(int *array, int *final_array);

int main()
{
    int array[10] = {1,2,3,2,2,3,2,1,1,2};
    int cant_element = 10;
    int element = 2;

    int error;
    if((error = deleteAllElementsFind(array, element, cant_element)) < 0)
        printf("%d", error);
    
    return 0;
}

int deleteAllElementsFind(int *array, int element, int cant_element)
{
    if(cant_element <= 0)
        return -1;

    int cant_delete_elements = 0;   
    int* final_array = array + (cant_element-1);

    while(array = findElement(array, final_array, element))
    {
        deleteElement(array, final_array);
        cant_delete_elements++;
    }

    return cant_delete_elements;
}

int *findElement(int* array, int* final_array, int element)
{
    while(array <= final_array)
    {
        if(*array == element)
            return array;
        
        array++;
    }
    return NULL;
}

void deleteElement(int *array, int *final_array)
{
    while(array <= final_array)
    {
        *array = *(array+1);
        array++; 
    }
}