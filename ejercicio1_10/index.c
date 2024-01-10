#include <stdio.h>
#include <string.h>

#define isAlpha(x) (((x >= 'a') && (x <= 'z')) || ((x >= 'A') && (x <= 'Z')))

char* descifradoPorPosicion(char* texto,char* clave);
char* descifrarPalabraPorPosicion(char* texto, char* clave);
char buscarCaracterDescifradoPorPosicion(char caracter, int pos, char* clave, int long_clave);

int main()
{
    char texto[] = "Nj qemh v ljs kraenkqbres; lj oqe qemh es oqevorme sgn ellhs --Istqt Asdmgj";
    char clave[] = "abcdghijkoqtuv";
    //gjlt
    printf("%s\n", descifradoPorPosicion(texto, clave));
    return 0;
}

char* descifradoPorPosicion(char* texto,char* clave)
{
    char* texto_descifrado = texto;
    while(*texto)
    {
        while(!isAlpha(*texto) && *texto)
            texto++;
        
        texto = descifrarPalabraPorPosicion(texto, clave);
    }
    return texto_descifrado;
}

char* descifrarPalabraPorPosicion(char* texto, char* clave)
{
    int long_clave = strlen(clave) - 1;
    int pos = 1;
    while(isAlpha(*texto))
    {
        *texto = buscarCaracterDescifradoPorPosicion(*texto, pos, clave, long_clave);
        texto++;
        pos++;
    }
    return texto;
}

char buscarCaracterDescifradoPorPosicion(char caracter, int pos, char* clave, int long_clave)
{
    int pos_clave;

    for(pos_clave = 0; (clave[pos_clave] != caracter) && clave[pos_clave]; pos_clave++);

    if(clave[pos_clave] == '\0')
        return caracter;

    pos_clave += pos;
    if(pos_clave > long_clave)
        pos_clave -= long_clave + 1;

    return clave[pos_clave];
}