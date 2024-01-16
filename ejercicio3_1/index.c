#include <stdio.h>
#include <time.h>

int menu();
int arrayAleatorio(float* vector, size_t cant_max_element);

int main(void)
{
    float vec[14];
    int cant_element = arrayAleatorio(vec, 14); //generamos un vector aleatorio.

    //mostramos el vector
    for(int i = 0; i < cant_element; i++)
    {
        printf("%f ", vec[i]);
    }
    printf("\n\n");

    menu(); //mostramos el menu.

}

int menu()
{
    printf("Elija una opcion:\n");
    printf("Minimo elemento -> 1");
    printf("loclo");
    printf();
}