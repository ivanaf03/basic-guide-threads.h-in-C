#include <stdio.h>
#include <threads.h>

int run(void* args){ //Función a ejecutar
int* a=args;
    printf("El hilo está ejecutandose con el argumento %i\n", *a);
    (*a)++;
    return (*a);
}

int main(){

    thrd_t t; //ID del thread
    int i=1; //Variable del thread
    int result; //Recogedor del argumento de la función

    thrd_create(&t, run, &i);
    thrd_join(t, &result);

    printf("El resultado es %i\n", result);

    return 0;
}