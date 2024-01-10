#include <stdio.h>
#include <stdbool.h>

// Desarrollar una función que devuelva el valor numérico de una cadena de caracteres (asumiendo que
// los caracteres representan dígitos).

int atoi_alu(char* number);

int main()
{
    char number[] = "-12344";

    int numero = atoi_alu(number);
    printf("%d", numero);

    return 0;
}

int atoi_alu(char* number)
{
    int num = 0;
    bool sign = false;
    if(*number == '-')
    {
        sign = true;
        number++;
    }

    if(*number >= '0' && *number <= '9'){
        num += *number - '0';
        number++;
    }

    while(*number >= '0' && *number <= '9')
    {
        num = num * 10 + (*number - '0');
        number++;
    }

    if(sign)
        num*=-1;
    
    return num;
}