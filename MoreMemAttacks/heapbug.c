#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n = 5;

//__asm__(".symver realpath,realpath@GLIBC_2.2.4");
int main(int argc, char **argv) {
        char *p, *q;

        p = malloc(1024);
        q = malloc(1024);
        if (argc >= 2)
                strcpy(p, argv[1]);
        free(q);
        printf("n = 0x%08x\n", n);
        free(p);
        return 0;
}