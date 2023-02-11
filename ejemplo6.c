//Arreglemos el código anterior con un mútex

#include <stdio.h>
#include <threads.h>

mtx_t mutex;

int run (void* args){
    static int shared=0;
    mtx_lock(&mutex);
    printf("Shared vale %i\n", shared);
    shared++;
    mtx_unlock(&mutex);
    return 0;
}

int main(){
    thrd_t t[10];
    mtx_init(&mutex, mtx_plain);

    for (int i = 0; i < 10; i++) {
        thrd_create(t + i, run, NULL);
    }

    for (int i = 0; i < 10; i++) {
        thrd_join(t[i], NULL);
    }

    mtx_destroy(&mutex);
    return 0;
}