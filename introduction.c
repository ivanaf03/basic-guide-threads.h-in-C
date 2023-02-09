#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void* testing(){
    printf("Testing threads\n");
    sleep(3);
    printf("End\n");
}

int main(int argc, char* argv[]){
    pthread_t t1, t2;
    if(pthread_create(&t1, NULL, &testing, NULL)!=0){ //Creamos un thread
        return 1;
    }
    if(pthread_create(&t2, NULL, &testing, NULL)!=0){ //Creamos otro thread
        return 2;
    }
    if(pthread_join(t1, NULL)!=0){ //Ejecutar el thread 1
        return 3;
    }
    if(pthread_join(t2, NULL)!=0){ //Ejecutar el thread 2
        return 4;
    }
    return 0;
}