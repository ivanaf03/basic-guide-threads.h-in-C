#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int x=2; //Variable global
//La prinicpal diferencia entre procesos y threads es que los threads comparten memoria

void* function(){
    x++; //x=3
    sleep(2);
    printf("x=%i\n",x);
    printf("Process id= %i\n", getpid()); //Tienen el mismo pid
}

void* function2(){
    sleep(2); 
    printf("x=%i\n",x); //x=3
    printf("Process id= %i\n", getpid()); //Tienen el mismo pid
}

int main(int argc, char* argv[]){
    pthread_t t1, t2;
    if(pthread_create(&t1, NULL, &function, NULL)!=0){
        return -1;
    }
    if(pthread_join(t1, NULL)!=0){
        return -1;
    }
    if(pthread_create(&t2, NULL, &function2, NULL)!=0){
        return -1;
    }
    if(pthread_join(t2, NULL)!=0){
        return -1;
    }
    return 0;
}