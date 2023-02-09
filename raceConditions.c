#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int mails=0;

void* routine(){
    for(int i=0;i<1000000;i++){ 
        mails++;
        //Se lee la variable mails
        //Se incrementa
        //Se escribe en memoria el nuevo valor
    }
}

int main(int argc, char* argv[]){
    pthread_t t1, t2;
    if(pthread_create(&t1, NULL, &routine, NULL)!=0){ //Creamos un thread
        return 1;
    }
    if(pthread_create(&t2, NULL, &routine, NULL)!=0){ //Creamos otro thread
        return 2;
    }
    if(pthread_join(t1, NULL)!=0){ //Ejecutar el thread 1
        return 3;
    }
    if(pthread_join(t2, NULL)!=0){ //Ejecutar el thread 2
        return 4;
    }
    printf("Numero de mails=%i\n", mails);
    //NO SALE EL NÚMERO ESPERADO DE MAILS, ERA 2000000
    //Esto se llama race conditions
    return 0;
}