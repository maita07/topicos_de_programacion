#include <stdio.h>
#include <stdbool.h>

#define DATO long

bool insertarElemento(DATO* vector, DATO elemento, int cant_element, int pos);
bool eliminarElemento(DATO* vector, int cant_element, int pos);

int eliminarAllElemento(DATO* vector, DATO elemento, int cant_element);
void eliminarPrimerElemento(DATO* vector, DATO* vector_final);
DATO* encontrarElemento(DATO elemento, DATO *vector, DATO *vector_final);

int main()
{
    DATO vector[10] = {1,1,143,1,1,1};
    int cant_element = 6;
    int pos = 2;
    DATO elemento = 2.5;

    printf("%d",eliminarAllElemento(vector,1,cant_element));
}

bool insertarElemento(DATO* vector, DATO elemento, int cant_element, int pos)
{
    if(pos < 0 || pos > cant_element)
        return false;

    DATO* final_vector = vector + cant_element;
    vector += pos;

    while((final_vector--) >= vector)
        *(final_vector+1) = *final_vector;
    
    *vector = elemento;

    return true;
}

bool eliminarElemento(DATO* vector, int cant_element, int pos)
{
    if(pos < 0 || pos > cant_element)
        return false;
    
    DATO* final_vector = vector + cant_element-1;
    vector += pos;

    while(vector < final_vector)
    {
        *vector = *(vector+1);
        vector++;
    }

    return true;
}

int eliminarAllElemento(DATO* vector, DATO elemento, int cant_element)
{
    int cant_eliminados = 0;
    
    DATO* vector_final = vector + cant_element - 1;
    while(vector < vector_final)
    {
        if(vector = encontrarElemento(elemento, vector, vector_final))
        {
            eliminarPrimerElemento(vector, vector_final);
            cant_eliminados++;
            vector_final--;
        }
    }

    return cant_eliminados;
}

void eliminarPrimerElemento(DATO* vector, DATO* vector_final)
{
    while(vector < vector_final)
    {
        *vector = *(vector+1);
        vector++;
    }
}

DATO* encontrarElemento(DATO elemento, DATO *vector, DATO *vector_final)
{
    while(*vector != elemento && vector != vector_final)
        vector++;

    if(vector == vector_final)
        return NULL;

    return vector;
}