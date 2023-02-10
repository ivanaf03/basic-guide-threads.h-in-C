#include <stdio.h>
#include <threads.h>

int run(void* args){ //Función a ejecutar
    int* a=args;
    printf("El hilo está ejecutandose con el argumento %i\n", *a);
    (*a)++;
    return (*a);
}

int main(){

    thrd_t t[10]; //ID del thread
    int result[10]; //Recogedor del argumento de la función

    for(int i=0;i<10;i++){
        thrd_create(&t[i], run, &i);
    }

    for(int i=0;i<10;i++){
        thrd_join(t[i], &result[i]);
    }

    for(int i=0;i<10;i++){
        printf("El resultado es %i\n", result[i]);
    }

    return 0;
}

//A simple vista parece que el código está bien simplemente haciendo bucles
//para crear varios hilos. Pero nada mas lejos de la realidad. Esto que está 
//pasando si ejecutamos el código es por las Race Conditions. El thread principal 
//modifica i antes de que los thread hagan las copias. De ahí que se den resultados
//inesperados. Para solucionar esto podemos tener una variable por thread o crearla
//con un malloc que se libere en cada thread.