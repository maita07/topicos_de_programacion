#include <stdio.h>
#include <ctype.h>

char* normalize(char* oracion);
void deleteCaracter(char* oracion);
char* normalizarPalabra(char *oracion);

int main()
{
    char oracion[] = "          aGUA  dE  cOCO        .       ";

    printf("%s\n", normalize(oracion));

    return 0;
}

char* normalize(char* oracion)
{
    char* oracion_normalizada = oracion;

    while(isblank(*oracion))
        deleteCaracter(oracion);

    while(*oracion)
    {
        if(isalpha(*oracion))
            oracion = normalizarPalabra(oracion);

        while(!isalpha(*oracion) && *oracion)
            deleteCaracter(oracion);
    }
    if(!isalpha(*(oracion-1)))
        *(oracion-1) = '\0';

    return oracion_normalizada;
}

char* normalizarPalabra(char *oracion)
{
    *oracion = toupper(*oracion);
    while(isalpha(*(oracion++)))
        *oracion = tolower(*oracion);

    return oracion;
}

void deleteCaracter(char* oracion)
{
    while(*oracion)
    {
        *oracion = *(oracion+1);
        oracion++;
    }
}