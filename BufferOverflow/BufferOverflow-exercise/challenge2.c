#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 


void vulnerable(char* ip) {
    char buf[20];
    strcpy(buf, ip);

}
 void win(){
printf("You successfully exploited the buffer overflow\n");
system("/bin/sh");
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Argument <input>\n");
        exit(1);
    }
    vulnerable(argv[1]);
    
}

