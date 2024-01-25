#include<stdio.h>
void vul(char *str) {
    char buf[16];
    strcpy(buf, str);
}
int main() {
  char large[10]= "hhhhhhhhh";
    
    vul(large);
   
}
