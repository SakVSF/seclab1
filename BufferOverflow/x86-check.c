#include<stdio.h>
void vul(char *str) {
    char buf[16];
    strcpy(buf, str);
}
int main() {
  char large[128];
    //getchar();
    FILE *fp = fopen("in.txt", "r");
    fgets(large, 128, fp);
    fclose(fp);
    vul(large);
    return 0;
    //vul("hhhhhhhhhh");
   
}
