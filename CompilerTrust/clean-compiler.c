#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

int main(int argc, char *argv[]){

int c; 
FILE *fptr;
fptr = fopen(argv[1], "r");
//printf("%s",argv[1]);

if (fptr == NULL) 
    { 
        printf("Cannot open file \n"); 
        exit(0); 
    } 
  
    // Read contents from file 
    c = fgetc(fptr);
    
    while (c != EOF) 
    { 
        printf ("%c", c); 
        c = fgetc(fptr);
    } 
  
    fclose(fptr); /* printing the input file content to stdout*/
    
    
    int len= strlen(argv[1]);
    char buf[30];
    strcpy(buf,argv[1]);
    buf[len-2]='\0';//define outputfile by removing ".c", name of the executable file

    
    pid_t child = fork();
    if(child==0){
    	
    	char * args [ ] = { "/usr/bin/gcc" , argv[1], "-o",buf, NULL } ;
    	int retval = execv("/usr/bin/gcc",args);
    	
    }
    return 0; 
}
