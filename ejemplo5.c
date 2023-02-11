//Un mútex sirve para proteger una sección crítica para que no
//entre más de un thread en ella a la vez. Por ejemplo, este 
//código no tiene mútex y veremos que sucede.

#include <stdio.h>
#include <threads.h>

int run (void* args){
    static int shared=0;
    printf("Shared vale %i\n", shared);
    shared++;
    return 0;
}

int main(){
    thrd_t t[10];
    for (int i = 0; i < 10; i++) {
        thrd_create(t + i, run, NULL);
    }

    for (int i = 0; i < 10; i++) {
        thrd_join(t[i], NULL);
    }
    return 0;
}

//Los procesos se solapan