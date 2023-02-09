#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char* argv[]){
    int pid=fork(); //Se crea un proceso y se ejecutan tanto padre como hijo
    int x=5;
    if(pid==-1){
        return -1;
    }
    if(pid==0){
        x++;
    }
    sleep(1);
    printf("Esta línea sale 2 veces\n");
    printf("x vale %i\n", x);
    printf("%i\n", pid);
    if(pid!=0){
        wait(NULL);
    }
    return 0;
}