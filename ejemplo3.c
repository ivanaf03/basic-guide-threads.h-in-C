#include <stdio.h>
#include <stdlib.h>
#include <threads.h>

int run(void* args){ //Función a ejecutar
    int a=*(int*)args;
    free(args);
    printf("El hilo está ejecutandose con el argumento %i\n", a);
    a++;
    return a;
}

int main(){

    thrd_t t[100]; //ID del thread
    int result[100]; //Recogedor del argumento de la función

    for(int i=0;i<100;i++){
        int *arg= malloc(sizeof *arg);
        *arg=i;
        thrd_create(t+i, run, arg);
    }

    for(int i=0;i<100;i++){
        thrd_join(t[i], &result[i]);
        printf("El resultado es %i\n", result[i]);
    }


    return 0;
}