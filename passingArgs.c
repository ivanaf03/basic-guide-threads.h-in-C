//Problem: crear 10 threads, que cada uno elija uno del array y lo muestre por pantalla

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int primes[10]={2,3,5,7,11,13,17,19,23,29};

void* function(void* arg){
    printf("%i ", (*(int*)arg));
}

int main(int args, char* argv[]){
    pthread_t th[10];
    for(int i=0;i<10;i++){
        if(pthread_create(&th[i], NULL, &function, &primes[i])!=0){
            perror("Fail");
            return -1;
        }
    }
    for(int i=0; i<10;i++){
        if(pthread_join(th[i], NULL)!=0){
            perror("Fail");
            return -1;
        }
    }
    return 0;
} 
//No siempre los muestra ordenados, pero hace lo que tiene que hacer.
//Se puede arreglar fácilmente.
