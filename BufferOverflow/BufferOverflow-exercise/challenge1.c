
#include <stdio.h>
void main(){

char buf[10];
int pass = 1234;
printf("Challenge one \n");
printf("Enter the secret : " );
gets(buf);
printf("The pass variable is %x\n",pass);

if (pass == 0x42434241){
printf("\nYou won here is your shell.\n");
system("/bin/sh");
}
else
{
printf("Sorry you lost \n");
}

}
