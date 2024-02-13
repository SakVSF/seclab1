#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


void func(){
    char overflowme[32];
    printf("overflow me: ");
    fflush(stdout);
    read(STDIN_FILENO, overflowme, 200);
    printf("Now you face the wrath of my canary!\n");
    fflush(stdout);
}


int main(int argc, char* argv[]){
    while(1) {
        if (fork()== 0) {
            func();
            printf("Ok bye!\n");
            fflush(stdout);
            exit(0);
        } else {
            wait(NULL);
        }
    }
    return 0;
}