//Se puede lanzar un hilo sin necesidad de hacer un join. Eso sí, perdiendo
//el retorno. Se hace con thrd_detach.

#include <stdio.h>
#include <threads.h>

int run(void* args){ //Función a ejecutar
    printf("El hilo está ejecutandose\n");
    return 0;
}

int main(){

    thrd_t t; //ID del thread
    int result; //Recogedor del argumento de la función

    for(int i=0;i<10;i++){
        thrd_create(&t, run, NULL);
        thrd_detach(t);
    }

    thrd_sleep(&(struct timespec){.tv_sec=1}, NULL); //Dormir 1 segundo para que los thread acaben

    return 0;
}