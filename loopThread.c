#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int mails=0;
pthread_mutex_t mutex;

void* routine(){
    for(int i=0;i<1000000;i++){ 
        pthread_mutex_lock(&mutex);
        mails++;
        pthread_mutex_unlock(&mutex);
    }
}

int main(int argc, char* argv[]){
    //No sería correcto meterlo todo en el mismo loop for
    pthread_t t1[4];
    pthread_mutex_init(&mutex, NULL);
    for(int i=0; i<4;i++){
        if(pthread_create(&t1[i], NULL, &routine, NULL)!=0){
            perror("Fail");
            return -1;
        }
        printf("Aquí empieza el thread %i\n", i+1);
    }
    for(int i=0; i<4;i++){
            if(pthread_join(t1[i], NULL)!=0){
            perror("Fail");
            return -1;
        }
    }
    pthread_mutex_destroy(&mutex); 
    printf("Numero de mails=%i\n", mails);
    return 0;
}