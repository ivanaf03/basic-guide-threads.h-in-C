#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

void* tirar_dado(){
    int value=(rand()%6)+1;
    int* sol=malloc(sizeof(int));
    *sol=value;
    return (void*) sol;
}

int main(int argc, char* argv[]){
    int *sol;
    srand(time(NULL));
    pthread_t th;
    if(pthread_create(&th, NULL, &tirar_dado, NULL)!=0){
        return -1;
    }
    if(pthread_join(th, (void*) &sol)!=0){ //Se recoge la salida de la función
        return -1;
    }
    printf("El dado vale %i\n", *sol);
    free(sol); //Tiene la misma dirección de memoria, por eso se puede liberar aquí
    return 0;
}